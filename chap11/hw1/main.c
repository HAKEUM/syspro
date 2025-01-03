#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void alarmHandler(int signo) {
    printf("Wake up\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    sa.sa_handler = alarmHandler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    alarm(5);

    short i = 0;
    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

