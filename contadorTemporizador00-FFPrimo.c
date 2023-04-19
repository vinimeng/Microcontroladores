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
    unsigned char i = 0x00;
    unsigned char j = 0x00;
    unsigned char c = 0x00;
    unsigned char d = 0x00;
    unsigned char tmp = 0x00;
    unsigned char primo = 0;

    TRISA = 0b11111110;
    TRISB = 0b00000000;

    while (1) {
        if (primo) {
            if (RA1 == 0) {
                primo = 0;
                tmp = 0x10;
                while (RA1 == 0);
            }

            if (i > 99) {
                PORTA = 0b11111111;

                if (i < 0x10) {
                    PORTB = display7s(0x00);
                    j = 0x00;
                } else if (i >= 0x10 && i < 0x20) {
                    PORTB = display7s(0x01);
                    j = 0x10;
                } else if (i >= 0x20 && i < 0x30) {
                    PORTB = display7s(0x02);
                    j = 0x20;
                } else if (i >= 0x30 && i < 0x40) {
                    PORTB = display7s(0x03);
                    j = 0x30;
                } else if (i >= 0x40 && i < 0x50) {
                    PORTB = display7s(0x04);
                    j = 0x40;
                } else if (i >= 0x50 && i < 0x60) {
                    PORTB = display7s(0x05);
                    j = 0x50;
                } else if (i >= 0x60 && i < 0x70) {
                    PORTB = display7s(0x06);
                    j = 0x60;
                } else if (i >= 0x70 && i < 0x80) {
                    PORTB = display7s(0x07);
                    j = 0x70;
                } else if (i >= 0x80 && i < 0x90) {
                    PORTB = display7s(0x08);
                    j = 0x80;
                } else if (i >= 0x90 && i < 0xA0) {
                    PORTB = display7s(0x09);
                    j = 0x90;
                } else if (i >= 0xA0 && i < 0xB0) {
                    PORTB = display7s(0x0A);
                    j = 0xA0;
                } else if (i >= 0xB0 && i < 0xC0) {
                    PORTB = display7s(0x0B);
                    j = 0xB0;
                } else if (i >= 0xC0 && i < 0xD0) {
                    PORTB = display7s(0x0C);
                    j = 0xC0;
                } else if (i >= 0xD0 && i < 0xE0) {
                    PORTB = display7s(0x0D);
                    j = 0xD0;
                } else if (i >= 0xE0 && i < 0xF0) {
                    PORTB = display7s(0x0E);
                    j = 0xE0;
                } else if (i >= 0xF0) {
                    PORTB = display7s(0x0F);
                    j = 0xF0;
                }
                atraso_ms(2);

                PORTB = display7s(i - j) | 0x10;
                atraso_ms(2);
            } else {
                PORTA = 0b11111110;

                if (i < 10) {
                    PORTB = display7s(0);
                    j = 0;
                } else if (i >= 10 && i < 20) {
                    PORTB = display7s(1);
                    j = 10;
                } else if (i >= 20 && i < 30) {
                    PORTB = display7s(0x02);
                    j = 20;
                } else if (i >= 30 && i < 40) {
                    PORTB = display7s(3);
                    j = 30;
                } else if (i >= 40 && i < 50) {
                    PORTB = display7s(4);
                    j = 40;
                } else if (i >= 50 && i < 60) {
                    PORTB = display7s(5);
                    j = 50;
                } else if (i >= 60 && i < 70) {
                    PORTB = display7s(6);
                    j = 60;
                } else if (i >= 70 && i < 80) {
                    PORTB = display7s(7);
                    j = 70;
                } else if (i >= 80 && i < 90) {
                    PORTB = display7s(8);
                    j = 80;
                } else if (i >= 90) {
                    PORTB = display7s(9);
                    j = 90;
                }
                atraso_ms(2);

                PORTB = display7s(i - j) | 0x10;
                atraso_ms(2);
            }
        } else {
            PORTA = 0b11111110;

            if (tmp == 0x10) {
                if (i < 0xFF) i++;
                else i = 0x00;
                tmp = 0x00;
            }

            if (i < 0x10) {
                PORTB = display7s(0x00);
                j = 0x00;
            } else if (i >= 0x10 && i < 0x20) {
                PORTB = display7s(0x01);
                j = 0x10;
            } else if (i >= 0x20 && i < 0x30) {
                PORTB = display7s(0x02);
                j = 0x20;
            } else if (i >= 0x30 && i < 0x40) {
                PORTB = display7s(0x03);
                j = 0x30;
            } else if (i >= 0x40 && i < 0x50) {
                PORTB = display7s(0x04);
                j = 0x40;
            } else if (i >= 0x50 && i < 0x60) {
                PORTB = display7s(0x05);
                j = 0x50;
            } else if (i >= 0x60 && i < 0x70) {
                PORTB = display7s(0x06);
                j = 0x60;
            } else if (i >= 0x70 && i < 0x80) {
                PORTB = display7s(0x07);
                j = 0x70;
            } else if (i >= 0x80 && i < 0x90) {
                PORTB = display7s(0x08);
                j = 0x80;
            } else if (i >= 0x90 && i < 0xA0) {
                PORTB = display7s(0x09);
                j = 0x90;
            } else if (i >= 0xA0 && i < 0xB0) {
                PORTB = display7s(0x0A);
                j = 0xA0;
            } else if (i >= 0xB0 && i < 0xC0) {
                PORTB = display7s(0x0B);
                j = 0xB0;
            } else if (i >= 0xC0 && i < 0xD0) {
                PORTB = display7s(0x0C);
                j = 0xC0;
            } else if (i >= 0xD0 && i < 0xE0) {
                PORTB = display7s(0x0D);
                j = 0xD0;
            } else if (i >= 0xE0 && i < 0xF0) {
                PORTB = display7s(0x0E);
                j = 0xE0;
            } else if (i >= 0xF0) {
                PORTB = display7s(0x0F);
                j = 0xF0;
            }
            atraso_ms(2);

            PORTB = display7s(i - j) | 0x10;
            atraso_ms(2);

            tmp++;

            for (d = 0x01; d <= i; d++) {
                if (i % d == 0x00) {
                    c++;
                    if (c > 0x02) {
                        break;
                    } 
                }
            }

            if (c == 0x02) {
                primo = 1;
            }

            c = 0x00;
        }
    }
}
