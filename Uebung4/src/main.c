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

void nullstelle(){
	double a, e,dif, x_0=0, x_n=0;
	/* f(x) = x² - a)
	 * f'(x) = 2x
	 */
	e = 0.001;
	dif = e;
	a = 2.236067977;
	x_0 = a;

	while(dif >= e){
		x_n = x_0 - ((x_0*x_0 - a)/(2*x_0));
		dif = x_n - x_0;
		x_0 = x_n;
		if(dif < 0){dif *= (-1);}
	}
	printf("Nullstelle ist %5.2f",x_n);
}

int main(){

	//pointerTest();
	//sortTest();
	nullstelle();

	return 0;
}
