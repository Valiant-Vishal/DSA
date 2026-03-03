#include <stdio.h>
#include <stdlib.h>

void add(int size, int A[][size], int B[][size], int C[][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void sub(int size, int A[][size], int B[][size], int C[][size]) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
  
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    
    int a11[k][k], a12[k][k], a21[k][k], a22[k][k];
    int b11[k][k], b12[k][k], b21[k][k], b22[k][k];
    int c11[k][k], c12[k][k], c21[k][k], c22[k][k];
    int m1[k][k], m2[k][k], m3[k][k], m4[k][k], m5[k][k], m6[k][k], m7[k][k];
    int temp1[k][k], temp2[k][k];

  
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

    // M1 = (A11 + A22) * (B11 + B22)
    add(k, a11, a22, temp1); add(k, b11, b22, temp2);
    strassen(k, temp1, temp2, m1);

    // M2 = (A21 + A22) * B11
    add(k, a21, a22, temp1);
    strassen(k, temp1, b11, m2);

    // M3 = A11 * (B12 - B22)
    sub(k, b12, b22, temp2);
    strassen(k, a11, temp2, m3);

    // M4 = A22 * (B21 - B11)
    sub(k, b21, b11, temp2);
    strassen(k, a22, temp2, m4);

    // M5 = (A11 + A12) * B22
    add(k, a11, a12, temp1);
    strassen(k, temp1, b22, m5);

    // M6 = (A21 - A11) * (B11 + B12)
    sub(k, a21, a11, temp1); add(k, b11, b12, temp2);
    strassen(k, temp1, temp2, m6);

    // M7 = (A12 - A22) * (B21 + B22)
    sub(k, a12, a22, temp1); add(k, b21, b22, temp2);
    strassen(k, temp1, temp2, m7);

   
    // C11 = M1 + M4 - M5 + M7
    add(k, m1, m4, temp1); sub(k, temp1, m5, temp2); add(k, temp2, m7, c11);
    // C12 = M3 + M5
    add(k, m3, m5, c12);
    // C21 = M2 + M4
    add(k, m2, m4, c21);
    // C22 = M1 - M2 + M3 + M6
    sub(k, m1, m2, temp1); add(k, temp1, m3, temp2); add(k, temp2, m6, c22);


    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];
            C[i + k][j + k] = c22[i][j];
        }
    }
}