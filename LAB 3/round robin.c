#include <stdio.h>

int main() {
    int n, i, time = 0, remain, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n], waiting[n], turnaround[n];

    for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    remain = n;


    while(remain > 0) {
        for(i = 0; i < n; i++) {
            if(remaining[i] > 0) {
                if(remaining[i] <= quantum) {
                    time += remaining[i];
                    remaining[i] = 0;
                    turnaround[i] = time;
                    waiting[i] = turnaround[i] - burst[i];
                    remain--;
                } else {
                    remaining[i] -= quantum;
                    time += quantum;
                }
            }
        }
    }


    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], turnaround[i], waiting[i]);
        total_wt += waiting[i];
        total_tat += turnaround[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
