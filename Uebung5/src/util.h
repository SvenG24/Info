/*
 * util.h
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */

#ifndef UTIL_H_
#define UTIL_H_

/**
 * Berechnet die Länge der Zeichenkette
 */
int slen(char *str);

/**
 * Berechnet den größten gemeinsamen Teiler von a und b
 * Für positive Zahlen.
 * Um das ggT zu berechnen wird die Funktion kgV mitgenutzt
 */
int ggT(int a, int b);

/**
 * Berechnet das kleinste gemeinsame Vielfache von a und b
 * für Positive Zahlen
 */
int kgV(int a, int b);

/**
 * Dreht die Zeichenkette um. Also gibt die Zeichenkette Rückwärts zurück
 */
void reverse(char *str);

/**
 * Berechnet die fakultät von n
 */
int faculty(int n);

int binominal(int n, int k);


#endif /* UTIL_H_ */
