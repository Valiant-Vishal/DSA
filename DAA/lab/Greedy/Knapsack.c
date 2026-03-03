#include <stdio.h>

void Knapsack(float m, int n, float weight[], float profit[] , int menu) {
    
    if menu == 1 {
        
    }
        float x[n];
        for (int i=0;i<n;i++) {
            x[i]=0.0;
        }
        float u=m;
        int i;
        for (i=0;i<n;i++) {
            if (weight[i]>u) break;
            x[i]=1.0;u=u-weight[i];
        }
        if (i<n) {
            x[i]=u/weight[i];
        }
    
        printf("Bag : ");
        for (int i = 0; i < n; i++) {
            printf("%.2f%s ", x[i], (i < n - 1) ? ", " : "");
        }
        printf("\n");
}

int Sort(float arr[], float arr1[], int n) {
    for (int j=0;j<n;j++) {
        int item = arr[j];
        int i=j-1;
        while ((i>=1) && (item < arr[i])) {
            arr[i+1] = arr[i];
            arr1[i+1] = arr1[i];
            int i = i-1;
        }
        arr[i+1] = item;
        arr1[i+1] = arr[j];
    }
    int i=0;
    for (int k = n-1;k>=0;k--) {
        arr[i] = arr[k];
        i++;
    }
}

int main() {
    float m;
    int n;
    printf("Enter the no. of things :");
    scanf("%d",&n);

    float profit[n];
    float weight[n];

    printf("Enter the profit for the things :\n");
    for (int i=0;i<n;i++) {
        printf("%d :",i+1);
        scanf("%f",&profit[i]);
    }

    printf("Enter the weight for the things : \n");
    for (int i=0;i<n;i++) {
        printf("%d :",i+1);
        scanf("%f",&weight[i]);
    }

    printf("Enter the Knapscap capacity :");
    scanf("%f",&m);

    
    Knapsack(m, n, weight, profit);
    // printf("The Remaining Capacity : %f",maxWeight);


}