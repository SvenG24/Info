/*
 * main.c
 *
 *  Created on: 13.11.2018
 *      Author: gi-user
 */

#include <stdio.h>
#include "zahlen.h"
#include "util.h"


int main(int argc, char *argv[]) {
	char operator, sx[DIGITS+1],sy[DIGITS+1], sz[DIGITS+1];
	int x,y,z;

	/* Übergebene Argumente auswerten*/
	if (argc < 4 || argc > 4){
		printf("Falsche Eingabe: %s <x> <operator> <y> \n",argv[0]);
		return 0;
	}
	x = stringTOint(argv[1]);
	y = stringTOint(argv[3]);
	operator = *argv[2];

	/* Aufgabe lösen/berechnen */
	z = solve(x,operator,y);
	printf("Solve: %d %c %d \n",x,operator,y);

	/* Ergebnise als Binär ausgeben */
	intTObinaer(x,sx);
	intTObinaer(y,sy);
	intTObinaer(z,sz);
	printf("\n  %s %d \n%c %s %d \n= %s %d \n",sx,x,operator,sy,y,sz,z);

	return 0;
}
