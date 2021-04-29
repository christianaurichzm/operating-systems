#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;
    int exit_code;

    printf("Fork sample program started\n");
    pid = fork();
    switch (pid)
    {
    case -1:
        exit(1);
    case 0:
        message = "This is the child process\n";
        n = 5;
        exit_code = 37;
        break;
    default:
        message = "This is the parent process\n";
        n = 3;
        exit_code = 0;
        break;
    }

    for (; n > 0; n--)
    {
        printf("%s", message);
        sleep(1);
    }

    /*  The program waits for the child process to finish  */

    // If different from zero, that is, parent process
    if (pid)
    {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child finished: PID = %d\n", child_pid);
        if (WIFEXITED(stat_val))
            printf("Child leaves with code %d\n", WEXITSTATUS(stat_val));

        else
            printf("The child process ended abnormally\n");
    }
    exit(exit_code);
}
