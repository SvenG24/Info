/*
 * zahlen.c
 *
 *  Created on: 25.10.2018
 *      Author: Sven
 */

#include "zahlen.h"

int charTOint(char c){
	int i;
	i = c - '0';

	return i;
}


char intTOchar(int i){
	char c;
	c = i + '0';

	return c;
}


int stringTOint(char str[]){
	int i;
	int x[DIGITS+1];

	for(i=0; str[i] != '\o'; i++){
		x[i] = charTOint(str[i]);
	}



	return i;
}
