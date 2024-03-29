#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);

char message[] = "Hello world!";

int main()
{
    int res;
    pthread_t a_thread;
    void *thread_result;
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message);
    if (res != 0)
    {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0)
    {
        perror("Thread failed to join");
        exit(EXIT_FAILURE);
    }
    printf("Thread joined, retornou %s\n", (char *)thread_result);
    printf("The message is now %s\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    printf("thread_function running. The argument was %s\n", (char *)arg);
    sleep(3);
    strcpy(message, "Goodbye!");
    pthread_exit("Thanks for the CPU time");
}
