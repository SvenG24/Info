/*
 * main.c
 *
 *  Created on: 08.11.2018
 *      Author: gi-user
 */
#include <stdio.h>


int slen(char s[]) {
	int length = 0;
	if(s) {
		while(s[length]){
			length++;
		}
	}
	return length;
}


int len(char s[]) {
	int length = 0;
	if(s) {
		do {
			if(s[length] != 0){
				length++;
			}
		} while(s[length]);
	}
	return length;
}


void reverse(char str[]) {

	int i=0,x=slen(str);

	char start[x+1];
	for(x--;x >= 0;x--){
		start[i] = str[x];
		i++;
	}
	start[i++] = 0;
	for(i=0;str[i]!= '\0';i++){
		str[i] = start[i];
	}
}



int kgV(int a, int b){
	int m=0, rest = 1;
	while(rest != 0){
		m++;
		rest = (m*a)%b;
	}
	return (m*a);
}

int ggT(int a, int b){
	int m,n;
	m = kgV(a,b);
	n = (a*b)/ m;
	return n;
}


char LT[] = "is less";
char GT[] = "is greater";
char EQ[] = "equals";
char UNKOWN[] = "ERROR";


void whatswrong(double x, double y, char temp[]){
	//char *result;

	if(x>y){
		temp = &LT[0];
	} else if(x<y) {
		temp = &GT[0];
	}else if(x==y){
		temp = &EQ[0];
	}else{
		temp = &UNKOWN[0];
	}
	/*
	switch(x,y){
	case x>y:
		result = LT;
		break;
	case x<y:
		result = GT;
		break;
	case x==y:
		result = EQ;
		break;
	default:
		result = UNKOWN;
	}*/
	return;
}








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
	int* p;
	p = &i;
	printf(" p = %p -- &p = %p -- *p = %d -- i = %d -- i_adr = %p \n\n\n\n\n",p,&p,*p,i,&i);



	char str[] = "";
	printf("Länge mit while:    %d\n",slen(str));
	printf("Länge mit do-while: %d\n\n",len(str));

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



	char *result;

	whatswrong(3,5,result);
	printf("%s",result);


	return 0;
}

