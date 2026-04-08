#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 8

int x[N];
int Count = 1;
void printSolution(int board[]) {
    
    printf("Solutions : %d\n", Count);
    for (int i = 0; i < N; i++) {
        // int q=1;
        for (int j = 0; j < N; j++) {
            if (board[i] == j){
                // printf("Q%d -> Col%d\n",q ,j+1 );
                // q++;
                printf(" Q ");
            }
            else {
                printf(" - ");
            }
        
        }
    printf("\n");
    }
    Count++;
}

bool Place(int k, int i) {
    for (int j = 0; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void NQueens(int k, int n) {
    for (int i=0; i < n; i++) {
        if (Place( k, i)) {
            x[k] = i;
            x[n];
            if ( k == n-1 ){
                printSolution(x);
            }
            else{
                NQueens( k + 1, n);
            }
        }
    }
    
}

int main() { 
    NQueens(0, N);
    return 0;
}