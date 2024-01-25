#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define FIFO_FILE "FIFO"
int file_descriptor;
char message_buffer[1024];
char message_end[5]; 
int read_beffer_bytes;
int end_process;

void sendData() {
    while(1) {
        printf("Enter msg to send:\n");
        fgets(message_buffer, sizeof(message_buffer), stdin);
        int stringlen = strlen(message_buffer);
        message_buffer[stringlen-1] = '\0';
        
        if (strcmp(message_buffer, "end") == 0) {
            printf("FIFO done!\n");
            close(file_descriptor);
            exit(1);
        } else {
            write(file_descriptor, message_buffer, strlen(message_buffer));
            printf("Send msg: %s\n", message_buffer);
        }
    }
}

int main() {
    file_descriptor = open(FIFO_FILE, O_CREAT|O_WRONLY);
    sendData();
    return 0;
}