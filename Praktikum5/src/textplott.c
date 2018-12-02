/*
 * textplott.c
 *
 *  Created on: 01.12.2018
 *      Author: gi-user
 */
#include <stdio.h>
#include "textplott.h"

void addFunction(Function f){
	int i;
	double x, y, temp;

	for(i=0; i<COLS; i++){
		x = (i / x_res) + x_min;
		y = f(x);
		temp = (-y+y_max) * y_res;
		if(temp < 0 || i < 0){
			printf("Außerhalb des Bereiches\n");
			return;
		}
		pic[(int)temp][i] = '*';
	}
}

void clearPlotter(){
	int i, j;

	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			pic[i][j] = ' ';
		}
	}
}

void showPlotter(){
	int i,j;

	for(i=0; i<ROWS; i++){
		for(j=0; j<COLS; j++){
			printf("%c",pic[i][j]);
		}
		printf("\n");
	}
}

void setPlotArea(float x0,float y0, float x1, float y1){
	x_min = x0;
	x_max = x1;
	y_min = y0;
	y_max = y1;

	x_res = COLS / (x_max - x_min);
	y_res = ROWS / (y_max - y_min);

	x_mid = (0 - x_min) * x_res;
	y_mid = (0 + y_max) * y_res;

	plot_Axes();
}

void plot(float x, float y, char c){
	pic[(int)(x_mid + (x/x_res))][(int)(y_mid - (y/y_res))] = c;

	//showPlotter();
}

void plot_Axes(){
	int i;
	double temp;


	pic[0][(int)x_mid] = '^';
	for(i=1; i<ROWS; i++){
		if((i % (int)y_res) == 0){
			pic[i][(int)x_mid] = '+';
			temp = -(i/y_res) + y_max;
			if(temp < 0){
				temp = temp * (-1) + 1;
				pic[i][(int)x_mid-2] = '-';
				pic[i][(int)x_mid-1] = temp + '0';
			}else {
				pic[i][(int)x_mid-2] = '+';
				pic[i][(int)x_mid-1] = temp + '0';
			}
		}else {
			pic[i][(int)x_mid] = '|';
		}
	}


	for(i=0; i<COLS-1; i++){
		if((i % (int)x_res) == 0){
			pic[(int)y_mid][i] = '+';
			temp = -(i/x_res) - x_min;
			if(temp >= 1  || temp < 0){
				if(temp < 0){
					temp = temp * (-1) + 1;
					pic[(int)y_mid+1][i-1] = '+';
					pic[(int)y_mid+1][i] = temp + '0';
				}else {
					pic[(int)y_mid+1][i-1] = '-';
					pic[(int)y_mid+1][i] = temp + '0';
				}
			}
		}else {
			pic[(int)y_mid][i] = '-';
		}
	}
	pic[(int)y_mid][i++] = '>';
}





