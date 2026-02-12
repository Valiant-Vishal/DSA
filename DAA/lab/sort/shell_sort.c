#include <stdio.h>
void shell(int arr[], int n) {
    int gap = n/2 ;
    while (gap > 0) {
        for (int i=gap;i<n;i++){
            int temp = arr[i];
            int j = i;

            while ((j >= gap) && (arr[j-gap] > temp)){
                arr[j] = arr[j-gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
        gap = gap/2;

    }

    
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    shell(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}