#include <stdio.h>

int main() {
  int p[20], bt[20], pri[20], wt[20], tat[20];
  int i, k, n, temp;
  float wtavg = 0, tatavg = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Taking burst time and priority input
  for (i = 0; i < n; i++) {
    p[i] = i;
    printf("Enter the Burst Time and Priority for Process %d: ", i);
    scanf("%d %d", &bt[i], &pri[i]);
  }

  // Sort processes based on priority (lower number = higher priority)
  for (i = 0; i < n; i++) {
    for (k = i + 1; k < n; k++) {
      if (pri[i] > pri[k]) {
        // Swap priorities
        temp = pri[i];
        pri[i] = pri[k];
        pri[k] = temp;

        // Swap burst times
        temp = bt[i];
        bt[i] = bt[k];
        bt[k] = temp;

        // Swap process IDs
        temp = p[i];
        p[i] = p[k];
        p[k] = temp;
      }
    }
  }

  // Calculate Waiting Time and Turnaround Time
  wt[0] = 0;
  tat[0] = bt[0];
  wtavg = 0;
  tatavg = tat[0];

  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }

  // Display the results
  printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
  }

  printf("\nAverage Waiting Time: %.2f", wtavg / n);
  printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

  return 0;
}
