/*
 * Bessel.c
 *
 *  Created on: 10.01.2019
 *      Author: gi-user
 */
double j0(double x){
	return 0;
}
double j1(double x){
	return 0;
}

double jn(int n, double x){
	if(n == 0){
		return j0(x);
	}
	else if(n == 1){
		return j1(x);
	}
	else if(n > 2){
		return ((2*n)/x) * jn(n-1,x) - jn(n-2,x);
	}
	return 0;
}
