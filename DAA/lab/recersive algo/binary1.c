#include<stdio.h>
#include<stdlib.h>

int binarySearch(int arr[], int i, int l, int x) {
    if (l==i){
        if (x == arr[i]) return x;
        else return 0;
    }

    else{
        int mid=((i+l)/2);
        if (x==arr[mid]) return mid;
        else if(x<arr[mid]) return binarySearch(arr,i,mid-1,x);
        else return binarySearch(arr,mid+1,l,x);
    }
    
    return -1;
}


int main() {
    int n, x;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];
    printf("Enter the elements (sorted): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}