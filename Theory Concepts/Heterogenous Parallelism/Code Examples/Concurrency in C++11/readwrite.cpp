#include<bits/stdc++.h>

using namespace std;

#define NUMBER_OF_READERS 10
#define NUMBER_OF_WRITERS 2

int read_count = 0;
mutex read_write_mutex, lock_mutex;

void *reader(void* pid) {

    lock_mutex.lock();
    read_count++;
    if (read_count == 1) {
        read_write_mutex.lock();
    }
    lock_mutex.unlock();

    printf("Reader %d\n", pid);
    printf("Reader %d exiting\n", pid);

    lock_mutex.lock();
    read_count--;
    if (read_count == 0) {
        read_write_mutex.unlock();
    }
    lock_mutex.unlock();

    pthread_exit(NULL);
}

void *writer(void* pid) {

    printf("Writer %d waiting\n", pid);

    read_write_mutex.lock();

    printf("Writer %d update\n", pid);
    printf("Writer %d exiting\n", pid);

    read_write_mutex.unlock();
    pthread_exit(NULL);

}

int main() {

    pthread_t readers[NUMBER_OF_READERS], writers[NUMBER_OF_WRITERS];
    
    for (int i = 0, j = 0; i < NUMBER_OF_READERS; i++) {
        pthread_create(&readers[i], NULL, reader, &i);
        pthread_detach(readers[i]);

        if (i % 5 == 0) {
            pthread_create(&writers[j], NULL, writer, &j);
            pthread_detach(writers[j++]);
        }
    }
    pthread_exit(0);
}