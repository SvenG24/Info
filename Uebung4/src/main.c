/*
 * main.c
 *
 *  Created on: 29.11.2018
 *      Author: gi-user
 */
#include <stdio.h>
#include "util.h"

void pointerTest(){

	char s1[] = "Zeichenkette eins";
	char *s2 = "Zeichenkette zwei";

	printf("\n\n PointerTest \n");

	printf("%s länge: %d\n",s1,slen(s1));
	reverse(s1);
	printf("%s länge: %d\n",s1,slen(s1));

	printf("%s länge: %d\n",s2,slen(s2));
	reverse(s2);
	printf("%s länge: %d\n",s2,slen(s2));

	printf("\n PointerTest Ende \n");

}

void sort(int n, double* x){
	double temp;
	int count = 0;

	while(count < (n*n)){
		for(int i=0; i<n-1; i++){
			if(x[i] > x[i+1]){
				temp = x[i];
				x[i] = x[i+1];
				x[i+1] = temp;
			}
			count++;
		}
	}
}


void sortTest(){
	int i,n=7;
	double x[] = {3,2,4,1,5,7,6};

	printf("unsorted: ");
	for(i=0;i<n;i++){
		printf("%5.2f ",x[i]);
	}

	sort(n,x);

	printf("\n  sorted: ");
	for(i=0;i<n;i++){
		printf("%5.2f ",x[i]);
	}
}




#define dabs(x) (x)<0? -(x) : (x)

double iterate(double x_0, double eps, unsigned int nmax){
	double delta, x_k_1, x_k = x_0;
	unsigned int k=0;
	do{
		x_k_1 = x_k;

		x_k = x_k_1 - ((x_k_1 * x_k_1) - x_0) / (2 * x_k_1);

		delta = dabs(x_k - x_k_1);
	}while(delta > eps && ++k < nmax);
	if(k>=nmax)printf("no convergence");
	return x_k;
}





int main(){

	//pointerTest();
	//sortTest();
	printf("%.12f", iterate(5,0.000001,5000));
	return 0;
}
