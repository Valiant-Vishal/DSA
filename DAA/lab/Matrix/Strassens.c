#include <stdio.h>
#include <stdio.h>

int add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return 0;
}

int sub(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return 0;
}

int strassen(int n, int A[n][n], int B[n][n], int C[n][n]){
    if (n == 1){
        C[0][0] = A[0][0] * B[0][0];
        return 0;
    }
    int k = n / 2;
    int a11[k][k], a12[k][k], a21[k][k], a22[k][k];
    int b11[k][k], b12[k][k], b21[k][k], b22[k][k];
    int c11[k][k], c12[k][k], c21[k][k], c22[k][k];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j];
            a22[i][j] = A[i + k][j + k];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j];
            b22[i][j] = B[i + k][j + k];
        }
    }

    int m1[k][k], m2[k][k], m3[k][k], m4[k][k], m5[k][k], m6[k][k], m7[k][k];
    int temp1[k][k], temp2[k][k];




}



int main() {
    
    return 0;
}
