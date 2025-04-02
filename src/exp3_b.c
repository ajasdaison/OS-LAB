/**
 * @file exp3_b.c
 * @brief Demonstrates the use of `stat()` system call to retrieve file information.
 *
 * This program uses the `stat()` system call to obtain information about a file named
 * `hello.txt`. If the file exists, it displays details such as:
 * - File mode (permissions) in octal format.
 * - User ID of the file owner.
 * - File size in bytes.
 *
 * If the file does not exist, an error message is printed using `perror()`.
 *
 * @author Ajas Daison
 * @date 2025
 */

#include <stdio.h>
#include <sys/stat.h>

/**
 * @brief Retrieves and prints file information using `stat()`.
 *
 * The function attempts to retrieve file metadata for `hello.txt` using the `stat()`
 * system call. If successful, it prints:
 * - `st_mode` (file mode/permissions) in octal.
 * - `st_uid` (user ID of the file owner).
 * - `st_size` (file size in bytes).
 *
 * If `stat()` fails (e.g., the file does not exist), an error message is displayed.
 *
 * @return int Returns 0 on success, 1 if `stat()` fails.
 */
int main() {
  struct stat sfile; /**< Structure to store file information */

  // Attempt to get file information
  if (stat("hello.txt", &sfile) == -1) {
    perror("stat"); // Print error message if file does not exist
    return 1;       // Exit with an error code
  }

  printf("\nst_mode = %o\n", sfile.st_mode);  /**< Print file mode in octal */
  printf("File st_uid = %d\n", sfile.st_uid); /**< Print user ID of owner */
  printf("File st_size = %lld bytes\n",
         (long long)sfile.st_size); /**< Print file size in bytes */

  return 0;
}

/**
 * @example Example Output:
 * If `hello.txt` exists:
 * @code
 * st_mode = 100644
 * File st_uid = 1000
 * File st_size = 512 bytes
 * @endcode
 *
 * If `hello.txt` does not exist:
 * @code
 * stat: No such file or directory
 * @endcode
 */

