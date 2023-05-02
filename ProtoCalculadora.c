/*
 * File:   main.c
 * Author: Vinicius Meng - 0250583
 *
 * Created on 2 de Maio de 2023, 08:50
 */

#include "config_628A.h"
#include "atraso.h"
#include "lcd.h"
#include "teclado.h"
#include "i2c.h"
#include "eeprom_ext.h"
#include "rtc.h"
#include "serial.h"

#include <string.h>

void my_reverse(char s[]) {
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    my_reverse(s);
}

void main() {
    unsigned char i, tmp;
    char temp[5];
    int n1, n2;
    tmp = 0;

    CMCON = 0x07;
    TRISA = 0x30;
    TRISB = 0xE7;

    PORTA = 0xFE;
    PORTB = 0x00;

    lcd_init();
    lcd_cmd(L_CLR);

    while (1) {
        if (tmp == 0) {
            lcd_cmd(L_L1);
            lcd_str("Escolha: + - * /");
            lcd_cmd(L_L2);
            lcd_str("         1 2 3 4");
            while (1) {
                int digito = tc_tecla(0);
                if (digito == 1) {
                    tmp = 1;
                    break;
                } else if (digito == 2) {
                    tmp = 2;
                    break;
                } else if (digito == 3) {
                    tmp = 3;
                    break;
                } else if (digito == 4) {
                    tmp = 4;
                    break;
                }
            }
        } else if (tmp == 1) {
            char tmp1 = 0;
            lcd_cmd(L_CLR);
            lcd_str("Primeiro n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n1 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }

            lcd_cmd(L_L2);
            lcd_str("Segundo  n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n2 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }
            lcd_cmd(L_CLR);
            itoa(n1, temp);
            lcd_str(temp);
            lcd_str(" + ");
            itoa(n2, temp);
            lcd_str(temp);
            lcd_str(" = ");
            itoa(n1 + n2, temp);
            lcd_str(temp);
            lcd_cmd(L_L2);
            lcd_str("# -> inicio");
            while (1) {
                int digito = tc_tecla(0);
                if (digito == 12) {
                    tmp = 0;
                    break;
                }
            }
        } else if (tmp == 2) {
            char tmp1 = 0;
            lcd_cmd(L_CLR);
            lcd_str("Primeiro n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n1 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }

            lcd_cmd(L_L2);
            lcd_str("Segundo  n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n2 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }
            lcd_cmd(L_CLR);
            itoa(n1, temp);
            lcd_str(temp);
            lcd_str(" - ");
            itoa(n2, temp);
            lcd_str(temp);
            lcd_str(" = ");
            itoa(n1 - n2, temp);
            lcd_str(temp);
            lcd_cmd(L_L2);
            lcd_str("# -> inicio");
            while (1) {
                int digito = tc_tecla(0);
                if (digito == 12) {
                    tmp = 0;
                    break;
                }
            }
        } else if (tmp == 3) {
            char tmp1 = 0;
            lcd_cmd(L_CLR);
            lcd_str("Primeiro n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n1 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }

            lcd_cmd(L_L2);
            lcd_str("Segundo  n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n2 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }
            lcd_cmd(L_CLR);
            itoa(n1, temp);
            lcd_str(temp);
            lcd_str(" * ");
            itoa(n2, temp);
            lcd_str(temp);
            lcd_str(" = ");
            itoa(n1 * n2, temp);
            lcd_str(temp);
            lcd_cmd(L_L2);
            lcd_str("# -> inicio");
            while (1) {
                int digito = tc_tecla(0);
                if (digito == 12) {
                    tmp = 0;
                    break;
                }
            }
        }  else if (tmp == 4) {
            char tmp1 = 0;
            lcd_cmd(L_CLR);
            lcd_str("Primeiro n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n1 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }

            lcd_cmd(L_L2);
            lcd_str("Segundo  n: ");
            while (1) {
                if (tmp1 == 0) {
                    int digito = tc_tecla(0);
                    if (digito <= 9) {
                        n2 = digito;
                        itoa(digito, temp);
                        lcd_str(temp);
                        break;
                    }
                }
            }
            lcd_cmd(L_CLR);
            itoa(n1, temp);
            lcd_str(temp);
            lcd_str(" / ");
            itoa(n2, temp);
            lcd_str(temp);
            lcd_str(" = ");
            itoa(n1 / n2, temp);
            lcd_str(temp);
            lcd_cmd(L_L2);
            lcd_str("# -> inicio");
            while (1) {
                int digito = tc_tecla(0);
                if (digito == 12) {
                    tmp = 0;
                    break;
                }
            }
        }
    }
}
