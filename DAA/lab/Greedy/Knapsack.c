#include <stdio.h>

void Knapsack(float m, int n, float weight[], float profit[]) {
    

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

int Sorting(float arr[], float arr1[], float arr2[], int n) {
    int gap = n / 2;
    int P1,P2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            float temp1 = arr1[i];
            float temp2 = arr2[i];

            int j = i;
            while ((j >= gap) && (arr[j - gap] < temp)) {
                arr[j] = arr[j - gap];
                arr1[j] = arr1[j-gap];
                j = j - gap;
            }
            arr[j] = temp;
            arr1[j] = temp1;
            arr2[j] = temp2;
        }
        gap = gap / 2;
    }
}

int main() {
    float m;
    int n;
    printf("Enter the no. of things :");
    scanf("%d",&n);

    float profit[n];
    float weight[n];
    float ratio[n];

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

    printf("By Weight :\n");
    Sorting(weight, profit, ratio, n);
    printf("Weight : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", weight[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    printf("Profit : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", profit[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    Knapsack(m, n, weight, profit);

    printf("By Profit :\n");
    Sorting(profit, weight, ratio, n);
    printf("Weight : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", weight[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    printf("Profit : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", profit[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    Knapsack(m, n, weight, profit);

    
    for (int i = 0;i < n;i++) {
        ratio[i] = profit[i]/weight[i];
    }
    printf("Ratio : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", ratio[i], (i < n - 1) ? ", " : "");
    }
    Sorting(ratio, profit, weight, n);
    printf("\nBy Ratio :\n");
    Sorting(profit, weight, ratio, n);
    printf("Weight : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", weight[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    printf("Profit : ");
    for (int i = 0; i < n; i++) {
    printf("%.2f%s ", profit[i], (i < n - 1) ? ", " : "");
    }
    printf("\n");
    Knapsack(m, n, weight, profit);

}