#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PERMISSIONS 0777

struct messageBuffer {
    long messageType;
    char data[1024];
};

struct messageBuffer object;

int msqid;
int len;
int string_status;
key_t key;

void sendMessage() {
    while(fgets(object.data, sizeof(object.data), stdin) != NULL) {
        len = strlen(object.data);
        if (object.data[len-1] == '\n') object.data[len-1] = '\0';
        // Msg is not sent successful, throw an error and exit
        if (msgsnd(msqid, &object, len+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        // Checking exit status
        string_status = strcmp(object.data, "end");
        if (string_status == 0) break;
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    printf("Msg queue is done with sending msg.\n");
}

int main() {
    system("touch messagequeue.txt");
    if ((key = ftok("messagequeue.txt", 'B')) == -1) {
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, PERMISSIONS | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    printf("Msg queue is ready to send msg. \n");
    printf("Enter lines of text, enter \'end\' to quit:\n");
    object.messageType = 1;
    sendMessage();
    system("rm messagequeue.txt");
    return 0;
}
