 
#include<pthread.h>

pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond3 = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock3 = PTHREAD_MUTEX_INITIALIZER;

int TRUE = 1;

void print(char *p)
{
  printf("%s",p);
}

void * threadMethod1(void *arg)
{
  printf("In thread1\n");
  do{
    pthread_mutex_lock(&lock1);
    //Add your business logic(parallel execution codes)  here
    pthread_cond_wait(&cond1, &lock1);
    printf("I am thread1  generating the final report and inserting into a table \n");
    pthread_cond_signal(&cond3);/* Now allow 3rd thread to process */
    pthread_mutex_unlock(&lock1);
  }while(TRUE);
  pthread_exit(NULL);
}

void * threadMethod2(void *arg)
{
  printf("In thread2\n");
  do
  {
    pthread_mutex_lock(&lock2);
    //Add your business logic(parallel execution codes)  here
    pthread_cond_wait(&cond2, &lock2);
    printf("I am thread3  generating the final report and inserting into a table \n");
    pthread_cond_signal(&cond1);
    pthread_mutex_unlock(&lock2);
  }while(TRUE);
  pthread_exit(NULL);
}

void * threadMethod3(void *arg)
{
  printf("In thread3\n");
  do
  {
    pthread_mutex_lock(&lock3);
    //Add your business logic(parallel execution codes)  here
    pthread_cond_wait(&cond3, &lock3);
    printf("I am thread2  generating the final report and inserting into a table \n");
    pthread_cond_signal(&cond2);
    pthread_mutex_unlock(&lock3);
  }while(TRUE);
  pthread_exit(NULL);
}

int main(void)
{
  pthread_t tid1, tid2, tid3;
  int i = 0;

  printf("Before creating the threads\n");
  if( pthread_create(&tid1, NULL, threadMethod1, NULL) != 0 )
        printf("Failed to create thread1\n");
  if( pthread_create(&tid2, NULL, threadMethod2, NULL) != 0 )
        printf("Failed to create thread2\n");
  if( pthread_create(&tid3, NULL, threadMethod3, NULL) != 0 )
        printf("Failed to create thread3\n");
  pthread_cond_signal(&cond1);/* Now allow first thread to process first */


  sleep(1);
  TRUE = 0;/* Stop all the thread */
  sleep(3);
 
 /* this is how we join thread before exit from a system */
  /*  
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);*/

 exit(0);
}