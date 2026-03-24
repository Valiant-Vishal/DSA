#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999

int parent[MAX];

// Find function for Union-Find
int find(int i) {
    while (parent[i] > 0)
        i = parent[i];
    return i;
}

// Union function for Union-Find
void uni(int i, int j) {
    parent[i] = j;
}

void kruskal(int n, int cost[MAX][MAX]) {
    int mincost = 0;
    int edge_count = 0;
    int t[MAX][2]; // To store edges of MST

    // Initialize Parent array
    for (int i = 1; i <= n; i++) parent[i] = -1;

    printf("\nEdges in the MST (Kruskal):\n");

    while (edge_count < n - 1) {
        int min = INF, u = -1, v = -1;

        // Simulate heap/extract-min by finding the absolute minimum edge
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int j_root = find(u);
        int k_root = find(v);

        if (j_root != k_root) {
            edge_count++;
            printf("Edge %d: (%d, %d) cost: %d\n", edge_count, u, v, min);
            mincost += min;
            uni(j_root, k_root);
        }

        // Mark edge as visited
        cost[u][v] = cost[v][u] = INF;
    }

    if (edge_count != n - 1) {
        printf("\nNO MST exists.\n");
    } else {
        printf("\nMinimum Cost: %d\n", mincost);
    }
}