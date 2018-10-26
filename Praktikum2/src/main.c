/*
 * main.c
 *
 *  Created on: 25.10.2018
 *      Author: Sven
 */

#include <stdio.h>
#include "zahlen.h"

int main(int argc, char* argv[]){
	/** Puffer fuer eine Zahl als Zeichenkette, mit terminierender Null 	*/
	char puffer[DIGITS+1];
	char * str = "47112";
	int x;
	/* 1) Optionales Kommandozeilenargument verwenden.						*/
	if (argc>1) {
		str = argv[1];
	}

	/* 2) Zahl aus einer Zeichenkette berechnen. 							*/
	x = stringTOint(str);
	if(x == ERROR){
		return 0;
	}
	printf("Zeichenkette \"%s\" als int: %d\n",str,x);

	/* 3) Zahl als Binaerzeichenkette darstellen. 							*/
	intTObinaer(x, puffer);
	printf("Zahl int: %d als Binaerzahl: %s\n",x,puffer);


	return 0;
}
