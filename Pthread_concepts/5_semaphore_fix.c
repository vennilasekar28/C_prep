#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define NUM_BUFFERS 5

int buffer_available = NUM_BUFFERS;   // shared resource count
sem_t sem;                            // semaphore

void* worker(void* arg) {
    int id = (int)(long)arg;

    // All threads reach here at the same time
    usleep(1000);

    // Take a resource (blocks if no buffer available)
    sem_wait(&sem);

    // -----------------------------
    // CRITICAL REGION: buffer use
    // -----------------------------
   // printf("Thread %d sees buffer_available=%d\n", id, buffer_available);

    buffer_available--;   // allocate buffer
    printf("Thread %d took a buffer. Remaining=%d\n", id, buffer_available);

    sleep(1);             // simulate using the buffer

    buffer_available++;   // free the buffer
    printf("Thread %d returned buffer. Remaining=%d\n", id, buffer_available);
    // -----------------------------

    // return the token
    sem_post(&sem);

    return NULL;
}

int main() {
    pthread_t t[10];

    // Initialize semaphore to NUM_BUFFERS
    sem_init(&sem, 0, NUM_BUFFERS);

    for (int i = 0; i < 10; i++)
        pthread_create(&t[i], NULL, worker, (void*)(long)i);

    for (int i = 0; i < 10; i++)
        pthread_join(t[i], NULL);

    sem_destroy(&sem);

    return 0;
}
