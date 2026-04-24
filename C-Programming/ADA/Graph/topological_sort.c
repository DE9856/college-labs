#define MAX 100
#include <stdio.h>

int a[MAX][MAX], indegree[MAX], queue[MAX];
int front = 0, rear = -1, n;

void toposort(){
    int count = 0;
    for(int i = 0;i<n;i++){
        indegree[i]=0;
        for(int j = 0;j<n;j++)
            if(a[j][i]==1)
                indegree[i]++;
    }

    for(int i = 0;i<n;i++)
        if(indegree[i]==0)
            queue[++rear]=i;
    
    printf("Topological Order: ");
    while(front<=rear){
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for(int i = 0;i<n;i++){
            if(a[v][i]==1){
                indegree[i]--;
                if(indegree[i]==0)
                    queue[++rear] = i;
            }
        }
    }

    if(count!=n)
        printf("\nCycle Detected, Topological Sort not possible");
    else
        printf("\nCycle not detected");
}

int main(){
    printf("Enter the no. of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d", &a[i][j]);

    toposort();
    return 0;
}
