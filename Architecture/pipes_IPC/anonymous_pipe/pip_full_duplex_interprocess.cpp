#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int pipefds1[2];
int pipefds2[2];
int status1, status2, pid;
char writemsg[BUFFER_SIZE];
char readmsg[BUFFER_SIZE];

void pipeOperation() {
    pid = fork();
    if (pid == 0) {
        read(pipefds1[0], readmsg, sizeof(readmsg));
        printf("Child process: Reading from pipe1 - %s", readmsg);
        printf("Child process: Writing to pipe2 - %s", writemsg);
        write(pipefds2[1], writemsg, sizeof(writemsg));
    } else {
        printf("Parent process: Writing to pipe1 - %s", writemsg);
        write(pipefds1[1], writemsg, sizeof(writemsg));
        read(pipefds2[0], readmsg, sizeof(readmsg));
        printf("Parent process: Reading from pipe2 - %s", readmsg);
    }
}

int main() {
    status1 = pipe(pipefds1);
    status2 = pipe(pipefds2);
    if (status1 == -1 || status2 == -1) {
        printf("Unable to create pipe\n");
        return 1;
    }

    printf("Entert msg to write into pipe:\n");
    printf("To exit type \"quit\" \n");
    fgets(writemsg, BUFSIZ, stdin);
    while (strcmp(writemsg, "quit\n") != 0) {
        pipeOperation();
        fgets(writemsg, BUFSIZ, stdin);
        kill(pid, SIGKILL);
    }

    return 0;
}