#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_BUF 100

int main() {
    int pipefd[2];
    pid_t pid1, pid2;
    char buffer[MAX_BUF];

    if (pipe(pipefd) == -1) {
        perror("pipe failed");
        return 1;
    }
	printf("parent process start\n");

    pid1 = fork();
    if (pid1 == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) { 
        printf("input string: ");
        fgets(buffer, MAX_BUF, stdin);

        close(pipefd[0]);
        write(pipefd[1], buffer, strlen(buffer) + 1);
        close(pipefd[1]); 
        return 0;
    }

    pid2 = fork();
    if (pid2 == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) { 
        close(pipefd[1]);
        read(pipefd[0], buffer, MAX_BUF);
        close(pipefd[0]);

        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = toupper((unsigned char)buffer[i]);
        }
		printf("%s",buffer);

        return 0;
    }

    close(pipefd[0]); 
    close(pipefd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}

