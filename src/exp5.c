#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3
#define ITERATIONS 5 // Number of items to produce/consume

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex;
sem_t full;
sem_t empty;

pthread_t prod, cons;

void *producer() {
  int item;
  for (int i = 0; i < ITERATIONS; i++) {
    item = rand() % 100;
    sem_wait(&empty);
    sem_wait(&mutex);

    buffer[in] = item;
    printf("\nProducer produced: %d at index %d", item, in);
    in = (in + 1) % BUFFER_SIZE;

    sem_post(&mutex);
    sem_post(&full);

    sleep(1);
  }
  printf("\nProducer finished execution.\n");
  pthread_exit(NULL);
}

void *consumer() {
  int item;
  for (int i = 0; i < ITERATIONS; i++) {
    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[out];
    printf("\nConsumer consumed: %d from index %d", item, out);
    out = (out + 1) % BUFFER_SIZE;

    sem_post(&mutex);
    sem_post(&empty);

    sleep(1);
  }
  printf("\nConsumer finished execution.\n");
  pthread_exit(NULL);
}

int main() {

  // Initialize unnamed semaphores
  sem_init(&mutex, 0, 1);
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);

  // Start Producer and Consumer
  pthread_create(&prod, NULL, producer, NULL);
  pthread_create(&cons, NULL, consumer, NULL);
  pthread_join(prod, NULL);
  pthread_join(cons, NULL);

  // Cleanup and Exit
  printf("\nExecution completed. Exiting program...\n");
  sem_destroy(&mutex);
  sem_destroy(&full);
  sem_destroy(&empty);

  return 0;
}
