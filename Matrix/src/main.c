/*
 * main.c
 *
 *  Created on: 03.01.2019
 *      Author: gi-user
 */

#include <stdio.h>
#include "matrix.h"

int main(){

	double a1[] = { 0.5, -1.0, -1.0 };
	double a2[] = { -1.0, 1.0, 2.0 };
	double a3[] = { -1.0, 2.0, 1.0 };

	double b1[] = { 1.0, 0.0, 0.0, 0.0, 0.0 };
	double b2[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	double b3[] = { 0.0, 0.0, 0.0, 0.0, 0.0 };

	double *A_[] = { a1, a2, a3 };
	double *B_[] = { b1, b2, b3 };

	int i, j;
	Matrix A;
	Matrix B;
	Matrix C;
	A.n = 3;
	B.n = 3;
	A.data = A_;
	B.data = B_;

	C = matplus(A,B);

	for(i=0;i<C.n;i++){
		for(j=0;j<C.n;j++){
			printf("C[%d][%d] = %4.5f \t",i,j,C.data[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
