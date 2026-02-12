#include <stdio.h>

int main(){
    // Arithmetic operations on pointers
    int a = 20;
    int *pr = &a;
    printf("Address of a: %p\n", pr);
    printf("Address of a: %p\n", ++pr);

    int arr[] = {10, 20, 30, 40, 50};
    printf("The address of arr is %p\n", arr);
    printf("The address of arr[0] is %p\n", arr);
    printf("The address of arr[1] is %p\n", arr+1);

    
    printf("The value of arr[0] is %d\n", *arr);
    printf("The value of arr[1] is %d\n", *(arr+1));
    return 0;
}