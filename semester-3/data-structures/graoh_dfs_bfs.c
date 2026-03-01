#include <stdio.h>
int a[50][50],visited[50],n;
int q[50],front=-1,rear=-1;

void dfs(int v){
  visited[v] =1;
  for(int i=1;i<=n;i++){
    if(a[v][i]==1 && visited[i]==0){
      printf("%d\t",i);
      dfs(i);
    }
  }
}

void bfs(int v){
  visited[v]=1;
  q[++rear] = v;
  while(front!=rear){
    int cur = q[++front];
    for(int i=1;i<=n;i++){
      if(a[cur][i]==1 && visited[i]==0){
        printf("%d\t",i);
        visited[i] = 1;
        q[++rear] = i;
      }
    }
  }
}

void main(){
  int ch,v;
  printf("Enter the no. of vertices: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: \n");
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      scanf("%d", &a[i][j]);
  printf("\n\nGRAPH MENU\n\n");
  printf("1.DFS\n2.BFS\n3.Exit\n");
  while(1){
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1:
          for(int i=1;i<=n;i++) visited[i]=0;
          printf("Enter the starting vertex: ");
          scanf("%d", &v);
          printf("%d\t", v);
          dfs(v);
          break;
        case 2:
          for(int i=1;i<=n;i++) visited[i]=0;
          printf("Enter the starting vertex: ");
          scanf("%d", &v);
          printf("%d\t", v);
          front=rear=-1;
          bfs(v);
          break;
        case 3: 
          printf("Exiting...");
          return;
        default:
          printf("Invalid Choice");
    }
  }
}
