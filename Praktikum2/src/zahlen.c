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
	int x = 0;

	for(i=0; str[i] != '\0'; i++){
		x = x * 10 + charTOint(str[i]);
	}

	return x;
}


void intTObinaer(int i, char str[]){
	int x=0;
	while(i != 0){
		i = i % 2;
		str[x] = intTOchar();
		x++;
	}

}





