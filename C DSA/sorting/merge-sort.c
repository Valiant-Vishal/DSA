#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // size of left subarray
    int n2 = right - mid;     // size of right subarray

    int L[n1], R[n2];  // temporary arrays

    // Copy data to temporary arrays
    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Merge back into original array
    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining elements
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;  // find the middle
        mergeSort(arr, left, mid);           // sort left half
        mergeSort(arr, mid + 1, right);      // sort right half
        merge(arr, left, mid, right);        // merge both halves
    }
}


int main()
{
    int s;
    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &s);
    int arr[s];

    for (int k = 0; k < s; k++)
    {
        printf("Enter element %d: ", k + 1);
        scanf("%d", &arr[k]);
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted array: ");
    for (int l = 0; l < n; l++)
    {
        printf("%d ", arr[l]);
    }
    return 0;
}