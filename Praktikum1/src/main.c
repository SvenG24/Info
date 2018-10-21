/*
 * main.c
 *
 *  Created on: 21.10.2018
 *      Author: gi-user
 */

#include <stdio.h>
#include <stdlib.h>

int main(){

//Aufgabe 1
	printf("Hallo Welt!!\n\n");







//Aufgabe 2

	//int a,b,b;
	float a,b,c;


	a = 5;										/*Variablen Werte zuweisen*/
	b = 4;
	c = a + b;									/*Variablen addieren und in c speichern*/
	//printf("%i + %i = %i\n\n\n",a,b,c);
	printf("%5.0f + %5.0f = %1.0f \n",a,b,c);	/*Ergebnis ausgeben*/

	a = 3.141;
	b = 2.718;
	c = a + b;
	//printf("%i + %i = %i\n\n\n",a,b,c);
	printf("%1.3f + %1.3f = %1.3f \n\n\n",a,b,c);








//Aufgabe 3
	int summe[3] = {0,0,0}, n = 0, i;							/*Variablen initialisieren*/

	printf("  n\t n*n\t s(n)\t q(n) \n\n");

	for(i=0; i<10; i++){						/*For schleife wird solange ausgeführt wie i kleiner 10 ist; Bei jedem Schleifen durchlauf wird i um eins erhöht(i++;)*/
		n++;									/*n  hochzälen*/
		summe[0] = n * n;						/*n² berechnen*/
		summe[1] += n;							/*n  aufsummieren*/
		summe[2] += n * n;						/*n² aufsummieren*/

		printf("%3i \t %3i \t %3i \t %3i \n",n,summe[0],summe[1],summe[2]);
	}

	return EXIT_SUCCESS;

}

