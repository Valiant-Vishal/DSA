#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int cost_matrix[MAX][MAX];
int dist[MAX], d[MAX], path[MAX];

// Forward Approach
void FGraph(int n, int k) {
    dist[n] = 0; // Cost to reach sink from sink is 0

    // Compute costs from n-1 down to 1
    for (int j = n - 1; j >= 1; j--) {
        int min_val = INF;
        for (int r = j + 1; r <= n; r++) {
            if (cost_matrix[j][r] != INF && cost_matrix[j][r] + dist[r] < min_val) {
                min_val = cost_matrix[j][r] + dist[r];
                d[j] = r;
            }
        }
        dist[j] = min_val;
    }

    // Find the minimum cost path
    path[1] = 1;
    path[k] = n;
    for (int j = 2; j < k; j++) {
        path[j] = d[path[j - 1]];
    }
}

// Backward Approach
void BGraph(int n, int k) {
    int bcost[MAX], bd[MAX];
    bcost[1] = 0;    // Cost from source to source is 0

    // Compute costs from 2 up to n
    for (int j = 2; j <= n; j++) {
        int min_val = INF;
        for (int r = 1; r < j; r++) {
            if (cost_matrix[r][j] != INF && bcost[r] + cost_matrix[r][j] < min_val) {
                min_val = bcost[r] + cost_matrix[r][j];
                bd[j] = r;
            }
        }
        bcost[j] = min_val;
    }

    // Find the minimum cost path
    path[1] = 1;
    path[k] = n;
    for (int j = k - 1; j >= 2; j--) {
        path[j] = bd[path[j + 1]];
    }
}

void printPath(int k) {
    printf("Path: ");
    for (int i = 1; i <= k; i++) {
        printf("%d%s", path[i], (i == k) ? "" : " -> ");
    }
    printf("\n");
}

int main() {
    int n, k, edges;

    printf("Enter number of vertices and stages: ");
    scanf("%d %d", &n, &k);

    // Initialize cost matrix with Infinity
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cost_matrix[i][j] = INF;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        cost_matrix[u][v] = w;
        printf("next\n");
    }

    printf("\n--- Using Forward Approach ---\n");
    FGraph(n, k);
    printf("Minimum Cost: %d\n", dist[1]);
    printPath(k);

    printf("\n--- Using Backward Approach ---\n");
    BGraph(n, k);
    printPath(k);

    return 0;
}