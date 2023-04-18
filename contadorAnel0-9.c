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

    TRISA = 0b11111111;
    TRISB = 0b00000000;

    while (1) {
        if (RA1 == 0) {
            if (i < 9) i++;
            else i = 0;
            while (RA1 == 0);
        }

        PORTB = display7s(0);
        atraso_ms(1);
        PORTB = display7s(i) | 0x10;
        atraso_ms(1);
    }
}
