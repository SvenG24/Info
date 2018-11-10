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
	} else if(c <= 'F' && c >= 'A') {
		i = c - 'A' + 10;
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
	int digit, Faktor , x = 0;

	if(*str == '0'){
		str++;
		if(*str == 'x' || *str == 'X'){
			Faktor = 16;
			str++;
		} else {
			Faktor = 8;
			str--;
		}
	} else {
		Faktor = 10;
	}

	if (*str == '-') {					//Prüfen ob die Zahl negativ ist
		for(str++;*str != '\0';str++) {
			if ((*str < '0' || *str > '9') && (*str < 'A' || *str > 'F')) {
				printf("ERROR: Ungueltiger String -- %s -- !\n", str);
				return 0;
			}
			digit = charTOint(*str);
			if (((long) (x * Faktor + digit)) >= INT_MAX) {
				printf("ERROR: Integer overflow!!!");
			}
			x = x * Faktor + digit;
		}
		x *= (-1);
	} else {								//sonst ist sie positiv
		for (int i = 0; str[i] != '\0'; i++) {
			if ((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F')) {
				printf("ERROR: Ungueltiger String -- %s -- !\n", str);
				return 0;
			}
			digit = charTOint(str[i]);
			if (((long) (x * Faktor + digit)) >= INT_MAX) {
				printf("ERROR: Integer overflow!!!");
			}
			x = x * Faktor + digit;
		}
	}
	return x;
}
void umrechnung(int zahl, int Basis, char str[]) {
	long rest, grenze = 1, i;

	i = zahl;

		for (int b = 1; b < DIGITS; b++) {
			grenze *= Basis;
		}
		grenze = grenze - 1;

		if (i > grenze || i < ((grenze + 1) * (-1))) {// Überprüfen ob die Zahl zu groß ist
			printf("ERROR: Die eingegebene Zahl ist zu groß um sie richtig als binaer Zahl anzuzeigen -- %ld --\n"
				   "       Bitte eine Zahl zwischen %ld bis %ld eingeben!!\n", i, ((grenze + 1) * (-1)), grenze);
		}

		if (i < 0) {									//Für Negative Zahlen
				i *= -1;
				i--;
				for (int x = DIGITS - 1; x >= 0; x--) {
						rest = i % Basis;
						i = i / Basis;
						rest = (Basis - 1) - rest;
						str[x] = intTOchar(rest);
				}
				str[DIGITS] = '\0';
			} else {									//Für Positive Zahlen
				for (int x = DIGITS - 1; x >= 0; x--) {
						rest = i % Basis;
						i = i / Basis;
						str[x] = intTOchar(rest);
				}
				str[DIGITS] = '\0';
			}
}
void intTObinaer(int i, char str[]) {
	umrechnung(i, 2, str);
}

void intTOoktal(int i, char str[]) {
	umrechnung(i, 8, str);
}

void intTOhex(int i, char str[]) {
	umrechnung(i, 16, str);
}








