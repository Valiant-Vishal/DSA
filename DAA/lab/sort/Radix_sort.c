#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int n)
{   
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void count_sort(int arr[], int n, int pos)
{
    if (n <= 0)
        return;
    // initialize the arrays
    int countArray[10] = {0};
    int outputArray[n];
    
    // count the frequncey of the digits.
    for (int i = 0; i < n; i++){
        int digit = (arr[i] / pos) % 10;
        countArray[digit]++;
    } 
    //verfication of count array
    // printf("Count array after sorting by position %d: ", pos);
    // print_array(countArray, 10);
    
    // build the output array
    int j=0;
    for (int i=0;i<10;i++){
        while (countArray[i] > 0){
            for (int k=0;k<n;k++){
                if (((arr[k]/pos)%10)==i){
                    outputArray[j] = arr[k];
                    countArray[i]--;
                    j++;
                }
            }
        }
    }
    
    //copy the output array to arr.
    for (int i = 0; i < n; i++){
        arr[i] = outputArray[i];
    }
    
    
    // printf("Output array after sorting by position %d: ", pos);
    // print_array(outputArray, n);
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void radix_sort(int arr[], int n)
{
    int max_value = getMax(arr, n);
    for (int exp = 1; max_value / exp > 0; exp *= 10)
    {
        count_sort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    radix_sort(arr, n);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
