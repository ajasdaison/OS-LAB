#include <stdio.h>

int main() {
  int bt[20], wt[20], tat[20], i, n;
  float wtavg = 0, tatavg = 0;

  printf("\nEnter the number of processes: ");
  scanf("%d", &n);

  // Get burst times
  for (i = 0; i < n; i++) {
    printf("Enter Burst Time for Process %d: ", i);
    scanf("%d", &bt[i]);
  }

  // Calculate waiting time
  wt[0] = 0;
  for (i = 1; i < n; i++) {
    wt[i] = wt[i - 1] + bt[i - 1]; // waiting time = sum of previous burst times
    wtavg += wt[i];
  }

  // Calculate turnaround time
  for (i = 0; i < n; i++) {
    tat[i] = wt[i] + bt[i];
    tatavg += tat[i];
  }

  // Display results
  printf("\nPROCESS||\tBURST TIME||\tWAITING TIME||\tTURNAROUND TIME\n");
  for (i = 0; i < n; i++) {
    printf("P%d||\t\t%d||\t\t%d||\t\t%d\n", i, bt[i], wt[i], tat[i]);
  }

  // Average results
  printf("\nAverage Waiting Time: %.2f", wtavg / n);
  printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

  return 0;
}
