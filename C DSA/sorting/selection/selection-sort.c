#include <stdio.h>
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


int selection(int arr[],int n)
{
    for (int i = 1; i < n; i++) {
        int min = i;
        for (int j = i+1; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}


int main()
{
    int arr[] = {
    6702, 9246, 4029, 316, 5185, 3558, 9431, 8468, 285, 2872};
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start = clock();
    selection(arr,n);
    clock_t end = clock();
    double time_taken_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Sorted array: ");
    for (int l = 0; l < n; l++)
    {
        printf("%d ", arr[l]);
    }
    printf("\nTime taken to sort %d elements: %f seconds\n", n, time_taken_ms);
    printMemoryUsage();
    return 0;
}

