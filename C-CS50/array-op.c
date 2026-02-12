#include <stdio.h>

// Using array notation [] which is equivalent to a pointer
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// This function now returns the new size of the array
int insert(int arr[], int size, int value, int position) {
    // Check if the array is full or the position is invalid
    if (size >= 100 || position < 0 || position > size) {
        printf("Invalid position or array is full\n");
        return size; // Return original size if insertion fails
    }

    // Shift elements to the right to make space
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new value
    arr[position] = value;
    
    // Return the new, incremented size
    return size + 1; 
}

int main() {
    int array[100] = {0, 1, 2, 4, 5};
    int size = 5; // Current number of elements

    printf("Original array: ");
    printArray(array, size);

    // Update the size variable with the value returned by the insert function
    size = insert(array, size, 3, 3);

    printf("Array after insertion: ");
    printArray(array, size);

    return 0;
}