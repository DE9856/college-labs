#define MAX 100
#include <stdio.h>

int a[MAX][MAX], visited[MAX], stack[MAX];
int top = -1, n;

void dfs(int node){
    visited[node] = 1;

    for(int i = 0; i < n; i++){
        if(a[node][i] == 1 && visited[i] == 0){
            dfs(i);
        }
    }

    stack[++top] = node;
}

void toposort(){
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            dfs(i);
        }
    }

    printf("Topological Sort: ");
    while(top >= 0){
        printf("%d ", stack[top--] + 1);
    }
}

int main(){
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0;
    }

    toposort();
    return 0;
}
