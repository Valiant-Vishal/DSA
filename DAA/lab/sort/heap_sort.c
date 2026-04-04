#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void CreateHeap(int arr[], int n) {
    for (int Q = 1; Q < n; Q++) {
        int I = Q;
        int key = arr[Q];
        
        int J = (I - 1) / 2;

        while (I > 0 && key > arr[J]) {
            arr[I] = arr[J];
            I = J;
            J = (I - 1) / 2;
        }
        arr[I] = key;
    }
}

void heapSort(int arr[], int n) {

    CreateHeap(arr, n);
    for (int Q = n - 1; Q > 0; Q--) {
        swap(&arr[Q], &arr[0]);
        int I = 0;           
        int J = 1;          
        int key = arr[0];    

        
        while (J < Q) { 
            if (J + 1 < Q && arr[J + 1] > arr[J]) {
                J++; 
            }
            
            if (arr[J] > key) {
                arr[I] = arr[J];
                I = J;
                J = 2 * I + 1;
            } else {
                break;
            }
        }
        arr[I] = key;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heapSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}   