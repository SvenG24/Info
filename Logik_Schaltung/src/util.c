/*
 * util.c
 *
 *  Created on: 24.11.2018
 *      Author: gi-user
 */

int slen(char s[]) {
	int length = 0;
	if(s) {
		while(s[length]){
			length++;
		}
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

