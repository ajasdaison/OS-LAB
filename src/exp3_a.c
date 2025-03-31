#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;
  // Create a child process
  pid = fork();

  if (pid < 0) {
    // Check if fork failed
    printf("fork failed\n");
    // if error occurs
    exit(1);
  } else if (pid == 0) {
    // Child process
    execlp("/bin/date", "date",
           NULL); // Replace child process with 'date' command
    exit(0);
  } else { // Parent process
    printf("Parent Process id is - %d\n Child Process id is - %d\n", getpid(),
           pid);
    wait(NULL); // Wait for child process to complete
    exit(0);
  }

  return 0;
}

/* OUTPUT:
 Parent Process id is - 1939
 Child Process id is - 1943
 Mon Mar 31 17:56:26 IST 2025
*/
