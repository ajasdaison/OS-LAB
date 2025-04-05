#include <stdio.h>

int main() {
  int p[20], bt[20], wt[20], tat[20], i, j, n, temp;
  float wtavg = 0, tatavg = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Take burst time input and assign process IDs
  for (i = 0; i < n; i++) {
    p[i] = i;
    printf("Enter Burst Time for Process %d: ", i);
    scanf("%d", &bt[i]);
  }

  // Sort processes based on Burst Time (SJF logic)
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (bt[i] > bt[j]) {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }

  wt[0] = 0;
  tat[0] = bt[0];
  wtavg = 0;
  tatavg = tat[0];

  // Calculate Waiting Time and Turnaround Time
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1];
    tat[i] = wt[i] + bt[i];
    wtavg += wt[i];
    tatavg += tat[i];
  }

  // Output the results
  printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
  for (i = 0; i < n; i++) {
    printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }

  printf("\nAverage Waiting Time = %.2f", wtavg / n);
  printf("\nAverage Turnaround Time = %.2f\n", tatavg / n);

  return 0;
}
