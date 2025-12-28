#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define NUM_BUFFERS  (5)

int buffer_available = NUM_BUFFERS;

sem_t token;

void *worker(void *arg){

    int id;
    id = (int)(long)arg;

    usleep(1000);

    sem_wait(&token);

    buffer_available--;

    printf("The thread id %d took the buffer, Remaining = %d\n",id,buffer_available);

    sem_post(&token);

    buffer_available++;

    printf("The thread id %d released the buffer, Remaining = %d\n",id,buffer_available);

    return NULL;
}

int main (){

    pthread_t thread1[10];

    sem_init(&token, 0, NUM_BUFFERS);

    for(int i=0; i<10; i++){

        pthread_create(&thread1[i],NULL,worker,&i);
    }

    for(int i=0; i<10; i++){

        pthread_join(thread1[i],NULL);
    }

    return 0;
}