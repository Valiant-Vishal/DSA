#include <stdio.h>
#include <limits.h>

#define INF 99999
#define V 4  

void printSolution(int dist[V][V]) {
    
    printf("     ");
    for (int i = 0; i < V; i++)
        printf("%6d", i);
    printf("\n     ");
    for (int i = 0; i < V; i++)
        printf("------");
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%3d |", i);
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("   INF");
            else
                printf("%6d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {  0,   3, INF,   7 },
        {  8,   0,   2, INF },
        {  5, INF,   0,   1 },
        {  2, INF, INF,   0 }
    };

    printf("Floyd-Warshall All-Pairs Shortest Path\n");
    printf("========================================\n\n");
    printf("Input Graph :\n\n");
    printSolution(graph);
    printf("\n");
    printf("Shortest distances between every pair of vertices:\n\n");
    floydWarshall(graph);

    return 0;
}