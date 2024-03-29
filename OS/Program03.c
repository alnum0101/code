#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

sem_t empty, full;
pthread_mutex_t mutex;

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void *producer(void *arg) {
    int item;

    for (int i = 0; i < BUFFER_SIZE * 2; i++) {
        item = rand() % 100; // Produce a random item

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Critical Section: Add item to the buffer
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        // Simulate some work in between producing items
        usleep(100000);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;

    for (int i = 0; i < BUFFER_SIZE * 2; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Critical Section: Consume item from the buffer
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        // Simulate some work in between consuming items
        usleep(150000);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
