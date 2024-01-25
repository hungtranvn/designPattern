#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define BUFFER_SIZE 1024

int pipefds[2];
int status, pid;
char writemsg[BUFFER_SIZE];
char readmsg[BUFFER_SIZE];

void pipeOperation() {
    pid = fork();
    if (pid == 0) {
        read(pipefds[0], readmsg, sizeof(readmsg));
        printf("Child process: Reading from pipe - %s", readmsg);
    } else {
        printf("Parent process: Write data - %s", writemsg);
        write(pipefds[1], writemsg, sizeof(writemsg));
    }
}

int main() {
    status = pipe(pipefds);
    if (status == -1) {
        printf("Unable to create pipe\n");
        return 1;
    }

    printf("Enter msg to write into pipe:\n");
    printf("To exit type \"quit\" \n");
    fgets(writemsg, BUFSIZ, stdin);
    while (strcmp(writemsg, "quit\n") != 0) {
        pipeOperation();
        fgets(writemsg, BUFSIZ, stdin);
        kill(pid, SIGKILL);
    }
    
    return 0;
}