#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("Recv: [%d] Hello from PID %d\n", getpid(), getppid());
    } else {
        printf("Send: [%d] Hello from PID %d\n", getpid(), pid);
    }

    return 0;
}

