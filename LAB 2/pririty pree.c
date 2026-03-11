#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0;
    int bt[10], rt[10], pr[10], wt[10], tat[10];
    int min_pr, highest;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Enter Priority: ");
        scanf("%d", &pr[i]);

        rt[i] = bt[i];
    }

    while(completed != n) {
        highest = -1;
        min_pr = 999;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0 && pr[i] < min_pr) {
                min_pr = pr[i];
                highest = i;
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) {
            completed++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];

            avg_wt += wt[highest];
            avg_tat += tat[highest];
        }
    }

    printf("\nPID\tBT\tPR\tWT\tTAT\n");

    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
