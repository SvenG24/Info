/*
 * Gesundheit.c
 *
 *  Created on: 10.01.2019
 *      Author: gi-user
 */

#include "Gesundheit.h"
#include <stdlib.h>
#include <stdio.h>

Patientenprofil erzeugeProfil(){
	Blutdruck blutdruck = malloc(sizeof(struct blutdruck_struct));
	Fettwerte fettwerte = malloc(sizeof(struct fettwerte_struct));
	Patientenprofil p = malloc(sizeof(struct patientenprofil_struct));
	p->blutdruck = blutdruck;
	p->fettwerte = fettwerte;

	return p;
}


void zeigeProfile(int anzahl, Patientenprofil p[]){
	int i;

	for(i=0;i<anzahl;i++){
		printf("Name       : %s\n",p[i]->Name);
		printf("Alter      : %d\n",p[i]->Alter);
		printf("Geschlecht : %s\n",p[i]->Geschlecht);
		printf("Körpergröße: %5.2lf\n",p[i]->Koerpergroesse);
		printf("Gewicht    : %5.3lf\n",p[i]->Gewicht);
		printf("Blutdruck  : %5.3lf, %5.3lf\n",p[i]->blutdruck->systolisch,p[i]->blutdruck->diastolisch);
		printf("Fettwert   : %5.3lf, %5.3lf\n",p[i]->fettwerte->Cholesterin,p[i]->fettwerte->Triglyzerin);
	}

}
