#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex;
sem_t full;
sem_t empty;

pthread_t prod, cons;

void *producer(void *arg) {
  int item;
  while (1) {
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
}

void *consumer(void *arg) {
  int item;
  while (1) {
    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[out];
    printf("\nConsumer consumed: %d from index %d", item, out);
    out = (out + 1) % BUFFER_SIZE;

    sem_post(&mutex);
    sem_post(&empty);

    sleep(1);
  }
}

int main() {
  int choice;

  if (sem_init(&mutex, 0, 1) == -1 || sem_init(&full, 0, 0) == -1 ||
      sem_init(&empty, 0, BUFFER_SIZE) == -1) {
    perror("Semaphore initialization failed");
    exit(1);
  }

  while (1) {
    printf("\n\n1. Start Producer\n2. Start Consumer\n3. Start Both Producer "
           "and Consumer\n4. Exit\nEnter your choice: ");

    if (scanf("%d", &choice) != 1) { // Validate input
      while (getchar() != '\n')
        ; // Clear buffer
      printf("Invalid input! Exiting...\n");
      exit(1);
    }

    switch (choice) {
    case 1:
      pthread_create(&prod, NULL, producer, NULL);
      printf("Producer started...\n");
      break;
    case 2:
      pthread_create(&cons, NULL, consumer, NULL);
      printf("Consumer started...\n");
      break;
    case 3:
      pthread_create(&prod, NULL, producer, NULL);
      pthread_create(&cons, NULL, consumer, NULL);
      printf("Producer and Consumer started...\n");
      pthread_join(prod, NULL); // Wait for both to finish
      pthread_join(cons, NULL);
      break;
    case 4:
      printf("Exiting program...\n");
      sem_destroy(&mutex);
      sem_destroy(&full);
      sem_destroy(&empty);
      exit(0);
    default:
      printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
    }
  }

  return 0;
}
