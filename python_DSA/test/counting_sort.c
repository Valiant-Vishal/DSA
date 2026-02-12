#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n) {
    // 1. Find the maximum element to know the range
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    // 2. Create count array and initialize with 0
    int count[max + 1];
    memset(count, 0, sizeof(count));

    // 3. Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // 4. Update count[i] to store actual position in output array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 5. Build the output array
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // 6. Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}