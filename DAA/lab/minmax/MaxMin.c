#include <stdio.h>

void MaxMin(int arr[], int i, int j, int *max, int *min) {
    int max1, min1; 
    if (i == j) {
        *max = *min = arr[i];
    }

    else if (i == j - 1) {
        if (arr[i] < arr[j]) {
            *max = arr[j];
            *min = arr[i];
        } 
        else {
            *max = arr[i];
            *min = arr[j];
        }
    }

    else {
        int mid = (i + j) / 2;
        
        
        MaxMin(arr, i, mid, max, min);  
        
        MaxMin(arr, mid + 1, j, &max1, &min1);

        if (*max < max1)
            *max = max1;

        if (*min > min1)
            *min = min1;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];
    printf("Enter the element: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;
    
    MaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}