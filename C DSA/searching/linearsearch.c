#include <stdio.h>

int search(int array[], int n, int x) {
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int x,s;
  printf("Enter the no. of elements you want to enter:");
  scanf("%d",&s);
  int arr[s];
  for (int i;i<s;i++){
    printf("Enter element %d:",i+1);
    scanf("%d", &arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Enter a number to search: ");
  scanf("%d", &x);
  int result = search(arr, n, x);

  (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);

}
