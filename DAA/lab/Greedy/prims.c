#include <stdio.h>

#define MAX 100
#define INF 999

void prims(int n, int cost[MAX][MAX]) {
    int near[MAX], t[MAX][2];
    int mincost = 0, k, l;

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
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (Enter 999 for No Edge/Infinity):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    
    printf("\n--- Prim's Algorithm ---");
    prims(n, cost);
    
    return 0;
}