#include <stdio.h>
#include <stdlib.h>

void heap(int k[], int n) {
    for (int Q=1; Q<n; Q++) {
        int I = Q;
        int key = k[Q];
        int J = I/2;

        while ((I>0) && key > k[J]) {
            k[I] = k[J];
            I = J;
            J = I/2;

            if (J < 0) {
                J = 0;
            }

        }
        k[I] = key;
    }
}

int main() {
        int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heap(arr, n);
    printf("\nHEAP array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}