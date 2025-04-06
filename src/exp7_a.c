#include <stdio.h>

int main() {
  int i, j, n, m;
  int ps[100], bs[150];
  int allocated[100] = {0}; // 0 = not allocated, 1 = allocated

  printf("Enter the number of blocks: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter the size of block %d: ", i + 1);
    scanf("%d", &bs[i]);
  }

  printf("Enter the number of processes: ");
  scanf("%d", &m);

  for (i = 0; i < m; i++) {
    printf("Enter the size of process %d: ", i + 1);
    scanf("%d", &ps[i]);
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if (ps[i] <= bs[j]) {
        printf("Process %d is allocated to block of size %d\n", i + 1, bs[j]);
        allocated[i] = 1;
        bs[j] = -1; // Mark block as used
        break;
      }
    }
  }

  for (i = 0; i < m; i++) {
    if (!allocated[i]) {
      printf("Process %d is not allocated\n", i + 1);
    }
  }

  return 0;
}
