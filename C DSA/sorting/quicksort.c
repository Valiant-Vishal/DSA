#include <stdio.h>

int quicksort(int beg, int end, int arr[])
{

    int i = beg;
    int j = end;
    int pivot = arr[(beg + end) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        
    }
    
    if (beg < j)
    {
        quicksort(beg, j, arr);
    }
    if (i < end)
    {
        quicksort(i, end, arr);
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
    
    quicksort(0, n-1, arr);
    
    printf("Sorted array: ");
    for (int l = 0; l < n; l++)
    {
        printf("%d ", arr[l]);
    }
    return 0;
}

