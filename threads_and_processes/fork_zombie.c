#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    char *message;
    int n;

    printf("Fork sample program started\n");
    pid = fork();
    switch (pid)
    {
    case -1:
        perror("Fork failed");
        exit(1);
    case 0:
        message = "This is the child process\n";
        n = 3;
        break;
    default:
        message = "This is the parent process\n";
        n = 5;
        break;
    }

    for (; n > 0; n--)
    {
        printf("%s", message);
        sleep(1);
    }
    exit(0);
}
