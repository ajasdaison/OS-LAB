/**
 * @file exp3_c.c
 * @brief Demonstrates directory handling using `opendir()`, `readdir()`, and `closedir()`.
 *
 * This program prompts the user to enter a directory name and attempts to open it.
 * If successful, it lists the contents of the specified directory. If the directory
 * does not exist or cannot be opened, an error message is displayed.
 *
 * @author Ajas Daison
 * @date 2025
 */

#include <dirent.h> // For directory handling functions (opendir, readdir, closedir)
#include <stdio.h>  // For printf, scanf, perror
#include <stdlib.h> // For exit codes

/**
 * @brief Reads a directory name from the user and displays its contents.
 *
 * This function performs the following steps:
 * - Prompts the user for a directory name.
 * - Attempts to open the directory using `opendir()`.
 * - If successful, reads and prints the directory contents using `readdir()`.
 * - If unsuccessful, prints an error message using `perror()`.
 * - Closes the directory stream before exiting.
 *
 * @return int Returns 0 on success, 1 if an error occurs.
 */
int main() {
  char buff[256];      /**< Buffer to store user-input directory name */
  DIR *dirp;           /**< Pointer to directory stream */
  struct dirent *dptr; /**< Pointer to directory entry structure */

  // Prompt user for directory name
  printf("Enter directory name: ");

  // Read directory name from user, ensuring safe input handling
  if (scanf("%255s", buff) != 1) {
    printf("Invalid input\n");
    return 1; // Exit with error if input fails
  }

  // Attempt to open the specified directory
  if ((dirp = opendir(buff)) == NULL) {
    perror("opendir"); // Print system-generated error message if opening fails
    return 1;          // Exit with error
  }

  // Print directory contents
  printf("Contents of directory %s:\n", buff);
  while ((dptr = readdir(dirp)) != NULL) { // Read each directory entry
    printf("%s\n", dptr->d_name);          // Print file/directory name
  }

  // Close the directory stream after use
  closedir(dirp);

  return 0; // Exit successfully
}

/**
 * @example Example Output:
 * If the directory exists and contains files:
 * @code
 * Enter directory name: testdir
 * Contents of directory testdir:
 * .
 * ..
 * file1.txt
 * file2.c
 * folder1
 * @endcode
 *
 * If the directory does not exist:
 * @code
 * Enter directory name: non_existent_dir
 * opendir: No such file or directory
 * @endcode
 */

