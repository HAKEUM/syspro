#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
	FILE *fd;
	struct student record;
	if (argc <2) {
		fprintf(stderr,"How to use: %s file\n", argv[0]);
		exit(1);
	}
	if((fd = fopen(argv[1],"w"))==NULL){
		perror(argv[1]);
		exit(2);
	}
	printf("%-9s %-8s %-4s\n", "StuID","Name","Score");
	while (scanf("%d %s %d", &record.id, record.name, &record.score) == 3) {
		lseek(fd, (record.id-START_ID)*sizeof(record),SEEK_SET);
		fprintf(fd, "%d %s %d\n",record.id, record.name , record.score);
	}
	close(fd);
	exit(0);
}
