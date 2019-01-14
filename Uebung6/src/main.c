/*
 * main.c
 *
 *  Created on: 10.01.2019
 *      Author: gi-user
 */
#include <stdio.h>
#include <stdlib.h>
#include "Gesundheit.h"
#include "Bessel.h"
#include "Heuhaufen.h"


int main(){

/*
 *
 * Aufgabe 1
 *
 */

	Patientenprofil P1[1];
	P1[0] = erzeugeProfil();

	P1[0]->Name = "Sven";
	P1[0]->Alter = 21;
	P1[0]->Geschlecht = "Männlich";
	P1[0]->Gewicht = 10;
	P1[0]->Koerpergroesse = 1.79;
	P1[0]->blutdruck->diastolisch = 50;
	P1[0]->blutdruck->systolisch = 40;
	P1[0]->fettwerte->Cholesterin = 24;
	P1[0]->fettwerte->Triglyzerin = 2;

	zeigeProfile(1,P1);


	free(P1[0]->blutdruck);
	free(P1[0]->fettwerte);
	free(P1[0]);




/*
 *
 * Aufgabe 3
 *
 */
	unsigned char u,v,w,a = 0xA5, b = 023, c = 52;

	u = (a>>2)&b;
	v = b|c;
	w = a - c;

	printf("\n\nErgebnis \n u: %d \n v: 0%o \n w: 0x%X \n",u,v,w);





/*
 *
 * Aufgabe 5
 *
 */

	char *heystack = "12345HalloS123Test0123Tt";
	char *needle = "Test";
	int x = strsearch(heystack, needle);
	printf("\nHeystack. %s\nNeedle: %s\nPosition: %d\n",heystack,needle,x);

	x = strsearch_(heystack, needle);
	printf("\nHeystack. %s\nNeedle: %s\nPosition: %d\n",heystack,needle,x);




	return 0;
}
