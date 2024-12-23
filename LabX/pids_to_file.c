#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    pid_t pid;

    // Open the file in append mode, or create it if it doesn't exist
    file = fopen("pids.txt", "a");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    // Fork the process to create a child
    pid = fork();

    if (pid < 0) {
        // Error in fork
        perror("Fork failed");
        fclose(file);
        exit(1);
    }

    if (pid == 0) {
        // Child process writes its PID
        fprintf(file, "Child process PID: %d\n", getpid());
        printf("Child process PID: %d\n", getpid());
    } else {
        // Parent process writes its PID
        fprintf(file, "Parent process PID: %d\n", getpid());
        printf("Parent process PID: %d\n", getpid());
    }

    // Close the file
    fclose(file);

    return 0;
}
