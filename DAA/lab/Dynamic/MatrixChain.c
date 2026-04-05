#include<stdio.h>
#define INF 99999
#define MAX 100



void print2DArray(int n, int arr[n][n], char* label) {
    printf("\n--- %s Matrix ---\n", label);
    
    printf("      "); 
    for (int j = 1; j < n; j++) printf("[%d]   ", j);
    printf("\n");

    for (int i = 1; i < n; i++) {
        
        printf("[%d] ", i); 
        
        for (int j = 1; j < n; j++) {
            if (j < i) {
                printf("  -   "); 
            } else if (arr[i][j] == INF) {
                printf(" INF  ");
            } else {
                
                printf("%4d  ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void printOptimalParens(int n, int S[n][n], int i, int j) {
    if (i == j) {
        printf("A%d", i); 
    } else {
        printf("(");

        printOptimalParens(n, S, i, S[i][j]);
        
        printOptimalParens(n, S, S[i][j] + 1, j);
        printf(")");
    }
}

void MatrixChain(int P[], int n ) {
    int M[n][n];
    int S[n][n];

    for (int i=0 ; i<n; i++) {
        for (int j=0; j<n ; j++ ) {
            if (i==0) {
                M[i][j] = j;
                S[i][j] = j;
            }
            else if (j==0)
            {
                M[i][j] = i;
                S[i][j] = i;
            }
            
            else {
                M[i][j] = 0;
                S[i][j] = 0;
            }
        }
    }

    for (int l=2; l<=n ; l++) {

        for (int i=1 ; i<n-l+1; i++) {

            int j=i+l-1;
            M[i][j] = INF;

            for (int k=i; k<=j-1; k++) {
                int q = M[i][k] + M[k+1][j] + ( P[i-1] * P[k] * P[j] ) ;

                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
    printf("The Cost table:");
    print2DArray(n, M, "cost");
    printf("The K valu table:");
    print2DArray(n, S , "K");
    printf("\nOptimal Parenthesization: ");
    printOptimalParens(n, S, 1, n-1); 
    printf("\n");

}

int main() {
    int P[] = {5,4,6,2,7};
    int n = 5;
    MatrixChain(P, n);
    
}