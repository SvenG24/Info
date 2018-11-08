/*
 * zahlen.c
 *
 *  Created on: 25.10.2018
 *      Author: Sven
 */

#include "zahlen.h"
#include <stdio.h>
#include <limits.h>

int charTOint(char c) {
	int i;

	if (c <= '9' && c >= '0') {	// Überprüfen ob die Eingabe gültig ist {'0','1',...,'9'}
		i = c - '0';
	} else {
		printf("ERROR: Ungueltiges Zeichen(char) -- '%c' -- !\n", c);
		return -1;
	}

	return i;
}

char intTOchar(int i) {
	char c;

	if (i <= 15 && i >= 0) { // Überprüfen ob die Eingabe gültig ist {0,1,...,15}
		c = i + '0';
		if(i > 9) {
			c = (i -10) + 'A';
		}
	} else {
		printf("ERROR: Ungueltige Ganz Zahl(int) -- %d -- !\n", i);
		return 0;
	}

	return c;
}

int stringTOint(char str[]) {
	int i, a, x = 0;

	if (str[0] == '-') {					//Prüfen ob die Zahl negativ ist
		for (i = 1; str[i] != '\0' && i < DIGITS; i++) {
			a = charTOint(str[i]);
			if (a == -1) {
				return 0;
			}

			if (((long) (x * 10 + a)) >= INT_MAX) {
				printf("ERROR: Integer overflow!!!");
			}
			x = x * 10 + a;

		}
		x *= (-1);
	} else {								//sonst ist sie positiv
		for (i = 0; str[i] != '\0' && i < DIGITS; i++) {
			a = charTOint(str[i]);
			if (a == -1) {
				return 0;
			}

			if (((long) x * 10 + a) > ((long) INT_MAX)) {
				printf("ERROR: Integer overflow!!!\n");
			}
			x = x * 10 + a;
		}
	}
	return x;
}

void intTObinaer(int i, char str[]) {
	int x, rest, grenze, a = 1, b;

	for (b = 1; b < DIGITS; b++) {
		a *= 2;
	}
	grenze = a - 1;

	if (i > grenze || i < ((grenze + 1) * (-1))) {// Überprüfen ob die Zahl zu groß ist
		printf(
				"ERROR: Die eingegebene Zahl ist zu groß um sie richtig als binaer Zahl anzuzeigen -- %i --\n"
						"       Bitte eine Zahl zwischen %i bis %i eingeben!!\n",
				i, ((grenze + 1) * (-1)), grenze);
	}

	if (i < 0) {									//Für Negative Zahlen
		i *= -1;
		i--;
		for (x = DIGITS - 1; x >= 0; x--) {
			if (i != 0) {
				rest = i % 2;
				i = i / 2;

				if (rest == 1) {					//Bit invertierung
					rest = 0;
				} else if (rest == 0) {
					rest = 1;
				}

				str[x] = intTOchar(rest);
			} else {
				str[x] = '1';
			}
		}
		str[DIGITS] = '\0';
	} else {									//Für Positive Zahlen
		for (x = DIGITS - 1; x >= 0; x--) {
			if (i != 0) {
				rest = i % 2;
				i = i / 2;
				str[x] = intTOchar(rest);
			} else {
				str[x] = '0';
			}
		}
		str[DIGITS] = '\0';
	}
}

