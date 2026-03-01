#include <stdio.h>
#define MAX 25
int main(){
  int block[MAX], file[MAX], frag[MAX], used[MAX] = {0}, alloc[MAX];
  int nb, nf,i,j,best,min;
  printf("Enter the number of blocks: ");
  scanf("%d", &nb);
  printf("Enter the number of files: ");
  scanf("%d", &nf);
  printf("Enter the size of the blocks: ");
  for(i=0;i<nb;i++)
    scanf("%d", &block[i]);
  printf("Enter the size of the files: ");
  for(i=0;i<nf;i++){
    scanf("%d", &file[i]);
    alloc[i]=-1;
  }
  
  for(i=0;i<nf;i++){
    min=99999;best=-1;
    for(j=0;j<nb;j++){
      if(!used[j] && block[j]>=file[i] && block[j]-file[i]<min){
        min=block[j] - file[i];
        best = j;
      }
    }
    if(best!=-1){
      alloc[i] = best;
      frag[i] = min;
      used[best] = 1;      
    }
    else
      frag[i] = -1;
  }
  
  printf("\nFile No.\tFile Size\tBlock No.\tBlock Size\tFragment");
  for(i=0;i<nf;i++){
    if(alloc[i]!=-1)
      printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,file[i], alloc[i]+1, block[alloc[i]], frag[i]);
    else
       printf("\n%d\t\t%d\t\tNot Allocated",i+1,file[i]);
  }
  return 0;
}
