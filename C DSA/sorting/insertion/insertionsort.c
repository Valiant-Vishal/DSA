#include<stdio.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

void printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memCounter;
    BOOL result = GetProcessMemoryInfo(GetCurrentProcess(), 
                                       &memCounter, 
                                       sizeof(memCounter));
    
    if (result) {
        printf("Memory usage: %u bytes\n", memCounter.WorkingSetSize);
    }
}

int main()
{
    int i, j, temp; 

    int arr[] = {
    6702, 9246, 4029, 316, 5185, 3558, 9799 };
    

    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start = clock();
    for (i=1;i<n;i++)
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
    clock_t end = clock();
    double time_taken_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken to sort %d elements: %f seconds\n", n, time_taken_ms);
    printMemoryUsage();
    return 0;

}