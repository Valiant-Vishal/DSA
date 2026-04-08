#include <stdio.h>

int selection(int arr[],int n)
{
    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i+1; k < n; k++ ) {
            if (arr[k] < arr[j]) {
                j = k;
            }
        }
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}


int main()
{
    int arr[] = {6702, 9246, 4029, 316, 5185, 3558, 9431, 8468, 285, 2872};

    int n = sizeof(arr) / sizeof(arr[0]);

    selection(arr,n);
    
    printf("Sorted array: ");

    for (int l = 0; l < n; l++)
    {
        printf("%d ", arr[l]);
    }

    return 0;
}
