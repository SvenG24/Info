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
	int zahl, x = 0;


	if (*str == '-') {					//Prüfen ob die Zahl negativ ist
		for(str++;*str != '\0';str++) {
			if (*str < '0' || *str > '9') {
				printf("ERROR: Ungueltiger String -- %s -- !\n", str);
				return 0;
			}
			zahl = charTOint(*str);
			if (((long)x * 10 + zahl) > INT_MAX) {
				printf("ERROR: Integer overflow!!!\n");
			}
			x = x * 10 + zahl;
		}
		x *= (-1);
	} else {								//sonst ist sie positiv
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] < '0' || str[i] > '9') {
				printf("ERROR: Ungueltiger String -- %s -- !\n", str);
				return 0;
			}
			zahl = charTOint(str[i]);
			if (((long)x * 10 + zahl) > INT_MAX) {
				printf("ERROR: Integer overflow!!!\n");
			}
			x = x * 10 + zahl;
		}
	}
	return x;
}

void intTObinaer(int i, char str[]) {
	int rest, grenze = 1;

	for (int b = 1; b < DIGITS; b++) {
		grenze *= 2;
	}
	grenze = grenze - 1;
	if (i > grenze || i < ((grenze + 1) * (-1))) {// Überprüfen ob die Zahl zu groß ist
		printf("ERROR: Die eingegebene Zahl ist zu groß um sie richtig als binaer Zahl anzuzeigen -- %i --\n"
			   "       Bitte eine Zahl zwischen %i bis %i eingeben!!\n", i, ((grenze + 1) * (-1)), grenze);
	}

	if (i < 0) {									//Für Negative Zahlen
		i *= -1;
		i--;
		for (int x = DIGITS - 1; x >= 0; x--) {
				rest = i % 2;
				i = i / 2;
				rest = 1 - rest;					//Bit invertierung
				str[x] = intTOchar(rest);
		}
		str[DIGITS] = '\0';
	} else {										//Für Positive Zahlen
		for (int x = DIGITS - 1; x >= 0; x--) {
				rest = i % 2;
				i = i / 2;
				str[x] = intTOchar(rest);
		}
		str[DIGITS] = '\0';
	}
}

