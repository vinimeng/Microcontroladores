/*
 * File:   main.c
 * Author: Vinícius Meng - 0250583
 *
 * Created on 18 de Abril de 2023, 20:53
 */

#include "config_628A.h"
#include "atraso.h"
#include "display7s.h"
#include "eeprom.h"

void main() {
    unsigned char i = 0;
    unsigned char tmp = 0;

    TRISA = 0b11111111;
    TRISB = 0b00000000;

    while (1) {
        if (tmp == 5) {
            if (i < 9) i++;
            else i = 0;
            tmp = 0;
        }

        PORTB = display7s(0);
        atraso_ms(10);
        PORTB = display7s(i) | 0x10;
        atraso_ms(10);
        
        tmp++;
    }
}
