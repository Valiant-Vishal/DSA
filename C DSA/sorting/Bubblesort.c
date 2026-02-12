#include <stdio.h>

int main() {
    int i, j, temp,s; 

    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &s);
    int arr[s]; 

    for (int k = 0; k < s; k++) { 
        printf("Enter element %d: ", k + 1);
        scanf("%d", &arr[k]);
    }

    int n = s; 
    for (int i = 0; i < n - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = 1;
        }
    }
    if (swapped == 0) {
        break; 
    }
    } 

    printf("\nSorted array: ");
    for (i = 0; i < s; i++) {
        printf("%d", arr[i]);
        if (i < s - 1) { 
            printf(", ");
        }
    }
    printf("\n"); 

    return 0;
}