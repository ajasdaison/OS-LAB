/**
 * @file exp4_shr_reader.c
 * @brief Shared Memory Reader Program
 *
 * This program demonstrates Inter-Process Communication (IPC) using shared
 * memory. It attaches to an existing shared memory segment, reads the stored
 * data, and then detaches from the shared memory before exiting. Optionally, it
 * can remove the shared memory segment after reading.
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
 * @brief Main function to read from shared memory.
 *
 * This function performs the following steps:
 * - Attaches to an existing shared memory segment with key `1222`.
 * - Reads and displays the stored data.
 * - Detaches from the shared memory.
 * - Optionally removes the shared memory segment after reading.
 *
 * @return int Returns 0 on success, exits with error code 1 on failure.
 */
int main() {
  void *shared_memory; /**< Pointer to the shared memory segment */
  int shmid;           /**< Shared memory segment ID */

  // Get the shared memory segment created by the writer
  shmid = shmget((key_t)1222, 1024, 0666);
  if (shmid == -1) {
    perror("shmget failed");
    exit(1);
  }

  printf("Shared Memory ID: %d\n", shmid);

  // Attach the shared memory segment
  shared_memory = shmat(shmid, NULL, 0);
  if (shared_memory == (void *)-1) {
    perror("shmat failed");
    exit(1);
  }

  printf("Process attached at address: %p\n", shared_memory);
  printf("Data read from shared memory: %s\n", (char *)shared_memory);

  // Detach shared memory
  shmdt(shared_memory);

  // Remove shared memory after reading (optional)
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}

/**
 * @example Example Usage:
 * @code
 * $ gcc exp4_shr_reader.c -o exp4_shr_reader
 * $ ./exp4_shr_reader
 * Shared Memory ID: 12345
 * Process attached at address: 0x7f8a4b600000
 * Data read from shared memory: Hello, Shared Memory!
 * @endcode
 *
 * @note This program should be used alongside the `exp4_shr_writer.c` program
 * to write data into shared memory before reading.
 */
