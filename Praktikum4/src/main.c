/*
 * main.c
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */
#include <stdio.h>
#include "bib/matrix.h"


int main(){

	int i, j, n = 3;

	double x[] = { 1, 2, 4 };
	double y[] = { 3, 5 ,6 };
	double z[] = { 0, 0, 0 };
	double w[] = { 0, 0, 0 };

	double a1[] = { 0.5, -1.0, -1.0 };
	double a2[] = { -1.0, 1.0, 2.0 };
	double a3[] = { -1.0, 2.0, 1.0 };

	double b1[] = { 0.5, 0.0, 1.5 };
	double b2[] = { 5.0, -0.5, -3.0 };
	double b3[] = { -1.0, -1.0, -0.75 };

	double c1[] = { 0.0, 0.0, 0.0 };
	double c2[] = { 0.0, 0.0, 0.0 };
	double c3[] = { 0.0, 0.0, 0.0 };

	double *A[] = { a1, a2, a3 };
	double *B[] = { b1, b2, b3 };
	double *C[] = { c1, c2, c3 };

	char plus,gleich;


	/* Vektor plus Vektor */
	vecplus(n, x, y, z);
	printf("Vektor + Vektor:\n");
	for (i = 0; i < n; i++) {
		if(i==1){plus='+';gleich='=';}
		else{plus=' ';gleich=' ';}
		printf("( %5.2f ) %c ( %5.2f )  %c  ( %5.2f ) \n", x[i],plus, y[i],gleich, z[i]);
	}
	printf("\n");



	/* Skalarprodukt */
	printf("Skalarprodukt: \nx*y = %5.2f\n\n", vecmult(n, x, y));




	/* Matrix plus Matrix */
	matplus(n, A, B, C);
	printf("Matrix + Matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("C[%d][%d] = %5.2f   ", i, j, C[i][j]);
		}
		printf("\n");
	}
	printf("\n");



	/* Matrix mal Vektor */
	matmulvec(n, x, w, C);
	printf("Matrix x Vektor:\n");
	for (i = 0; i < n; i++) {
		printf("c[%d] = %5.2f\n", i, w[i]);
	}
	printf("\n");



	/* Matrix mal Matrix */
	matmult(n, A, B, C);
	printf("Matrix x Matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("C[%d][%d] = %5.2f   ", i, j, C[i][j]);
		}
		printf("\n");
	}







	/* Lineares Gleichungsystem lösen */
	/*
	lgsLoesen(n,A,x);
	printf("Matrix x Matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("C[%d][%d] = %5.2f   ", i, j, C[i][j]);
		}
		printf("\n");
	}
	*/

	return 0;
}
