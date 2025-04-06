#include <stdio.h>
#include <stdlib.h>

int main() {
  int t[20], d[20], h, i, j, n, temp, k, atr[20], p = 0, sum = 0;

  printf("Enter the number of tracks to be traversed: ");
  scanf("%d", &n);

  printf("Enter the initial position of head: ");
  scanf("%d", &h);

  t[0] = 0; // Start of the disk
  t[1] = h;

  printf("Enter the track numbers:\n");
  for (i = 2; i < n + 2; i++) {
    scanf("%d", &t[i]);
  }

  // Sort all tracks
  for (i = 0; i < n + 2; i++) {
    for (j = 0; j < n + 2 - i - 1; j++) {
      if (t[j] > t[j + 1]) {
        temp = t[j];
        t[j] = t[j + 1];
        t[j + 1] = temp;
      }
    }
  }

  // Find index of head
  for (i = 0; i < n + 2; i++) {
    if (t[i] == h) {
      j = i;
      k = i;
      break;
    }
  }

  // Move from head to 0 (left)
  while (t[j] != 0) {
    atr[p++] = t[j--];
  }
  atr[p++] = t[j]; // add 0

  // Move from head to right end
  for (i = k + 1; i < n + 2; i++) {
    atr[p++] = t[i];
  }

  printf("\nTrack Traversal and Seek Differences:\n");
  printf("Track\t\tSeek\n");

  for (j = 0; j < n + 1; j++) {
    d[j] = abs(atr[j + 1] - atr[j]);
    sum += d[j];
    printf("%d\t\t%d\n", atr[j], d[j]);
  }

  printf("%d\n", atr[j]);
  printf("\nTotal Head Movement: %d\n", sum);
  printf("Average Head Movement: %.2f\n", (float)sum / n);

  return 0;
}
