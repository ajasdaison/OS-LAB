#include <stdio.h>
#include <stdlib.h>

int main() {
  int t[100], atr[100], d[100], h, i, j, n, temp, k, tot, p = 0, sum = 0;

  printf("Enter the number of requests: ");
  scanf("%d", &n);

  printf("Enter the initial position of head: ");
  scanf("%d", &h);

  printf("Enter total number of tracks (disk size): ");
  scanf("%d", &tot);

  // Set up track array
  t[0] = 0;       // Beginning
  t[1] = h;       // Head
  t[2] = tot - 1; // End of disk

  printf("Enter the requested tracks:\n");
  for (i = 3; i < n + 3; i++) {
    scanf("%d", &t[i]);
  }

  int size = n + 3;

  // Sort track list
  for (i = 0; i < size; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (t[j] > t[j + 1]) {
        temp = t[j];
        t[j] = t[j + 1];
        t[j + 1] = temp;
      }
    }
  }

  // Find head index
  for (i = 0; i < size; i++) {
    if (t[i] == h) {
      j = i;
      break;
    }
  }

  // Move from head to end
  for (i = j; i < size; i++) {
    atr[p++] = t[i];
  }

  // Then from beginning up to before head
  for (i = 0; i < j; i++) {
    atr[p++] = t[i];
  }

  // Calculate differences and total seek
  printf("\nTrack Traversal\tSeek Difference\n");
  for (i = 0; i < p - 1; i++) {
    d[i] = abs(atr[i + 1] - atr[i]);
    printf("%d --> %d\t\t%d\n", atr[i], atr[i + 1], d[i]);
    sum += d[i];
  }

  printf("%d\n", atr[p - 1]);

  printf("\nTotal Head Movement: %d\n", sum);
  printf("Average Head Movement: %.2f\n", (float)sum / n);

  return 0;
}
