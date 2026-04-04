#include <stdio.h>
#include <stdlib.h>

void printBag(int A[], int k) {
    printf("Bag: ");
    for (int i = 0; i < k; i++) { 
        printf("%d%s", A[i], (i == k - 1) ? "" : " , ");
    }
    printf("\n");
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int*  DPKnapsack(int P[] , int W[], int n, int m) {
    int K[n+1][m+1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                K[i][j] = 0;
            } else if (W[i - 1] <= j) {
                K[i][j] = max(P[i - 1] + K[i - 1][j - W[i - 1]], K[i - 1][j]);
            } else {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    int i = n;
    int j = m;
    int* include = (int*)calloc(n, sizeof(int));

    while (i > 0 && j > 0) {
        if (K[i][j] != K[i - 1][j]) {
            include[i - 1] = 1;
            j -= W[i - 1];
        }
        i--; 
    }
    printf("Total Profit: %d\n", K[n][m]);
    return include;
}

int main() {
    int m;
    int n;
    printf("Enter the no. of things :");
    scanf("%d",&n);

    int profit[n];
    int weight[n];


    printf("Enter the profit for the things :\n");
    for (int i=0;i<n;i++) {
        printf("%d :",i+1);
        scanf("%d",&profit[i]);
    }

    printf("Enter the weight for the things : \n");
    for (int i=0;i<n;i++) {
        printf("%d :",i+1);
        scanf("%d",&weight[i]);
    }

    printf("Enter the Knapscap capacity :");
    scanf("%d",&m);

    int* Array = DPKnapsack(profit, weight, n, m) ;

    printBag(Array, n);

    free(Array);
    return 0;
}