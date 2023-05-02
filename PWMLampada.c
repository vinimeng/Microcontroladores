/*
 * File:   main.c
 * Author: Vinicius Meng - 0250583
 *
 * Created on 2 de Maio de 2023, 08:50
 */

#include "config_628A.h"
#include "atraso.h"
#include "display7s.h"
#include "eeprom.h"

#define _XTAL_FREQ 4000000UL //deve ser o valor do clock do PICSIMLAB

void __interrupt() IRS(void) // Vetor de interrupção 
{
    RA0 = RB3;
    INTCONbits.T0IF = 0;
}

void main(void) {
    TRISA = 0b00000110;
    TRISB = 0b00000000;
    T2CON = 0b00000101;
    CMCON = 0b00000111;
    CCP1CON = 0b00111111;
    PR2 = 255;
    CCPR1L = 100;
    
    GIE = 0x01; //Habilita a interrupção global
    T0IE = 0x01; //Habilita a interrupção por estouro do TMR0
    
    while (1) {
        if (RA1 == 1 && CCPR1L < 250) {
            CCPR1L += 10;
            __delay_ms(100);
        }
        if (RA2 == 1 && CCPR1L > 0) {
            CCPR1L -= 10;
            __delay_ms(100);
        }
    }
}
