#include <stdio.h>

#define MAX 100

int visited[MAX];

void DFS(int n, int adj[n][n], int node) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i])
            DFS(n, adj, i);
    }
}

int main() {
    int n;
    printf("NAME:Bhavana K S\nUSN:1BM24CS070");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(n, adj, 0);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    return 0;
}
