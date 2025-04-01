#include <stdio.h>
#include <sys/stat.h>

int main() {
  struct stat sfile;

  // Attempt to get file information
  if (stat("hello.txt", &sfile) == -1) {
    perror("stat");
    return 1; // Exit with an error code
  }

  printf("\nst_mode = %o\n", sfile.st_mode);  // Print file mode in octal
  printf("File st_uid = %d\n", sfile.st_uid); // Print user ID of owner
  printf("File st_size = %lld bytes\n",
         (long long)sfile.st_size); // Print file size in bytes

  return 0;
}

/*OUTPUT:
If hello.txt exists:

st_mode = 100644
File st_uid = 1000
File st_size = 512 bytes

If hello.txt does not exist:

stat: No such file or directory
*/
