/*
 * zahlen.h
 *
 *  Created on: 25.10.2018
 *      Author: Sven
 */

#ifndef ZAHLEN_H_
#define ZAHLEN_H_



/** Verwende zur Darstellung maximal
 *  DIGITS lange Zeichenketten					*/
#define DIGITS 16

/** Verwandle ein ASCII char in die entsprechende
 *  Ganzzahl und gebe diese als Ergenis zurueck.*/
int charTOint(char c);

/** Verwandle eine Ganzzahl in das entsprechende
 *  ASCII Zeichen und gebe diese als Erebnis zurueck.*/
char intTOchar(int i);

/** Bilde aus der Zeichenkette str eine Ganzzahl zur Basis 10
 *  und gebe diese als Ergebnis zurueck.		*/
int stringTOint(char str[]);

/** Schreibt Binaerdarstellung der
 *  Ganzzahl i nach str.						*/
void intTObinaer(int i, char str[]);


#endif /* ZAHLEN_H_ */
