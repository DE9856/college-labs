#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define DISC_SIZE 199
int cmp(const void *a, const void *b){
  return (*(int*)a - *(int*)b);
}

int main(){
  int req[SIZE] = {126, 90,14, 50, 25, 42, 51, 78, 102, 100};
  int head = 42;
  int seek=0,i;
  int left[SIZE+1], right[SIZE+1];
  int l = 0,r=0;
  
  for(i=0;i<SIZE;i++){
    if(req[i]<head) left[l++] = req[i];
    else if(req[i]>head) right[r++] = req[i];
    else{}
  }
  
  left[l++] = 0;
  right[r++] =DISC_SIZE;
  qsort(left,l,sizeof(int),cmp);
  qsort(right,r,sizeof(int),cmp);
  printf("Sequence Order: \n%d",head);
  for(i=l-1;i>=0;i--){
    seek+=abs(head-left[i]);
    head = left[i];
    printf(" -> %d ",head);
  }
  for(i=0;i<r;i++){
    seek+=abs(head-right[i]);
    head = right[i];
    printf(" -> %d ",head);
  }
  printf("Total seek time: %d",seek);
  return 0;
}
