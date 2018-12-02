/*
 * textplott.h
 *
 *  Created on: 01.12.2018
 *      Author: gi-user
 */

#ifndef TEXTPLOTT_H_
#define TEXTPLOTT_H_

#define ROWS 25
#define COLS 80

double x_min,x_max,y_min,y_max,x_res,y_res,x_mid,y_mid;
char pic[ROWS][COLS];

typedef enum {FALSE,TRUE} BOOLEAN;

typedef double (*Function)(double);
/** add a function to plot 			*/
void addFunction(Function f);

/** initialize the plotter			*/
void clearPlotter();
/** print plotter array to stdout	*/
void showPlotter();
/** set the plot area coordinates	*/
void setPlotArea(float x0,float y0, float x1, float y1);
/** plot char at coordinate (x,y).	*/
void plot(float x, float y, char c);
/** utility method to draw x,y axes	*/
void plot_Axes();

#endif /* TEXTPLOTT_H_ */
