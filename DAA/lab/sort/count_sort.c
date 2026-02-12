#include <stdio.h>
#include <stdlib.h>

void count_sort(int arr[], int n)
{
    if (n <= 0)
        return;

    int k = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i];
        }
    }

    int Aux[k];
    for (int i = 0; i <= k; i++) Aux[i]=0;

    for (int i = 0; i < n; i++) Aux[arr[i]] = Aux[arr[i]] + 1;


    int j = 0;
    for (int i = 0; i <= k; i++)
    {
        while (Aux[i] > 0)
        {
            arr[j] = i;
            j++;
            Aux[i] = Aux[i] - 1;
        }
    }
}

int main()
{
    int arr[] = {2,5,7,2,5,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    count_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}