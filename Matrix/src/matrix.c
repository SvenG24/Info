/*
 * matrix.c
 *
 *  Created on: 03.01.2019
 *      Author: gi-user
 */

#include "matrix.h"
#include <stdlib.h>


Matrix matplus(Matrix A, Matrix B){
	int i,j;
	double** temp;
	for(i=0; i<A.n; i++){
		for(j=0; j<A.n; j++){
			temp[i][j] = A.data[i][j] + B.data[i][j];
		}
	}


	Matrix C = {
			A.n,
			&temp
	};

	/*Matrix C;
	C.n = A.n;
	C.data = (double**)malloc(sizeof(double*) * C.n);
	for(i=0;i<C.n;i++){
		C.data[i] = (double*)malloc(sizeof(double) * C.n);
	}

	C.n = A.n;
	for(i=0; i<A.n; i++){
		for(j=0; j<A.n; j++){
			C.data[i][j] = A.data[i][j] + B.data[i][j];
		}
	}*/
	return C;
}
