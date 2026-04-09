#include<stdio.h>

int main()
{
    int j, temp; 

    int arr[] = {
    6702, 9246, 4029, 316, 5185, 3558, 9799 };

    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    
    for (int i=1;i<n;i++)
    {
        temp = arr[i];
        j=i-1;
        while (j >= 0 && arr[j]>temp)
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j+1]=temp;
    }

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;

}