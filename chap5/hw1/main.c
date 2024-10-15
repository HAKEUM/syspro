#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

int main() {
	int fd;
	char buf;
	char saveTexted[MAX_LINES][LINE_LENGTH];
	int count = 0;
	int charIndex = 0;

	fd = open("test.txt",O_RDONLY);
	if (fd < 0) {
		perror("File Error");
		return 1;
	}
	while(count<MAX_LINES && read(fd, &buf, 1) > 0) {
		if(buf == '\n') {
			saveTexted[count][charIndex] = '\0';
			count++;
			charIndex = 0;
		} else {
			saveTexted[count][charIndex++] = buf;
		}
	}
	close(fd);
	printf("Total Line : %d\n",count);
	printf("You can choose 1 ~ %d Line\n",count);

	char input[100];
	printf("Pls 'Enter' the line to select : ");
	fgets(input, sizeof(input), stdin);

	if(strcmp(input, "*\n") == 0) {
		for (int i = 0; i<count; i++) {

			printf("%s\n",saveTexted[i]);
		}
	} else {
		int n,m;
		if(sscanf(input, "%d-%d", &n,&m) == 2) {
			for(int i = n-1; i < m && i < count; i++) {
				printf("%s\n",saveTexted[i]);
			}
		} else {
			char *token = strtok(input, ",\n");
			int lineNumbers[MAX_LINES];
			int numCount = 0;

			while(token != NULL) {
				if(sscanf(token, "%d", &n) == 1 && n > 0 && n <= count) {
					lineNumbers[numCount++] = n - 1;
				}
				token = strtok(NULL, ",\n");
			}

			for (int i = 0; i< numCount; i++) {
				printf("%s\n",saveTexted[lineNumbers[i]]);
			}
		}
	}
	return 0;
}
