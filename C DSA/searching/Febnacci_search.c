#include <stdio.h>
int min(int a, int b){
    return (a > b) ? b : a;
}
int FibSearch(int array[], int n, int x) 
{
    int fibM_2 = 0;
    int fibM_1 = 1;
    int fibM = fibM_2 + fibM_1;
    
    while (fibM <= n)
    {
        fibM_2 = fibM_1;
        fibM_1 = fibM;
        fibM = fibM_2 + fibM_1;
    }
    int offset = -1;
    int k = 0;
    while (fibM > 1)
    {
        
        int i = min(offset + fibM_2, n - 1);
        //printf("\nopening -> M=%d\nM1=%d\nM2=%d\noffset=%d\ni=%d\n",fibM,fibM_1,fibM_2,offset,i);
    
        if (array[i] < x){
            fibM = fibM_1;
            fibM_1 = fibM_2;
            fibM_2 = fibM - fibM_1;
            offset = i;
            //printf("\n1st -> M=%d\nM1=%d\nM2=%d\noffset=%d\ni=%d\n",fibM,fibM_1,fibM_2,offset,i);
        }
        else if(array[i] > x){
            fibM = fibM_2;
            fibM_1 = fibM_1 - fibM_2;
            fibM_2 = fibM - fibM_1;
            //printf("\n2nd -> M=%d\nM1=%d\nM2=%d\noffset=%d\ni=%d\n",fibM,fibM_1,fibM_2,offset,i);
        }
        else 
            return i;

        //printf("iteration -> %d\nn -> %d\n",++k,n);
    }
    
    return -1;
    
    
}

int main() 
{
  int x,s;
  printf("Enter the no. of elements you want to enter:");
  scanf("%d",&s);
  int arr[s];
  for (int i;i<s;i++)
  {
    printf("Enter element %d:",i+1);
    scanf("%d", &arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Enter a number to search: ");
  scanf("%d", &x);
  int result = FibSearch(arr, n, x);

  (result == -1) ? printf("Element not found") : printf("Element found at index: %d", result);
}
