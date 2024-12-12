#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int pid;
void sigint_handler(int signo);


int main(void)
{
	if(pid==0) {
		while(1 ) {
			signal(SIGINT,sigint_handler);
			printf("process [1] Execution\n");
			sleep(1);
		}
	} else {
		printf("parent killed\n");
}
}
void sigint_handler(int signo)
{
      printf("Interrupt to child\n");
	  printf("child killed\n");
	  printf("parent killed\n");
	  exit(0);
}

