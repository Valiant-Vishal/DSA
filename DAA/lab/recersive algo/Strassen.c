#include <stdio.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}


void sub(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}


void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = n / 2;
    
    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    int M1[half][half], M2[half][half], M3[half][half], M4[half][half];
    int M5[half][half], M6[half][half], M7[half][half];
    int temp1[half][half], temp2[half][half];

    
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }


    

    add(half, A11, A22, temp1);
    add(half, B11, B22, temp2);
    strassen(half, temp1, temp2, M1);


    add(half, A21, A22, temp1);
    strassen(half, temp1, B11, M2);


    sub(half, B12, B22, temp1);
    strassen(half, A11, temp1, M3);


    sub(half, B21, B11, temp1);
    strassen(half, A22, temp1, M4);


    add(half, A11, A12, temp1);
    strassen(half, temp1, B22, M5);


    sub(half, A21, A11, temp1);
    add(half, B11, B12, temp2);
    strassen(half, temp1, temp2, M6);

    sub(half, A12, A22, temp1);
    add(half, B21, B22, temp2);
    strassen(half, temp1, temp2, M7);


    add(half, M1, M4, temp1);
    sub(half, temp1, M5, temp2);
    add(half, temp2, M7, C11);


    add(half, M3, M5, C12);
    add(half, M2, M4, C21);


    sub(half, M1, M2, temp1);
    add(half, temp1, M3, temp2);
    add(half, temp2, M6, C22);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

// Main function to test the 4x4 matrix
int main() {
    int n = 4;
    
    // 4x4 Matrix A
    int A[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    // 4x4 Matrix B
    int B[4][4] = {
        {2, 0, 1, 3},
        {1, 2, 0, 1},
        {0, 1, 2, 0},
        {3, 0, 1, 2}
    };
    
    // Result Matrix C, initialized to 0
    int C[4][4] = {0};

    // Run Strassen's algorithm
    strassen(n, A, B, C);

    // Print the result
    printf("Resulting 4x4 Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}