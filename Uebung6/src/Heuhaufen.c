/*
 * Heuhaufen.c
 *
 *  Created on: 10.01.2019
 *      Author: gi-user
 */
#include <string.h>
#include <stdio.h>

int strsearch(char *heystack, char *needle){
	int x = 0,i,k = 0;

	for(i=0;heystack[i] != 0;i++){
		if(heystack[i] == needle[k]){
			x = i+1;
			k++;
			i++;
			for(;heystack[i] != 0 && needle[k] != 0;i++){
				if(heystack[i] == needle[k]){
					k++;
				}
				else{
					break;
				}
			}
			if(needle[k] == 0){
				return x;
			}
		}
		else{
			k = 0;
			x = -1;
		}
	}
	return x;
}






int strsearch_(char *heystack, char *needle){
	int x = 0,i;

	for(i=0;heystack[i] != 0;i++){
		if(strncmp(heystack+i,needle,strlen(needle)) == 0){
			return i+1;
		}
		else{
			x = -1;
		}
	}
	return x;
}













