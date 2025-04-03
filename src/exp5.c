/**
 * @file exp5.c
 * @brief Implementation of the Producer-Consumer Problem using Semaphores.
 *
 * This program demonstrates process synchronization using semaphores to
 * implement the producer-consumer problem. It ensures mutual exclusion using a
 * binary semaphore and maintains buffer state with counting semaphores.
 *
 * @author Ajas Daison
 * @date 2025
 */

#include <stdio.h>
#include <stdlib.h>

int mutex = 1; /**< Binary semaphore for mutual exclusion */
int full = 0;  /**< Counting semaphore for full buffer slots */
int empty = 3; /**< Counting semaphore for empty buffer slots */
int x = 0;     /**< Shared buffer item count */

/**
 * @brief Simulates the "Wait" operation on a semaphore.
 *
 * Decrements the semaphore value, blocking if the value is non-positive.
 *
 * @param S Pointer to the semaphore variable.
 * @return Updated semaphore value after decrementing.
 */
int wait(int *S) {
  while (*S <= 0)
    ; /**< Busy waiting if S <= 0 */
  return --(*S);
}

/**
 * @brief Simulates the "Signal" operation on a semaphore.
 *
 * Increments the semaphore value, signaling resource availability.
 *
 * @param S Pointer to the semaphore variable.
 * @return Updated semaphore value after incrementing.
 */
int sem_signal(int *S) { return ++(*S); }

/**
 * @brief Producer function.
 *
 * Produces an item and adds it to the buffer if space is available.
 * Utilizes semaphores to ensure mutual exclusion and maintain buffer states.
 */
void producer() {
  mutex = wait(&mutex);     /**< Lock the mutex */
  full = sem_signal(&full); /**< Increase full buffer count */
  empty = wait(&empty);     /**< Decrease empty buffer count */
  x++;                      /**< Produce an item */

  printf("\nProducer produces item %d", x);

  mutex = sem_signal(&mutex); /**< Unlock the mutex */
}

/**
 * @brief Consumer function.
 *
 * Consumes an item from the buffer if available.
 * Uses semaphores to ensure mutual exclusion and proper buffer management.
 */
void consumer() {
  mutex = wait(&mutex);       /**< Lock the mutex */
  full = wait(&full);         /**< Decrease full buffer count */
  empty = sem_signal(&empty); /**< Increase empty buffer count */

  printf("\nConsumer consumes item %d", x);
  x--; /**< Consume an item */

  mutex = sem_signal(&mutex); /**< Unlock the mutex */
}

/**
 * @brief Main function for the Producer-Consumer simulation.
 *
 * Provides a menu-driven interface to allow the user to act as a producer or
 * consumer.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
  int n;

  printf("\n1. Producer\n2. Consumer\n3. Exit");

  while (1) {
    printf("\nEnter your choice: ");
    if (scanf("%d", &n) != 1) {
      printf("\nInvalid input! Exiting...\n");
      break;
    }

    switch (n) {
    case 1:
      if ((mutex == 1) && (empty != 0))
        producer();
      else
        printf("\nBuffer is full!!");
      break;

    case 2:
      if ((mutex == 1) && (full != 0))
        consumer();
      else
        printf("\nBuffer is empty!!");
      break;

    case 3:
      exit(0);

    default:
      printf("\nInvalid choice! Exiting...\n");
      return 0;
    }
  }

  return 0;
}
