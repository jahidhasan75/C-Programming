#include <stdio.h>

struct process
{
    int pid;
    int bt;
    int wt;
    int tat;
};

int main()
{
    struct process p[10], temp;
    int n, i, j;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter process id: ");
        scanf("%d", &p[i].pid);

        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
    }

    /* Sorting according to burst time */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].bt > p[j].bt)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* Waiting time */
    p[0].wt = 0;

    for(i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].wt + p[i - 1].bt;
    }

    /* Turnaround time */
    for(i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }

    /* Average */
    for(i = 0; i < n; i++)
    {
        avg_wt = avg_wt + p[i].wt;
        avg_tat = avg_tat + p[i].tat;
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].bt,
               p[i].wt,
               p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    /* Gantt Chart */
    printf("\nGantt Chart:\n");

    for(i = 0; i < n; i++)
    {
        printf("--------");
    }

    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("| P%d ", p[i].pid);
    }

    printf("|\n");

    for(i = 0; i < n; i++)
    {
        printf("--------");
    }

    printf("\n0");

    for(i = 0; i < n; i++)
    {
        printf("\t%d", p[i].tat);
    }

    printf("\n");

    return 0;
}