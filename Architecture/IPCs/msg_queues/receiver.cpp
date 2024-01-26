#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISSIONS 0777

struct messageBuffer {
    long mtype;
    char data[1024];
};

struct messageBuffer object;

int msqid;
int string_status;
key_t key;

void receiveMessage() {
    while (1) {
        if (msgrcv(msqid, &object, sizeof(object.data), 0, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("received: \"%s\"\n", object.data);
        
        if (strcmp(object.data, "end") == 0) {
            break;
        }
    }
}

int main() {
    // create the unique Indentifier for the msg queue
    if ((key = ftok("messagequeue.txt", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, PERMISSIONS)) == -1) {
        printf("Unable to create the msg queue.\n");
        perror("msgget");
        exit(1);
    }

    printf("Message queue is ready to receive msg.\n");
    receiveMessage();
    printf("Msg queue is done with receiving message.\n");
    return 0;
}
