#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "myfifo"

void writerProcess() {
    int fd;

    // Create the FIFO (named pipe)
    mkfifo(FIFO_NAME, 0666);

    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);

    if (fd == -1) {
        perror("Error opening FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Write data to the FIFO
    char message[] = "Hello, reader!";
    write(fd, message, strlen(message) + 1);

    // Close the FIFO
    close(fd);
}

void readerProcess() {
    int fd;
    char buffer[100];

    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);

    if (fd == -1) {
        perror("Error opening FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the FIFO
    read(fd, buffer, sizeof(buffer));

    // Display the read data
    printf("Message from writer: %s\n", buffer);

    // Close the FIFO
    close(fd);
}

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // This is the writer process
        writerProcess();
    } else {
        // This is the reader process
        readerProcess();
    }

    return 0;
}
