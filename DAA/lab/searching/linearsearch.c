#include <stdio.h>

int search(int array[], int n, int x) {
    int i = 0;
    

    while (array[i] != x) {
        i++;
    }
    if (i < n) {
        return i;
    } else {
        return -1;
    }
}


int main() {
  int x,s;
  printf("Enter the no. of elements you want to enter:");
  scanf("%d",&s);
  int arr[s];
  for (int i=0;i<s;i++){
    printf("Enter element %d:",i+1);
    scanf("%d", &arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Enter a number to search: ");
  scanf("%d", &x);
  int result = search(arr, n, x);

  (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);

}
