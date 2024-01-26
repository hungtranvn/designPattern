#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// global variables
int pipefds[2];
int status;
char writemessage[BUFFER_SIZE];
char readmessage[BUFFER_SIZE];

void pipeOperation() {
    printf("Writing to pip - Message is %s", writemessage);
    write(pipefds[1], writemessage, sizeof(writemessage));
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pip - Message is %s", readmessage);
}

int main() {
    status = pipe(pipefds);
    if (status == -1) {
        printf("Unable to create pip\n");
        return 1;
    }

    printf("Enter the message to write into Pipe\n");
    printf("To exit type \"quit\" \n");
    fgets(writemessage, BUFFER_SIZE, stdin);
    while(strcmp(writemessage, "quit\n") != 0) {
        pipeOperation();
        fgets(writemessage, BUFFER_SIZE, stdin);
    }
    
    close(pipefds[0]);
    close(pipefds[1]);
    return 0;
}