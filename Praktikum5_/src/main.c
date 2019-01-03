/*
 * main.c
 *
 *  Created on: 02.01.2019
 *      Author: gi-user
 */
#include <stdio.h>
#include "matrix.h"


void matTest(int n, double** A, int k, double** B, double** C){
	int cmp1,cmp2,cmp3,i,j;

	matpowI(n,A,k,B,C);
	matcopy(n,C,B);
	matpowR(n,A,k,B,C);
	cmp1 = matcmp(n,B,C);		/*Vergleiche die Ergebnisse der Iterativen und Rekursiven Version*/

	matcopy(n,C,B);
	matpow(n,A,k,B,C);
	cmp2 = matcmp(n,B,C);		/*Vergleiche die Ergebnisse der Rekursiven und optimierten Version*/

	matcopy(n,C,B);
	matpowI(n,A,k,B,C);
	cmp3 = matcmp(n,B,C);		/*Vergleiche die Ergebnisse der Iterativen und optimierten Version*/


	if(cmp1 == 1 && cmp2 == 1 && cmp3 == 1)printf("Alle FUnktion liefern das gleiche Ergebnis\n");
	if(cmp1 == 0 || cmp2 == 0 || cmp3 == 0)printf("FEHLER: Die Funktionen liefern unterschiedliche Ergebnisse\n");


	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("C[%d][%d] = %4.5f \t",i,j,C[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}





int main(){

	int n = 3, k = 5;

	double a1[] = { 0.5, -1.0, -1.0 };
	double a2[] = { -1.0, 1.0, 2.0 };
	double a3[] = { -1.0, 2.0, 1.0 };

	double b1[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double b2[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double b3[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double b4[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double b5[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	double c1[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double c2[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double c3[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double c4[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double c5[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	double *A[] = { a1, a2, a3 };
	double *B[] = { b1, b2, b3, b4, b5 };
	double *C[] = { c1, c2, c3, c4, c5 };






	int n1 = 3, k1 = 3;
	double d1[] = { 1.0, 1.0, 3.0 };
	double d2[] = { 5.0, 2.0, 6.0 };
	double d3[] = { -2.0, -1.0, -3.0 };
	double *D[] = { d1, d2, d3 };



	int n2 = 2, k2 = 8;
	double e1[] = { 2.0, 1.0};
	double e2[] = { 0.0, 2.0};
	double *E[] = { e1, e2};


	int n3 = 5, k3;
	double f1[] = { 0.0, 0.0, 0.0, 0.0, 16.0 };
	double f2[] = { 0.75, 0.0, 0.0, 0.0, 0.0 };
	double f3[] = { 0.0, 2.0/3.0, 0.0, 0.0, 0.0 };
	double f4[] = { 0.0, 0.0, 0.5, 0.0, 0.0 };
	double f5[] = { 0.0, 0.0, 0.0, 0.25, 0.0 };
	double *F[] = { f1, f2, f3, f4, f5 };








	printf("Matrix A aus dem Praktikum 4\n");
	matTest(n,A,k,B,C);

	printf("Matrix 1\n");
	matTest(n1,D,k1,B,C);

	printf("Matrix 2\n");
	matTest(n2,E,k2,B,C);

	printf("Matrix 3\n");
	k3=0;
	while(k3 < 6){
		k3++;
		matTest(n3,F,k3,B,C);
	}


	return 0;
}
