/*
 * matrix.c
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */
#include <stdio.h>
#include "matrix.h"

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




/**
 *
 * Praktikum 5
 *
 */
void matcopy(int n, double** A, double** B){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			B[i][j] = A[i][j];
		}
	}
}

void matunity(int n, double** A){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)A[i][j] = 1.0;
			else A[i][j] = 0.0;
		}
	}
}

int matcmp(int n, double** A, double** B){
	int i, j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(A[i][j] != B[i][j])return 0;
		}
	}
	return 1;
}

void matpowI(int n, double** A,	unsigned int k,	double** B, double** C){
	unsigned int i;
	matcopy(n, A, B);
	for(i = 1; i < k; i++){
		matmult(n, A, B, C);
		matcopy(n, C, B);
	}
	if(k==1)matcopy(n, A, C);
	else if(k==0)matunity(n,C);
}

void matpowR(int n, double** A,	unsigned int k,	double** B, double** C){
	if(k == 0){
		matunity(n,C);
	}
	else if(k == 1){
		matcopy(n, A, C);
	}
	else {
		matpowR(n,A,k-1,B,C);
		matmult(n, A, C, B);
		matcopy(n, B, C);
	}
}

void matpow(int n, double** A,	unsigned int k,	double** B, double** C){
	if(k == 0){
		matunity(n,C);
	}
	else if(k == 1){
		matcopy(n, A, C);
	}
	else if(k%2 == 0){
		matpow(n, A, k/2, B, C);
		matmult(n, C, C, B);
		matcopy(n, B, C);
	}
	else if(k%2 == 1){
		matpow(n, A, k/2, B, C);
		matmult(n, C, C, B);
		matmult(n, B, A, C);
	}
}








