/*
Step 1:  Initialize all distances to infinity and `visited` to false; set the `start` node's distance to 0.
Step 2:  Start a loop that runs for all nodes.
Step 3:  In the loop, select the unvisited node `u` with the smallest distance.
Step 4:  Mark `u` as `visited` and, for all its unvisited neighbors `v`, update `dist[v]` if `dist[u] + weight(u, v)` is smaller.
Step 5:  After the loop, the `dist` array holds the shortest path distances from `start`.
*/
#include <stdio.h>
#include <limits.h> 

#define MAX 100
#define INF INT_MAX

int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j);
}

void printSolution(int dist[], int parent[], int n, int start) {
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\t%d\t\t%d", start, i, dist[i], start);
        printPath(parent, i);
        printf("\n");
    }
}

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];
    int visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                (dist[u] + graph[u][v] < dist[v])) 
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, parent, n, start);
}

int main() {
    int graph[MAX][MAX] = {0};
    int n, edges, u, v, weight, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight; 
    }

    printf("\nEnter starting vertex: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}