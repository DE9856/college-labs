#include <stdio.h>
int main(){
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], done[n];
    float atat = 0.0f, awt = 0.0f;
    for(int i = 0; i < n; i++){
        printf("Enter PID, AT, BT, Priority for Process %d: ", i+1);
        scanf("%d %d %d %d", &pid[i], &at[i], &bt[i], &pr[i]);
        done[i] = 0;
    }
    int time = 0, completed = 0;
    while(completed < n){
        int idx = -1;
        int minPr = 999999;
        for(int i = 0; i < n; i++){
            if(at[i] <= time && done[i] == 0){
                if ( idx == -1
                    || pr[i] < minPr
                    || (pr[i] == minPr && at[i] < at[idx])
                    || (pr[i] == minPr && at[i] == at[idx] && bt[i] < bt[idx])
                    || (pr[i] == minPr && at[i] == at[idx] && bt[i] == bt[idx] && pid[i] < pid[idx]) )
                {
                    minPr = pr[i];
                    idx = i;
                }
            }
        }
        if(idx == -1){
            time++;
            continue;
        }
        ct[idx] = time + bt[idx];
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        time += bt[idx];
        atat += tat[idx];
        awt += wt[idx];
        done[idx] = 1;
        completed++;
    }
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage TAT: %.2f\nAverage WT: %.2f\n", atat / n, awt / n);
    return 0;
}
