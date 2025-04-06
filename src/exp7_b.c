#include <stdio.h>

int main() {
  int i, j, mem[30], n, pro[30], m, temp, k, avail[30] = {0}, t;

  printf("Enter the number of memory partitions: ");
  scanf("%d", &n);

  printf("Enter the sizes of memory partitions:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &mem[i]);
  }

  printf("Enter the number of processes: ");
  scanf("%d", &m);

  printf("Enter the sizes of processes:\n");
  for (j = 0; j < m; j++) {
    scanf("%d", &pro[j]);
  }

  // Sort memory in descending order (for Worst Fit)
  for (i = 0; i < n - 1; i++) {
    t = i;
    for (j = i + 1; j < n; j++) {
      if (mem[t] < mem[j]) {
        temp = mem[j];
        mem[j] = mem[t];
        mem[t] = temp;
      }
    }
  }

  // Allocate each process
  for (i = 0; i < m; i++) {
    int allocated = 0;
    for (j = 0; j < n; j++) {
      if (pro[i] <= mem[j]) {
        printf("Process %dK is placed in memory block %dK\n", pro[i], mem[j]);
        mem[j] = 0;        // Mark block as used
        avail[i] = pro[i]; // Mark process as allocated
        allocated = 1;
        break;
      }
    }
    if (!allocated) {
      printf("Process %dK cannot be placed\n", pro[i]);
    }
  }

  return 0;
}
