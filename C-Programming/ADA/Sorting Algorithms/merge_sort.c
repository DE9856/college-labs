#include <stdio.h>
#include <time.h>
#include <stdlib.h>
clock_t start, end;

void merge(int arr[], int l, int m, int r){
  int i=l, j=m+1, k=0;
  int temp[r - l + 1];
  while(i<=m && j<=r){
    if(arr[i]<arr[j])
      temp[k++]=arr[i++];
    else
      temp[k++]=arr[j++];
  }
  while(i<=m)
    temp[k++]=arr[i++];
  while(j<=r)
    temp[k++]=arr[j++];
  for(i=l,k=0; i<=r; i++,k++)
    arr[i]=temp[k];
}

void merge_sort(int arr[], int left, int right){
  if(left<right){
    int mid=(left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main(){
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  for(int i=0; i<n; i++)
    arr[i]=rand()%(n*2);
  
  start = clock();
  merge_sort(arr, 0, n-1);
  end = clock();

  printf("The time taken is %lfms\n", (double)(end-start)/(double)(CLOCKS_PER_SEC)*1000);
  return 0;
}
