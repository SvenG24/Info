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




/**
 *
 * Praktikum 5
 *
 */


enum Boolean { false, true };
typedef enum Boolean boolean;

/**
 * Copy the matrix A,
 * returning the result in matrix C.
 */
void matcopy(int n, 	/* dimensions of problem	*/
		double** A, 	/* the matrix A				*/
		double** B);	/* place for the result		*/

/**
 * returning the unity matrix in matrix A.
 */
void matunity(int n, 	/* dimensions of problem	*/
		double** A); 	/* the matrix A				*/

/**
 * Vergleiche matrix A mit matrix B,
 * gibt true zurück wenn sie gleich sind
 * und flase wenn sie nicht übereinstimmen
 */
void matunity(int n, 	/* dimensions of problem	*/
		double** A); 	/* the matrix A				*/


/**
 * Calculate the k-th power A**k of matrix A,
 * returning the result in matrix C, optimized version.
 */
void matpow(int n,		/* dimensions of problem	*/
		double** A,		/* the matrix A				*/
		unsigned int k,	/* the power coefficient	*/
		double** B, 	/* place for temporary results */
		double** C);	/* place for the result		*/

/**
 * Calculate the k-th power A**k of matrix A,
 * returning the result in matrix C, naive recursion.
 */
void matpowR(int n,		/* dimensions of problem	*/
		double** A,		/* the matrix A				*/
		unsigned int k,	/* the power coefficient	*/
		double** B, 	/* place for temporary results */
		double** C);	/* place for the result		*/

/**
 * Calculate the k-th power A**k of matrix A,
 * returning the result in matrix C, iterative version.
 */
void matpowI(int n,		/* dimensions of problem	*/
		double** A,		/* the matrix A				*/
		unsigned int k,	/* the power coefficient	*/
		double** B, 	/* place for temporary results */
		double** C);	/* place for the result		*/


#endif /* BIB_MATRIX_H_ */
