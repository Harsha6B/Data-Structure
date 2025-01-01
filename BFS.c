#include<stdio.h>
void bfs(int);
int a[10][10], vis[10], n;

void main()
{
   int i, j, src;
   
   printf("enter the number of vertices\n");
   scanf("%d", &n);  // Input the number of vertices
   printf("enter the adjacency matrix\n");
   for (i = 1; i <= n; i++) {  // Input the adjacency matrix
      for (j = 1; j <= n; j++) {
         scanf("%d", &a[i][j]);  // Adjacency matrix entry (0 or 1)
      }
      vis[i] = 0;  // Initially, all vertices are unvisited
   }

   printf("enter the src vertex\n");
   scanf("%d", &src);  // Input the source vertex for BFS traversal
   printf("nodes reachable from src vertex\n");
   bfs(src);  // Start BFS from the source vertex
}

void bfs(int v)
{
    int q[10], f = 1, r = 1, u, i;
    q[r] = v;  // Enqueue the start vertex (source vertex)
    vis[v] = 1;  // Mark the source vertex as visited

    while (f <= r) {  // While there are elements in the queue
       u = q[f];  // Dequeue the first vertex (from the front of the queue)
       printf("%d ", u);  // Print the current vertex

       for (i = 1; i <= n; i++) {  // Explore all adjacent vertices of u
          if (a[u][i] == 1 && vis[i] == 0) {  // If vertex i is connected and unvisited
             vis[i] = 1;  // Mark vertex i as visited
             r = r + 1;  // Increment the rear pointer of the queue
             q[r] = i;  // Enqueue vertex i
          }
       }

       f = f + 1;  // Increment the front pointer of the queue (dequeue operation)
    }
}


******OUTPUT******
enter the number of vertices
4
enter the adjacency matrix
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
enter the src vertex
1
nodes reachable from src vertex
1 2 3 4

