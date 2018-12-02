/*
 * main.c
 *
 *  Created on: 01.12.2018
 *      Author: gi-user
 */

#include <math.h>
#include "textplott.h"

double poly(double x){
	return 2*(x+1)*(x-0.75)*(x-1.5);
}

double sinc(double x){
	if(x != 0){
		return sin(x)/x;
	}
	return 1;
}

int main(){
	Function f;
	clearPlotter();
	setPlotArea(-1.0,-5,2.0,7);
	//calcdY(TRUE);

	f = poly;
	addFunction(f);

	/*
	f = sinc;
	addFunction(f);
	*/

	showPlotter();
	return 0;
}
