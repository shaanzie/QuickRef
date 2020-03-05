# Pthreads

A thread is a lightweight process. A pthread is a posix thread library, which is a standard. Pthreads allows functions to implement parallelism.

This is done to make programs more responsive, using multi-threaded control.

The functions offered and that are commonly used are
1. Pthread_ - General Pthread
2. Pthread_attr_ - Thread attributes
3. Pthread_mutex_ - Mutex
4. Pthread_mutexattr - Mutex attributes
5. Pthread_cond_ - Conditional variables
6. Pthread_condaddr - Conditional variable attributes
7. Pthread_key_ - Thread specific data keys

## Thread management routines

1. Creation       = pthread_create
2. Termination    = pthread_exit, return
3. Wait           = pthread_join
4. Pthread header = <pthread.h>
5. Compilation    = -lpthread

Detached threads can detach child processes from parent processes, to make them independent.
```
pthread_detach(pthread_t tid)
```
Thread synchronization can be achieved using mutexes or condition variables such as wait() and signal().

