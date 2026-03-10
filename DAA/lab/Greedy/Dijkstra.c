#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX
#define N 5

int minDistance(int dist[], bool s[], int n) {
    int min = INF , min_index = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }return min_index;
}

int Shortestpath(int v,int cost[][N], int dist[], int n){
    bool s[n];
    dist[v] = 0;
    for (int i=1;i<n;i++) {
        s[i] = false;
        dist[i]=cost[v][i];
    }

    s[v] = true;
    dist[v] = 0;

    for (int i=0;i<=n-1;i++) {       
        
        int u = minDistance(dist, s, n);
        if (u == -1) break;

        s[u] = true;
        for (int w = 0; w < n; w++) {
            if (s[w] == false && cost[u][w] != INF && dist[u] != INF) {
                if (dist[w] > dist[u] + cost[u][w]) {
                    dist[w] = dist[u] + cost[u][w];
                }
            } 
        }
        
    }
}

int main() {
    int n = N; //number of the vertices
    
    int dist[N];
    int s[N];
    int cost[N][N] = {
        {0,   10,  INF, 30,  100},
        {INF, 0,   50,  INF, INF},
        {INF, INF, 0,   INF, 10},
        {INF, INF, 20,  0,   60},
        {INF, INF, INF, INF, 0}
    };

    int source = 0;
    Shortestpath(source, cost, dist, n);
    printf("Vertex\tDistance from Source %d\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }

    return 0;


}