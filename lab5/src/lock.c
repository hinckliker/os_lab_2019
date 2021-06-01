#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t lock1, lock2;

void *proccess1(){

      pthread_mutex_lock(&lock1);
      printf("Начало работы poccess1\n");
      sleep(2);

      printf("Попытка захватить ресурсы proccess2\n");
      pthread_mutex_lock(&lock2);
      printf("Захват ресурсов proccess2\n");
      pthread_mutex_unlock(&lock2);

      printf("Окончание работы proccess1\n");

      pthread_mutex_unlock(&lock1);

      pthread_exit(NULL);

}

void *proccess2(){

      pthread_mutex_lock(&lock2);

      printf("Начало работы proccess2\n");
      sleep(2);

      printf("Попытка захватить ресурсы proccess1\n");
      pthread_mutex_lock(&lock1);
      printf("Захват ресурсов proccess1\n");
      pthread_mutex_unlock(&lock1);

      printf("Окончание работы proccess2..\n");

      pthread_mutex_unlock(&lock2);

      pthread_exit(NULL);

}

int main() {

      pthread_mutex_init(&lock1,NULL);
      pthread_mutex_init(&lock2,NULL);

      pthread_t t1,t2;

      pthread_create(&t1,NULL,proccess1,NULL);
      pthread_create(&t2,NULL,proccess2,NULL);

      pthread_join(t1,NULL);
      pthread_join(t2,NULL);

      return 0;

}