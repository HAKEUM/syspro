#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main() {
	int pid1,pid2,pid3;
	pid1 = fork();
	if(pid1 == 0) {
		printf("Hello\n");
		pid2 = fork();
		if(pid2 == 0) {
			printf("Hello\n");
			exit(0);
		}
		exit(1);
	}
	pid3 == fork();
	if(pid3 == 0) {
		printf("Hello\n");
		exit(2);
	}
	printf("Hello\n");
	return 0;
}	
