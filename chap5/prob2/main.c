#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	char buffer[BUFSIZE];
	int fd;
	ssize_t nread;
	long total = 0;

	if ((fd = open("test", O_RDONLY|O_CREAT,0600))==-1)
		perror("File Open Error!\n");

	while((nread = read(fd, buffer, BUFSIZE))>0)
		total += nread;

	close(fd);
	printf("%s File size : %ld Byte \n", "test",total);
	exit(0);
}
