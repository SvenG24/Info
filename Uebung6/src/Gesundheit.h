/*
 * Gesundheit.h
 *
 *  Created on: 10.01.2019
 *      Author: gi-user
 */

#ifndef GESUNDHEIT_H_
#define GESUNDHEIT_H_

typedef struct patientenprofil_struct *Patientenprofil;
typedef struct blutdruck_struct *Blutdruck;
typedef struct fettwerte_struct *Fettwerte;

struct patientenprofil_struct {
	char *Name;
	char *Geschlecht;
	double Gewicht;
	int Alter;
	double Koerpergroesse;
	Blutdruck blutdruck;
	Fettwerte fettwerte;
};

struct blutdruck_struct {
	double systolisch;
	double diastolisch;
};

struct fettwerte_struct {
	double Cholesterin;
	double Triglyzerin;
};


Patientenprofil erzeugeProfil();
void zeigeProfile(int anzahl, Patientenprofil p[]);

#endif /* GESUNDHEIT_H_ */
