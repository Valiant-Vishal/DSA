#include <stdio.h>

int search(int array[], int size, int x) {
    int low, high, mid;
    low = 0;
    high = size - 1; 
    while (low <= high) {
        mid = (low + high) / 2; 
        if (array[mid] == x) 
            return mid;
        else if (array[mid] < x) 
            low = mid + 1;
        else
            high = mid - 1;
        
    }
    return -1;
}

int main() {
    int x,s;
    printf("Enter the no. of elements you want to enter:");
    scanf("%d",&s);
    int arr[s];

    for (int i;i<s;i++){
      printf("Enter element %d:",i+1);
      scanf("%d", &arr[i]);
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter a number to search: ");
    scanf("%d", &x);


    int result = search(arr, n, x);

    (result == -1) ? printf("Element not found\n") : printf("Element found at index: %d\n", result);

    return 0; 
}