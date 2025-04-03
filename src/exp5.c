#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3 // Buffer size

int buffer[BUFFER_SIZE]; // Shared buffer
int in = 0, out = 0;     // Buffer indices for producer and consumer

sem_t mutex; // Binary semaphore for mutual exclusion
sem_t full;  // Counting semaphore for full slots
sem_t empty; // Counting semaphore for empty slots

pthread_t prod, cons; // Thread variables

// Producer function
void *producer(void *arg) {
  int item;

  while (1) {
    item = rand() % 100; // Generate a random item
    sem_wait(&empty);    // Wait if buffer is full
    sem_wait(&mutex);    // Lock critical section

    buffer[in] = item; // Add item to buffer
    printf("\nProducer produced: %d at index %d", item, in);
    in = (in + 1) % BUFFER_SIZE; // Circular buffer

    sem_post(&mutex); // Unlock critical section
    sem_post(&full);  // Signal that a slot is full

    sleep(1); // Simulate delay
  }
}

// Consumer function
void *consumer(void *arg) {
  int item;

  while (1) {
    sem_wait(&full);  // Wait if buffer is empty
    sem_wait(&mutex); // Lock critical section

    item = buffer[out]; // Consume item
    printf("\nConsumer consumed: %d from index %d", item, out);
    out = (out + 1) % BUFFER_SIZE; // Circular buffer

    sem_post(&mutex); // Unlock critical section
    sem_post(&empty); // Signal that a slot is empty

    sleep(1); // Simulate delay
  }
}

// Main function with a switch statement
int main() {
  int choice;

  // Initialize semaphores
  sem_init(&mutex, 0, 1);           // Binary semaphore (1 = available)
  sem_init(&full, 0, 0);            // Initially, buffer is empty (full = 0)
  sem_init(&empty, 0, BUFFER_SIZE); // Initially, all slots are empty

  while (1) {
    // Display menu options
    printf("\n\n1. Start Producer\n2. Start Consumer\n3. Start Both Producer "
           "and Consumer\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // Start only the producer thread
      pthread_create(&prod, NULL, producer, NULL);
      printf("Producer started...\n");
      break;

    case 2:
      // Start only the consumer thread
      pthread_create(&cons, NULL, consumer, NULL);
      printf("Consumer started...\n");
      break;

    case 3:
      // Start both producer and consumer threads
      pthread_create(&prod, NULL, producer, NULL);
      pthread_create(&cons, NULL, consumer, NULL);
      printf("Producer and Consumer started...\n");
      pthread_join(prod, NULL);
      pthread_join(cons, NULL);
      break;

    case 4:
      printf("Exiting program...\n");
      exit(0);

    default:
      printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
    }
  }

  return 0;
}
