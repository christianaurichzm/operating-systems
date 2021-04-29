#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{

    /* List of arguments for the process to be loaded */
    /* [0]: program name, [1]: arguments */
    char *const ps_argv[] = {"echo", "hello world 3 and 4", 0};

    /* Exec system calls */
    execl("/bin/echo", "echo", "hello world", 0);

    /* Assuming echo is in /bin */
    execlp("echo", "echo", "hello world 2", 0);

    /* Assuming echo is in /bin */
    execv("/bin/echo", ps_argv);

    /* Assuming /bin is in PATH */
    execvp("echo", ps_argv);

    exit(0);
}
