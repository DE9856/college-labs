#include <stdio.h>
struct Directory{
  char name[20];
  int count;
  char files[20][20];
};

int main(){
  int n, i,j;
  printf("Enter the number of directories: ");
  scanf("%d", &n);
  struct Directory d[n];
  
  for(i=0;i<n;i++){
    printf("\nDirectory %d:\n",i+1);
    printf("Enter Directory Name: ");
    scanf("%s", d[i].name);
    printf("\nEnter number of files: ");
    scanf("%d",&d[i].count);
    printf("Enter the file names: ");
    for(j=0;j<d[i].count;j++)
      scanf("%s",d[i].files[j]);
  }
  
  printf("\n\nDIRECTORY\t\tSize\t\tFilename\n");
  for(i=0;i<n;i++){
    printf("%s\t\t%d\t\t\t",d[i].name,d[i].count);
    for(j=0;j<d[i].count;j++)
      printf("%s\n\t\t\t\t",d[i].files[j]);
    printf("\n");
  }
  return 0;
}
