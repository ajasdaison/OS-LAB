/**
 * @file shared_writer.c
 * @brief Shared Memory Writer Program
 *
 * This program demonstrates Inter-Process Communication (IPC) using shared
 * memory. It creates a shared memory segment, writes user-provided data into
 * it, and then detaches the shared memory before exiting.
 *
 * @author Ajas Daison
 * @date 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

/**
 * @brief Main function to create and write to shared memory.
 *
 * This function performs the following steps:
 * - Creates a shared memory segment with key `1222`.
 * - Attaches the segment to the process's address space.
 * - Reads input from the user using `fgets()` and stores it in shared memory.
 * - Prints the shared memory address and content.
 * - Detaches the shared memory before exiting.
 *
 * @return int Returns 0 on success, exits with error code 1 on failure.
 */
int main() {
  void *shared_memory; /**< Pointer to the shared memory segment */
  char buffer[100] = {
      0};    /**< Buffer initialized to prevent uninitialized memory issues */
  int shmid; /**< Shared memory segment ID */

  // Create a shared memory segment with key 1222 and size 1024 bytes
  shmid = shmget((key_t)1222, 1024, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  printf("Shared Memory ID: %d\n", shmid);

  // Attach shared memory to process address space
  shared_memory = shmat(shmid, NULL, 0);
  if (shared_memory == (void *)-1) {
    perror("shmat failed");
    exit(1);
  }

  printf("Process attached at address: %p\n", shared_memory);
  printf("Enter some data to write to shared memory: \n");

  // Read input from user using fgets to avoid buffer overflow
  if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
    perror("Error reading input");
    shmdt(shared_memory);
    exit(1);
  }

  // Copy input to shared memory
  strncpy((char *)shared_memory, buffer, 100);

  printf("Data written to shared memory: %s\n", (char *)shared_memory);

  // Detach shared memory
  shmdt(shared_memory);

  return 0;
}

/**
 * @example Example Usage:
 * @code
 * $ gcc shared_writer.c -o shared_writer
 * $ ./shared_writer
 * Shared Memory ID: 12345
 * Process attached at address: 0x7f8a4b600000
 * Enter some data to write to shared memory:
 * Hello, Shared Memory!
 * Data written to shared memory: Hello, Shared Memory!
 * @endcode
 *
 * @note This program should be used alongside a corresponding reader program
 * to read the shared memory content.
 */
