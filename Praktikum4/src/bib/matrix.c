/*
 * matrix.c
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */
#include <stdio.h>

void vecplus(int n, double *x, double *y, double *z) {
	int i;

	for(i = 0; i < n; i++) {
		z[i] = x[i] + y[i];
	}
}

double vecmult(int n, double *x, double *y) {
	int i;
	double z = 0;

	for(i = 0; i < n; i++){
		z += x[i] * y[i];
	}
	return z;
}

void matplus(int n, double **A, double **B, double **C){
	int i,j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

void matmult(int n, double **A, double **B, double **C){
	int i,j,k;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			C[i][j] = 0;
			for(k = 0; k<n; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void matmulvec(int n, double *x , double *y, double **A){
	int i,j;

	for(i=0; i<n; i++){
		y[i] = 0;
		for(j=0; j<n; j++){
			y[i] += A[i][j] * x[j];
		}
	}
}












