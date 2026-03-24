#include <stdio.h>
#include <stdlib.h>

int Merge(int arr[], int Low, int mid, int High) {
    int B[High];
    int I = Low;
    int N = Low;
    int J = mid+1;
    while ((N <= mid) && (J <= High)) {
        if (arr[N] <= arr[J]) {
            
            B[I] = arr[N];
            N++;
        }
        else {
           
            B[I] = arr[J];
            J++;
        }
        I++;
    }
    if (N > mid) {
        for (int k=J; k<=High; k++) {
            B[I] = arr[k];
            I++;
        }
    }
    else {
        for (int k=N; k<=mid; k++) {
            B[I] = arr[k];
            I++;
        }
    }

    for (int k=Low ; k <= High; k++) {
        arr[k] = B[k];
    }
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