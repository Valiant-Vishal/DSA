#include <stdio.h>
#include <stdlib.h>

int Merge(int arr[], int LB, int mid, int HB) {
    int i = LB, j = mid + 1, k = LB;
    int B[HB + 1];

    while (i <= mid && j <= HB) {
        if (arr[i] <= arr[j]) {
            B[k++] = arr[i++];
        } else {
            B[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        B[k++] = arr[i++];
    }

    while (j <= HB) {
        B[k++] = arr[j++];
    }

    for (i = LB; i <= HB; i++) {
        arr[i] = B[i];
    }
    
    return 0;
}

int MergeSort(int arr[], int LB, int HB) {
    if (LB < HB) {
        int mid = (LB + HB) / 2;
        MergeSort(arr, LB, mid);
        MergeSort(arr, mid + 1, HB);
        Merge(arr, LB, mid, HB);
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) { free(arr); return 1; }
    }

    MergeSort(arr, 0, n - 1);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");

    free(arr);
    return 0;
}