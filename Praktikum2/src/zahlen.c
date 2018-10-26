/*
 * zahlen.c
 *
 *  Created on: 25.10.2018
 *      Author: Sven
 */

#include "zahlen.h"
#include <stdio.h>

int charTOint(char c) {
	int i;

	if (c <= '9' && c >= '0') {
		i = c - '0';
	} else {
		printf("ERROR: Ungueltiges Zeichen(char) -- '%c' -- !\n",c);
		return ERROR;
	}

	return i;
}





char intTOchar(int i) {
	char c;

	if (i <= 15 && i >= 0) {
		c = i + '0';
	} else {
		printf("ERROR: Ungueltige Ganz Zahl(int) -- %d -- !\n",i);
		return '0';
	}

	return c;
}





int stringTOint(char str[]) {
	int i, a, x = 0;

	if (str[0] == '-') {
		for (i = 1; str[i] != '\0' && i < DIGITS; i++) {
			a = charTOint(str[i]);
			if (a == ERROR) {
				return ERROR;
			}
			x = x * 10 + a;
		}
		x = x * (-1);
	} else {
		for (i = 0; str[i] != '\0' && i < DIGITS; i++) {
			a = charTOint(str[i]);
			if (a == ERROR) {
				return ERROR;
			}
			x = x * 10 + a;
		}
	}

	if(i >= DIGITS){
		printf("ERROR: Die Zeichenkette ist zu lang!!\n");
		return ERROR;
	}

	return x;
}





void revers(char str[]) {
	int i=0, x=0;
	char strReverse[DIGITS+1];

	while(str[x] != '\0') {
		x++;
	}
	while(x > 0) {
		x--;
		strReverse[i] = str[x];
		i++;
	}
	strReverse[i] = '\0';

	for(i=0; strReverse[i] != '\0'; i++) {
		str[i] = strReverse[i];
	}

}





void invert(char str[]) {
	int i;
	for(i=0; str[i] != '\0'; i++) {
		if(str[i] == '0') {
			str[i] = '1';
		} else if(str[i] == '1') {
			str[i] = '0';
		}
	}
}





void intTObinaer(int i, char str[]) {
	int x = 0;
	int rest = 0;

	if(i < 0) {									//Für Negative Zahlen
		i *= -1;
		i--;
		for(x=0; x < DIGITS; x++) {
			if(i != 0) {
				rest = i % 2;
				i = i / 2;
				str[x] = intTOchar(rest);
			} else {
				str[x] = '0';
			}
		}
		str[16] = '\0';

		invert(str);
	} else {									//Für Positive Zahlen
		for(x=0; x < DIGITS; x++) {
			if(i != 0) {
				rest = i % 2;
				i = i / 2;
				str[x] = intTOchar(rest);
			} else {
				str[x] = '0';
			}
		}
		str[16] = '\0';
	}

	revers(str);
}








