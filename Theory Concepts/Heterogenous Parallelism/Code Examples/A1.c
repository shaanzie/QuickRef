#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conditional = PTHREAD_COND_INITIALIZER;
int balance = -213413;
int increment = 200;
struct inc_balance{
    int* balance;
    int increment;
    int id;
};

void* f1(void* balance1){
    balance = 0;
    printf("Thread-A set balance to %d\n",balance);fflush(stdout);
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&conditional);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* f2(void* data){
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&conditional,&mutex);
    //pthread_mutex_unlock(&mutex);
    struct inc_balance* temp = (struct inc_balance*)data;
    //*(temp->balance) += temp->increment;
    balance += increment;
    //printf("Thread-%d incremented balance from %d to %d\n",temp->id,*(temp->balance)-temp->increment,*(temp->balance));
    printf("Thread-%d incremented balance from %d to %d\n",temp->id,balance-increment,balance);
    
    fflush(stdout);
    //pthread_mutex_lock(&mutex);
    pthread_cond_signal(&conditional);
    pthread_mutex_unlock(&mutex);
    return NULL;
}


int main(int argc, char** argv){
    pthread_t t1;
    //int balance = -242424;
    pthread_create(&t1,NULL,f1,(void*)&balance);
    //pthread_join(t1,NULL);
    int num_incrementers = atoi(argv[1]);
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t)*num_incrementers);
    struct inc_balance* params = (struct inc_balance*)malloc(sizeof(struct inc_balance)*num_incrementers);

    for (int i = 0; i< num_incrementers; i++){
        //pthread_mutex_lock(&mutex);
        //pthread_cond_wait(&conditional,&mutex);
        //params[i].balance = &balance;
        //params[i].increment = 200;
        params[i].id = i;
        //pthread_cond_signal(&conditional);
        //pthread_mutex_unlock(&mutex);
        printf("Creating thread %d\n",i);fflush(stdout);
        pthread_create(&threads[i],NULL,f2,(void*)&params[i]);
        
    }
    
     for (int i = 0; i< num_incrementers; i++){
        pthread_join(threads[i],NULL);
     }
     pthread_join(t1,NULL);
     printf("Final Balance %d\n",balance);
    return 0;
}