/*
 * matrix.h
 *
 *  Created on: 03.01.2019
 *      Author: gi-user
 */

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct {
	unsigned int n;
	double** data;
} Matrix;



Matrix matplus(Matrix A, Matrix B);

#endif /* MATRIX_H_ */
