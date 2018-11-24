/*
 * matrix.h
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */

#ifndef BIB_MATRIX_H_
#define BIB_MATRIX_H_

/**
∗ Addition of vector x with vector y,
∗ returning the result in vector z=x+y.
*/
void vecplus(int n,				/* dimensions of problem */
		double* x, double* y,	/* vector x and vector y */
		double* z);				/* the result vector z */

/**
∗ Multiply vector x with vector y,
∗ returning the result of x∗y.
*/
double vecmult(int n,			/* dimensions of problem */
		double* x, double* y);	/* left and right vectors */

/**
∗ Addition of matrix A with matrix B,
∗ returning the result in matrix C=A+B.
*/
void matplus(int n,				/* dimensions of problem */
		double** A, double** B, /* matrix A and matrix B */
		double** C);			/* the result matrix C */

/**
∗ Multiply matrix A with matrix B,
∗ returning the result in matrix C=A∗B.
*/
void matmult(int n,				/* dimensions of problem */
		double** A, double** B, /* matrix A and matrix B */
		double** C);			/* the result matrix C */

/**
∗ Multiply matrix A with vector x,
∗ returning the result in vector y=A∗x.
*/
void matmulvec(int n,			/* dimensions of problem */
		double* x, double* y,	/* left and right vectors */
		double** A);			/* coefficients of matrix */

#endif /* BIB_MATRIX_H_ */
