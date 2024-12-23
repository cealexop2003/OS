#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // First fork
    pid = fork();
    if (pid == 0) {
        // Child process
        printf("Fork 1 - Child process PID: %d\n", getpid());
    } else {
        // Parent process
        printf("Fork 1 - Parent process PID: %d\n", getpid());
        
        // Second fork
        pid = fork();
        if (pid == 0) {
            // Child process
            printf("Fork 2 - Child process PID: %d\n", getpid());
        } else {
            // Parent process
            printf("Fork 2 - Parent process PID: %d\n", getpid());

            // Third fork
            pid = fork();
            if (pid == 0) {
                // Child process
                printf("Fork 3 - Child process PID: %d\n", getpid());
            } else {
                // Parent process
                printf("Fork 3 - Parent process PID: %d\n", getpid());
            }
        }
    }

    return 0;
}
