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
    
    int countArray[10] = {0};
    int outputArray[n];
    for (int i = 0; i < n; i++){
        int digit = (arr[i] / pos) % 10;
        countArray[digit]++;
        
    } 
    
    printf("1st loop Count array after sorting by position %d: ", pos);
    print_array(countArray, 10);

    for (int i = 1; i < 10; i++)
        countArray[i] += countArray[i - 1];
    
    printf("2nd loop Count array after sorting by position %d: ", pos);
    print_array(countArray, 10);
    
    for (int i = n - 1; i >= 0; i--){
        int digit = (arr[i] / pos) % 10;
        outputArray[countArray[digit] - 1] = arr[i];
        countArray[digit]--;
    }

    for (int i = 0; i < n; i++){
        arr[i] = outputArray[i];
    }
    
    printf("Count array after sorting by position %d: ", pos);
    print_array(countArray, 10);
    printf("Output array after sorting by position %d: ", pos);
    print_array(outputArray, n);
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
