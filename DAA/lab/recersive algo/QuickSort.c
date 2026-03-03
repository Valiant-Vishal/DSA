#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int QuickSort(int arr[], int LB, int HB) {
    bool flag = true;

    if (LB < HB){
        int i=LB, j=HB+1, key=arr[LB];
        while (flag == true){
            i++;
            while (arr[i]<key)i++;
            j--;
            while (arr[j]>key)j--;
            if (i<j){
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
    
            else flag = false;
            int temp = arr[LB];
            arr[LB] = arr[j];
            arr[j] = temp;
        }
    QuickSort(arr, LB, j-1);
    QuickSort(arr, j+1, HB);
    }
}


int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    QuickSort(arr,0 , n-1); 
    

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d%s ", arr[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    return 0;
}

