#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_BUFFERS 5
int buffer_available = NUM_BUFFERS;

void* worker(void* arg) {
    int id = (int)(long)arg;

    if (buffer_available > 0) {

        sleep(3);

        buffer_available--;   // ❌ Not protected! RACE CONDITION

        printf("Thread %d got a buffer! Remaining=%d\n", id, buffer_available);

        sleep(1);

        buffer_available++;   // ❌ Also unsafe

        printf("Thread %d returned buffer. Remaining=%d\n", id, buffer_available);

    } else {

        printf("Thread %d: NO buffer available!\n", id);
        
    }

    return NULL;
}

int main() {
    pthread_t t[10];

    for (int i = 0; i < 10; i++)
        pthread_create(&t[i], NULL, worker, (void*)(long)i);

    for (int i = 0; i < 10; i++)
        pthread_join(t[i], NULL);

    return 0;
}
