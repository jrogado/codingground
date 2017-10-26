#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    pid_t  pid;

    printf("argc = %d\n", argc);

    if (argc == 1) {
        printf("Usage: fork <args>\n");
        exit(1);
    }
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        execvp(argv[1], &argv[1]);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
		printf("Child process %d exit\n", pid);
        exit(0);
    }
    exit(0);
}