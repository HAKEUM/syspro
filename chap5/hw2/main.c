#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE 100
int main() {
	char buf;
	int fd;
	char saveTexted[MAX_LINE][100];
	int count = 0;
	int charIndex = 0;

	fd = open("test.txt",O_RDONLY);
	if (fd<0) {
		perror("File Error");
		return 1;
	}

	while(read(fd, &buf, 1) > 0) {
		if(buf == '\n') {
			saveTexted[count][charIndex] = '\0';
			count++;
			charIndex = 0;
		} else {
			saveTexted[count][charIndex++] = buf;
		}
	}
	close(fd);

	int line = count-1;
	for(int i=0;i<count;i++) {
		printf("%s\n",saveTexted[line]);
		line--;
	}
	return 0;
}
