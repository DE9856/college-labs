#include <stdio.h>
#include <string.h>
void main(){
  int alloc[10][10], max[10][10], avail[10], need[10][10], work[10];
  char finish[10];
  int i,j,p,r;
  printf("Enter the no. of processes and resources: \n");
  scanf("%d%d", &p, &r);
  printf("\nEnter the Allocation Matrix: \n");
  for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&alloc[i][j]);
  printf("\nEnter the Max Matrix: \n");
  for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&max[i][j]);
   printf("\nEnter Available Matrix\n");
  for(j=0;j<r;j++){
    scanf("%d",&avail[j]);
    work[j] = avail[j];
  }
  
  for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      need[i][j] = max[i][j] - alloc[i][j];
  
  for(int i=0;i<p;i++)
    finish[i] = 'n';
    
  int count = 0;
  while(count<p){
    int found = 0;
    for(i = 0;i<p;i++){
      if(finish[i]=='n'){
        int can_allocate = 1;
        for(j=0;j<r;j++){
          if(need[i][j]>work[j]){
            can_allocate = 0;
            break;
          }
        }
        if(can_allocate){
          printf("\nProcess %d has been selected\n",i);
          printf("Work Vector before Allocation: ");
          for(int j=0;j<r;j++)
            printf("%d\t",work[j]);
          for(int j = 0;j<r;j++)
            work[j]+=alloc[i][j];
          finish[i]='y';
          count++;
          found = 1;
          printf("\nWork Vector after Process Execution ");
          for(int j=0;j<r;j++)
            printf("%d\t",work[j]);
        }
      }
    }
    if(!found)
      break;
  }
  if(count==p){
    printf("\nSystem is in safe state");
  }
  else
    printf("\nSystem is not in safe state");
}
