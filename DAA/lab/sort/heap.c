#include <stdio.h>
#include <stdlib.h>

int main() {

    int n ;

    printf("Enter the number of elements:\n");
    scanf("%d", &n); 
    int *ptr = (int*)malloc(n * sizeof(int));

   
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

   
    for (int i = 0; i < n; i++) {
        int get ;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &get);
        ptr[i] = get;

    }
    
    for (int i = 0; i < 5; i++) {
    printf("Address: %p | Value: %d\n", (void*)&ptr[i], ptr[i]);
    }
    free(ptr);
    ptr = NULL;

    return 0;
}