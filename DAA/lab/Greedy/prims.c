#include <stdio.h>

#define MAX 100
#define INF 999

int prims(int n, int cost[MAX][MAX]) {
    int near[MAX], t[MAX][2];
    int mincost = 0, k, l;
    int edge_count = 0;

    int min = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    mincost = cost[k][l];
    t[1][0] = k;
    t[1][1] = l;
    edge_count++;
    printf("\nEdges in MST (Prim's):\n");
    printf("Edge %d: (%d, %d) cost: %d\n", edge_count, k, l, cost[k][l]);

    for (int i = 1; i <= n; i++) {
        if (cost[i][l] < cost[i][k])
            near[i] = l;
        else
            near[i] = k;
    }
    near[k] = near[l] = 0;

    for (int i = 2; i < n; i++) {
        int j, min_val = INF;

        for (int m = 1; m <= n; m++) {
            if (near[m] != 0 && cost[m][near[m]] < min_val) {
                min_val = cost[m][near[m]];
                j = m;
            }
        }

        t[i][0] = j;
        t[i][1] = near[j];
        mincost += cost[j][near[j]];
        edge_count++;
        printf("Edge %d: (%d, %d) cost: %d\n", edge_count, j, near[j], cost[j][near[j]]);
        near[j] = 0;

        for (int k_idx = 1; k_idx <= n; k_idx++) {
            if (near[k_idx] != 0 && cost[k_idx][near[k_idx]] > cost[k_idx][j]) {
                near[k_idx] = j;
            }
        }
    }

    return mincost;
}


int main() {
    int n;
    n = 6;
    int cost[MAX][MAX];
    
    // Initialize all values to INF
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cost[i][j] = INF;
        }
    }
    cost[1][2] = cost[2][1] = 10;
    cost[1][4] = cost[4][1] = 30;
    cost[1][5] = cost[5][1] = 100;
    cost[2][3] = cost[3][2] = 50;
    cost[3][4] = cost[4][3] = 20;
    cost[3][5] = cost[5][3] = 5;
    cost[4][5] = cost[5][4] = 60;
    
    // Diagonal elements are 0
    for (int i = 0; i <= n; i++) {
        cost[i][i] = 0;
    }
    
    printf("\n--- Prim's Algorithm ---");
    int mincost = prims(n, cost);
    printf("\nMinimum Cost: %d\n", mincost);
    
    return 0;
}