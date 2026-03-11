#include <stdio.h>

struct process {
    int pid, bt, pr, wt, tat;
};

int main() {
    int n, i, j;
    struct process p[10], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        p[i].pid = i+1;

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Enter Priority: ");
        scanf("%d", &p[i].pr);
    }

    // Sort by priority (lower number = higher priority)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].pr > p[j].pr) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wt = 0;

    for(i = 1; i < n; i++)
        p[i].wt = p[i-1].wt + p[i-1].bt;

    for(i = 0; i < n; i++) {
        p[i].tat = p[i].wt + p[i].bt;
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].pr, p[i].wt, p[i].tat);

    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);

    return 0;
}
