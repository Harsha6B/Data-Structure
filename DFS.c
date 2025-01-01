#include <stdio.h>

void dfs(int);
int a[10][10], vis[10], n;

void main()
{
    int i, j, src;

    // Input the number of vertices
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    // Input the adjacency matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);  // Read the matrix value (0 or 1)
        }
        vis[i] = 0;  // Initially mark all vertices as unvisited
    }

    // Input the source vertex for DFS traversal
    printf("Enter the source vertex:\n");
    scanf("%d", &src);

    // Print nodes reachable from the source vertex
    printf("Nodes reachable from source vertex %d:\n", src);
    dfs(src);  // Start DFS from the source vertex
}

// DFS Function
void dfs(int v)
{
    int i;

    // Mark the current vertex as visited
    vis[v] = 1;
    printf("%d ", v);  // Print the current vertex

    // Explore all the adjacent vertices of the current vertex
    for (i = 1; i <= n; i++) {
        if (a[v][i] == 1 && vis[i] == 0) {  // If there is an edge and vertex i is not visited
            dfs(i);  // Recursively visit the neighbor vertex
        }
    }
}


******OUTPUT******
