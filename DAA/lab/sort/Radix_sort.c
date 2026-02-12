#include <stdio.h>
#include <stdlib.h>

void count_sort(int arr[], int n, int pos)
{
    if (n <= 0)
        return;

    int count[10];
    for (int i = 0; i < 10; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }     

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
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
    int max = getMax(arr, n);

    for (int pos = 1; max / pos > 0; pos *= 10)
    {
        count_sort(arr, n, pos);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    radix_sort(arr, n);
    printf("\nSorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
