#include <stdio.h>
int main(){
  int n;
  printf("Enter Number of Processes: ");
  scanf("%d",&n);
  int pid[n], at[n], bt[n], ct[n],tat[n],wt[n],done[n];
  float atat = 0.0,awt=0.0;
  for(int i=0;i<n;i++){
    printf("Enter PID, AT, BT for Process %d: ",i+1);
    scanf("%d%d%d",&pid[i], &at[i], &bt[i]);
    done[i] = 0;
  }
  int time = 0,completed = 0;
  while(completed<n){
    int idx = -1;
    int minBt = 99999;
    for(int i =0;i<n;i++){
      if(at[i]<=time && done[i]==0 && bt[i] <minBt){
        minBt = bt[i];
        idx = i;
      }
    }
    if(idx==-1){
      time++;
      continue;
    }
    ct[idx] = time+bt[idx];
    tat[idx] = ct[idx] - at[idx];
    wt[idx] = tat[idx] - bt[idx];
    time+=bt[idx];
    atat+=tat[idx];
    awt+=wt[idx];
    done[idx] = 1;
    completed++;
  }
  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for(int i =0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
  }
  printf("Average TAT: %f\nAverage WT: %f",atat/n,awt/n);
}
