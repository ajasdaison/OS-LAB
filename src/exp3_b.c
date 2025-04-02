/**
 * @file exp3_b.c
 * @brief Program to retrieve and display file information using `stat()`.
 *
 * This program checks for the existence of "hello.txt" and displays its
 * metadata, including file mode, owner user ID, and size. If the file does not
 * exist, it prints an error message and skips further execution.
 *
 * @author Ajas Daison
 * @date April 2, 2025
 */

#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief Main function to retrieve and display file information.
 *
 * The program attempts to get metadata of "hello.txt" using `stat()`. If the
 * file does not exist, it prints an error message and exits without failure.
 *
 * @return Returns 0 on successful execution.
 */
int main() {
  struct stat sfile;

  // Attempt to get file information
  if (stat("hello.txt", &sfile) == -1) {
    perror("stat"); ///< Print system-generated error message
    printf("File does not exist. Skipping...\n");
    return 0; // Do not exit with error
  }

  // Print file information
  printf("\nst_mode = %o\n", sfile.st_mode);  ///< Print file mode in octal
  printf("File st_uid = %d\n", sfile.st_uid); ///< Print user ID of owner
  printf("File st_size = %lld bytes\n",
         (long long)sfile.st_size); ///< Print file size

  return 0;
}

/**
 * @example Sample Output:
 *
 * If hello.txt exists:
 * @code
 * st_mode = 100644
 * File st_uid = 1000
 * File st_size = 512 bytes
 * @endcode
 *
 * If hello.txt does not exist:
 * @code
 * stat: No such file or directory
 * File does not exist. Skipping...
 * @endcode
 */
