#include <stdio.h>

int main() {
  int i, j, n, t, max;
  int bu[10], wa[10], tat[10], ct[10];
  float awt = 0, att = 0, temp = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter Burst Time for Process %d: ", i + 1);
    scanf("%d", &bu[i]);
    ct[i] = bu[i]; // Keep original burst time
  }

  printf("Enter the size of time slice: ");
  scanf("%d", &t);

  // Find the maximum burst time to estimate rounds
  max = bu[0];
  for (i = 1; i < n; i++) {
    if (max < bu[i])
      max = bu[i];
  }

  // Start Round Robin scheduling
  while (1) {
    int done = 1; // Flag to check if all processes are done

    for (i = 0; i < n; i++) {
      if (bu[i] > 0) {
        done = 0; // There's at least one process left

        if (bu[i] > t) {
          temp += t;
          bu[i] -= t;
        } else {
          temp += bu[i];
          tat[i] = temp; // Completion time
          bu[i] = 0;
        }
      }
    }

    if (done == 1)
      break;
  }

  // Calculate Waiting Time and Averages
  for (i = 0; i < n; i++) {
    wa[i] = tat[i] - ct[i];
    awt += wa[i];
    att += tat[i];
  }

  // Print the result
  printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
  for (i = 0; i < n; i++) {
    printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
  }

  printf("\nAverage Waiting Time = %.2f", awt / n);
  printf("\nAverage Turnaround Time = %.2f\n", att / n);

  return 0;
}
