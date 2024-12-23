#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signum) {
    // This function will be called when the signal is received
    if (signum == SIGUSR1) {
        printf("Child received signal from parent.\n");
    }
}

int main() {
    pid_t pid;

    // Create a signal handler for SIGUSR1
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        perror("Signal error");
        exit(EXIT_FAILURE);
    }

    pid = fork();  // Create a child process

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        printf("Child process started with PID %d\n", getpid());

        // Wait for the signal from the parent
        while (1) {
            // In a real application, we would do some work here
            pause();  // Wait for signals
        }
    } else {
        // Parent process
        printf("Parent process started with PID %d\n", getpid());

        // Give the child time to start
        sleep(1);

        // Send a SIGUSR1 signal to the child process
        if (kill(pid, SIGUSR1) == -1) {
            perror("Kill failed");
            exit(EXIT_FAILURE);
        }

        printf("Parent sent signal to child.\n");

        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}
