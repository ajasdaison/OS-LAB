#include <stdio.h>
#include <stdlib.h>

int main() {
  int queue[20], n, head, i, j, seek = 0, diff;
  float avg;

  printf("Enter the number of disk requests: ");
  scanf("%d", &n);

  printf("Enter the disk request queue:\n");
  for (i = 1; i <= n; i++) {
    scanf("%d", &queue[i]);
  }

  printf("Enter the initial head position: ");
  scanf("%d", &head);

  queue[0] = head;

  for (j = 0; j < n; j++) {
    diff = abs(queue[j + 1] - queue[j]);
    seek += diff;
    printf("Disk head moves from %d to %d with seek %d\n", queue[j],
           queue[j + 1], diff);
  }

  printf("Total seek time = %d\n", seek);
  avg = seek / (float)n;
  printf("Average seek time = %.2f\n", avg);

  return 0;
}
