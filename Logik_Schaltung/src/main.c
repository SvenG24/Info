/*
 * main.c
 *
 *  Created on: 08.11.2018
 *      Author: gi-user
 */
#include <stdio.h>
#include "util.h"



char LT[] = "is less";
char GT[] = "is greater";
char EQ[] = "equals";
char UNKOWN[] = "ERROR";
char *result;


void whatswrong(double x, double y){


	if(x>y){
		result = &LT[0];
	} else if(x<y) {
		result = &GT[0];
	}else if(x==y){
		result = &EQ[0];
	}else{
		result = &UNKOWN[0];
	}

	return;
}








int main() {

	whatswrong(2.0,3.0);
	printf("%s\n",result);


	int a,b,c,x,y,z;

	printf(" a | b | c |  | x | y | z\n");
	printf("--------------------------\n");

	for(a=0;a<=1;a++){
		for(b=0;b<=1;b++){
			for(c=0;c<=1;c++){

				//Normal
				x = ((a&&b) || (!a&&!b))&&(c||a);

				//NAND
				y = !(!(!a&&!b&&c)&&!(a&&b));

				//NOR
				z = !(!(!(!a||!b)||!(a||b))||!(c||a));

				printf(" %i | %i | %i |  | %i | %i | %i\n",a,b,c,x,y,z);

			}
		}
	}




	int i = 24;
	int* p;
	p = &i;
	printf(" p = %p -- &p = %p -- *p = %d -- i = %d -- i_adr = %p \n\n\n\n\n",p,&p,*p,i,&i);



	char str[] = "";
	printf("Länge mit while:    %d\n",slen(str));
	//printf("Länge mit do-while: %d\n\n",len(str));

	printf("Vorher:  %s\n",str);
	reverse(str);
	printf("Nachher: %s\n\n",str);


	/**
	 * kgV und ggT
	 */
	int g = 4;
	int h = 8;
	printf("kgV von %d und %d ist %d\n",g,h,kgV(g,h));
	printf("ggT von %d und %d ist %d\n",g,h,ggT(g,h));


	char test[] = "hallo";
	char *result = &test[0];

	//whatswrong(3,5,result);
	printf("%s",result);

	printf("\n %d", kgV(0,5));
	return 0;
}

