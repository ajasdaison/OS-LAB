/**
 * @file exp3_a.c
 * @brief Demonstrates process creation using fork(), exec(), and wait() system
 * calls.
 *
 * This program creates a child process using `fork()`. The child process then
 * replaces itself with the `/bin/date` command using `execlp()`. The parent
 * process waits for the child process to complete using `wait()`. This
 * demonstrates process control in Unix-based operating systems.
 *
 * @author Ajas Daison
 * @date 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief Creates a child process that executes the `date` command.
 *
 * The function performs the following:
 * - Calls `fork()` to create a new child process.
 * - If `fork()` fails, it prints an error message and exits.
 * - If `fork()` succeeds, the child process executes the `date` command using
 * `execlp()`.
 * - The parent process prints its PID and the child's PID, then waits for the
 * child to finish.
 *
 * @return int Returns 0 upon successful execution.
 */
int main() {
  int pid; /**< Variable to store the process ID */

  // Create a child process
  pid = fork();

  if (pid < 0) {
    // Check if fork failed
    printf("fork failed\n");
    exit(1);
  } else if (pid == 0) {
    // Child process executes 'date' command
    execlp("/bin/date", "date", NULL);
    exit(0);
  } else {
    // Parent process prints PIDs and waits for child
    printf("Parent Process ID: %d\nChild Process ID: %d\n", getpid(), pid);
    wait(NULL); // Wait for the child process to complete
    exit(0);
  }

  return 0;
}

/**
 * @example Example Output:
 * @code
 * Parent Process ID: 1939
 * Child Process ID: 1943
 * Mon Mar 31 17:56:26 IST 2025
 * @endcode
 */
