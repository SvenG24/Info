/*
 * main.c
 *
 *  Created on: 11.12.2018
 *      Author: gi-user
 */

#include <stdio.h>
#include <float.h>
//#include "util.h"

#define dabs(x) (x)<0? -(x) : (x)

int count = 0;


double dmasch(double x_0, double a){
	double x_n_1, x_n = x_0;
	long i=0;
	do{
		i++;
		x_n_1 = x_n;
		x_n = x_n_1 / a;
	}while(1 + x_n != 1);

	return dabs(x_n);
}

float fmasch(float x_0, float a){
	float x_n_1, x_n = x_0;
	long i=0;
	do{
		i++;
		x_n_1 = x_n;
		x_n = x_n_1 / a;
	}while(1 + x_n != 1);

	return dabs(x_n);
}


int binominalrek(int n, int k){
	int erg, erg1, erg2;

	count++;
	//printf("BEG %d: %d,%d\n",count,n,k);
	if(k == 0 || k == n)erg = 1;
	else if(k<0 || k>n)erg = 0;
	else {
		erg1 = binominalrek(n - 1, k);
		erg2 = binominalrek(n - 1, k - 1);
		erg = erg1 + erg2;
	}
	//printf("End %d: %d\n",count,erg);
	//count--;
	return erg;
}

int fakultaet(int n){
	int i,erg=1;
	for(i=2;i<=n;i++){
		erg *= i;
		count++;
	}
	return erg;
}

int binominalexp(int n, int k){
	int erg;
	erg = fakultaet(n)/(fakultaet(k)*fakultaet(n-k));
	return erg;
}


int Funktion1(int n){
	if(n == 1)return 1;
	if(n%2 == 0)return Funktion1(n/2);
	else return Funktion1(3*n+1);
}
int Funktion2(int n){
	if(n == 1)return 1;
	else return (Funktion2(n-1) + 2*n - 1);
}
int Funktion3(int n){
	if(n == 1 || n ==2)return 1;
	else return (Funktion3(n - Funktion3(n-1)) + Funktion3(n - Funktion3(n-2)));
}

int Funktion4(int n){
	if(n > 100)return (n - 10);
	else return Funktion4(Funktion4(n + 11));
}

int main(){
	/* Aufgabe 1 */
	printf("Genauigkeit = %.343lf\n",dmasch(1,2.0));
	printf("Genauigkeit = %.343lf\n",dmasch(1,10.0));
	printf("Genauigkeit = %.343lf\n",dmasch(1,16.0));
	printf("\t      %.343lf\n\n",DBL_MIN);
	printf("Genauigkeit = %.73f\n",fmasch(1,2.0));
	printf("Genauigkeit = %.73f\n",fmasch(1,10.0));
	printf("Genauigkeit = %.73f\n",fmasch(1,16.0));
	printf("\t      %.73lf\n\n",FLT_MIN);



	/* AUfgabe 2 */
	int n_ = 3;
	int k = 2;
	printf("Binominal(rekursiv): %d über %d = %d\n",n_,k,binominalrek(n_,k));
	printf("Durchläufe = %d\n",count);
	count = 0;
	printf("\nBinominal:           %d über %d = %d\n",n_,k,binominalexp(n_,k));
	printf("Durchläufe = %d\n",count);



	/* Aufgabe 3 */
	int n;

	printf("\nFunktion 1\n");			/* immer 1 */
	for(n = 1; n <= 7; n++){
		printf("n = %d: %d  |  ",n,Funktion1(n));
	}
	printf("\nFunktion 2\n");		/* n^2 */
	for(n = 1; n <= 7; n++){
		printf("n = %d: %d  |  ",n,Funktion2(n));
	}
	printf("\nFunktion 3\n");
	for(n = 1; n <= 7; n++){
		printf("n = %d: %d  |  ",n,Funktion3(n));
	}
	printf("\nFunktion 4\n");		/* immer 91 */
	for(n = 1; n <= 7; n++){
		printf("n = %d: %d  |  ",n,Funktion4(n));
	}





	return 0;
}
