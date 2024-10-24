#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX_LINES 100
#define LINE_LENGTH 256

int main(int argc,char *argv[]) {
    int fd;
	int j=0;
    char buf;
    char saveTexted[MAX_LINES][LINE_LENGTH];
    int count = 0;
    int charIndex = 0;
	
	if (argc == 2) {
		fd = open(argv[1],O_RDONLY);
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
		for (int i=0;i<2;i++) {
			printf("%s\n",saveTexted[i]);
		}
	}
}
