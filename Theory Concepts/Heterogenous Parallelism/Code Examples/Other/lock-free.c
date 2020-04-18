#include<stdio.h>
#include<pthread.h>

int counter = 0;
int sync = 1;

void update1()
{
    while(sync == 0)
        ;
    sync = 0;
    counter++;
    printf("%d\n", counter);
    sync = 1;
}

void update2()
{
    while(sync == 0)
        ;
    sync = 0;
    counter*=6;
    printf("%d\n", counter);
    sync = 1;
}

int main() 
{
    pthread_t pid1, pid2;
    pthread_create(&pid1, NULL, &update1, NULL);
    pthread_create(&pid2, NULL, &update2, NULL);
    pthread_join(&pid1, NULL);
    pthread_join(&pid2, NULL);
    pthread_exit(NULL);
    return 0;
}