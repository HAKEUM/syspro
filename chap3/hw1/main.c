#include <stdio.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];

main(){
	int len;
	int max;
	max = 0;
	int count = 0;

	while(gets(line) != NULL) {
		len = strlen(line);
		if(len > max) {
			max = len;
			copy(line, longest);
		}
  1 #include <stdio.h>
  2 #include "copy.h"
  3
  4 char line[MAXLINE];
  5 char longest[MAXLINE];
  6
  7 main(){
  8     int len;
  9     int max;
 10     max = 0;
 11     int count = 0;
 12
 13     while(gets(line) != NULL) {
 14         len = strlen(line);
 15         if(len > max) {
 16             max = len;
 17             copy(line, longest);
 18         }
 19     }
 20     return 0;
	}
	return 0;
