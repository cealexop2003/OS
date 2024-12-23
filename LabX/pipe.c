#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PIPE_READ 0
#define PIPE_WRITE 1

int main() {
    int pipefds[2];  // Array to hold the read and write file descriptors for the pipe
    pid_t pid;
    char message[] = "Hello from Parent!";
    char buffer[100];

    // Create a pipe
    if (pipe(pipefds) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork to create a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        close(pipefds[PIPE_WRITE]);  // Close the write end of the pipe in the child

        // Read the message from the pipe
        read(pipefds[PIPE_READ], buffer, sizeof(buffer));
        printf("Child received message: %s\n", buffer);

        close(pipefds[PIPE_READ]);  // Close the read end of the pipe in the child
    } else {
        // Parent process
        close(pipefds[PIPE_READ]);  // Close the read end of the pipe in the parent

        // Write the message to the pipe
        write(pipefds[PIPE_WRITE], message, strlen(message) + 1);  // +1 for the null terminator
        printf("Parent sent message: %s\n", message);

        close(pipefds[PIPE_WRITE]);  // Close the write end of the pipe in the parent

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}
