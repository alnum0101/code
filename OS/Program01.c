#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <unistd.h>

int main() {

 pid_t child_pid;

 // Fork a child process

 child_pid = fork();

 if (child_pid == -1) {

 // Fork failed

 perror("Fork failed");

 exit(EXIT_FAILURE);

 }

 if (child_pid == 0) {

 // This is the child process

 printf("Child process: PID = %d\n", getpid());

 // Execute a new program in the child process

 execlp("/bin/ls", "ls", "-l", (char *)NULL);

 // If exec fails

 perror("Exec failed");

 exit(EXIT_FAILURE);
} else {

 // This is the parent process

 printf("Parent process: PID = %d\n", getpid());

 // Wait for the child process to finish

 wait(NULL);

 printf("Child process terminated\n");

 }

 return 0;

}
