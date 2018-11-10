/*
 * main.c
 *
 *  Created on: 08.11.2018
 *      Author: gi-user
 */
#include <stdio.h>

int main() {
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
	char* p;
	p = &i;
	printf(" p = %p -- &p = %p -- *p = %d -- i = %d -- i_adr = %p",p,&p,*p,i,&i);

	return 0;
}

