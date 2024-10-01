#include <stdio.h>
#include "copy.h"
#include <string.h>

char line[5][MAXLINE];
char longest[MAXLINE];

int main() {
	int i, j=0;

	for(i=0; i<5; i++){
		scanf("%s", line[i]);
	}

	for(i=1; i<=4; i++){
		for(j=0;j<5-i; j++){
			if(strlen(line[j])<strlen(line[j+1])){
				strcpy(longest, line[j+1]);
				strcpy(line[j+1], line[j]);
				strcpy(line[j], longest);
			}
		}
	}

	for(i=0; i<5; i++){
		printf("%s\n", line[i]);
	}
	return 0;
}


