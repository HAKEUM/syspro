#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
	int fd;

	if ((fd = open("testFile", O_RDWR|O_CREAT,0600)) == -1)
		printf("File Open Error\n");
	else printf("file %s Open Sucess : %d\n", argv[1],fd);

	close(fd);
	exit(0);
}
