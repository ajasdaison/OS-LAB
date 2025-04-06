#include <stdio.h>

int main() {
  int n, m, i, j, k, y;
  int alloc[20][20], max[20][20], avail[20];
  int finish[20], safesequence[20], work[20], need[20][20];
  int ind = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("Enter the number of resources: ");
  scanf("%d", &m);

  printf("Enter the Allocation Matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &alloc[i][j]);
    }
  }

  printf("Enter the Max Matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &max[i][j]);
    }
  }

  printf("Enter the Available Resources:\n");
  for (i = 0; i < m; i++) {
    scanf("%d", &avail[i]);
    work[i] = avail[i]; // Initialize work = available
  }

  // Initialize Finish
  for (i = 0; i < n; i++) {
    finish[i] = 0;
  }

  // Calculate Need Matrix
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  printf("\nNEED Matrix is:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%d ", need[i][j]);
    }
    printf("\n");
  }

  // Banker's Algorithm logic
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      if (finish[i] == 0) {
        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > work[j]) {
            flag = 1;
            break;
          }
        }

        if (flag == 0) {
          safesequence[ind++] = i;
          for (y = 0; y < m; y++) {
            work[y] += alloc[i][y];
          }
          finish[i] = 1;
        }
      }
    }
  }

  // Check if all processes are finished
  int allFinished = 1;
  for (i = 0; i < n; i++) {
    if (finish[i] == 0) {
      allFinished = 0;
      break;
    }
  }

  if (allFinished) {
    printf("\nThe system is in a SAFE state.\nSafe sequence is: ");
    for (i = 0; i < n; i++) {
      printf("P%d ", safesequence[i]);
    }
    printf("\n");
  } else {
    printf("\nThe system is NOT in a safe state.\n");
  }

  return 0;
}
