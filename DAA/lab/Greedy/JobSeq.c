#include <stdio.h>


void Print(int arr[],int t){
    for (int i=0;i<=t;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
// The Job Sequencing Algorithm
// d: array of deadlines, J: array to store the scheduled job sequence, n: total jobs
int jobSequencing(int d[], int J[], int n) {
    
    // Step 1: Initialize the schedule
    d[0] = 0;        
    J[0] = 0;        
    J[1] = 1;        // Always take the #1 highest paying job first
    int k = 1;       // Track how many jobs we have scheduled


    // Step 2: Try to schedule the remaining jobs
    for (int i = 2; i <= n; i++) {
        int r = k;
        // printf("Main for i=>%d ; r=>%d",i,r);
        // printf("\n before while");
        // printf("\n(d[J[r]] > d[i]) && (d[J[r]] != r))");
        // printf("\n%d >= %d && %d != %d",d[J[r]],d[i],d[J[r]],r);
        // Step 3: Find a valid time slot by scanning backwards
        while ((d[J[r]] > d[i]) && (d[J[r]] != r)) {
            // printf("\nJ=>");
            // Print(J,k);
            // printf("\nd=>");
            // Print(d,n);
            // printf("\n(d[J[r]] > d[i]) && (d[J[r]] != r))");
            // printf("\n%d >= %d && %d != %d",d[J[r]],d[i],d[J[r]],r);
            r = r - 1;
            // printf("\nwhile i=>%d ; r=>%d",i,r);
        }
        // printf("\nk => %d",k);
        // Step 4: Insert the job if there is room
        // printf("\n before if");
        // printf("\n(d[J[r]] <= d[i]) && (d[i] > r))");
        // printf("\n%d <= %d && %d > %d",d[J[r]],d[i],d[J[r]],r);
        if ((d[J[r]] <= d[i]) && (d[i] > r)) {
            
            // printf("\n\nif\n");
            // printf("\n(d[J[r]] <= d[i]) && (d[i] > r))");
            // printf("\n%d <= %d && %d > %d",d[J[r]],d[i],d[J[r]],r);
            // Shift previously scheduled jobs to the right to make space
            // printf("\n C=>For q=>%d to %d",k,r+1);
            for (int q = k; q >= r + 1; q--) {
                // printf("\n C=>For q=>%d to %d",q,r+1);
                J[q + 1] = J[q];
            }
            // printf("\nJ=>");
            // Print(J,k);
            // printf("\nd=>");
            // Print(d,n);
            
            // Insert the new job into the open slot
            J[r + 1] = i;
            k = k + 1;
            // printf("\nk in for =>%d",k);
        }
        // printf("\nLast \n");
        // printf("J=>");
        // Print(J,k);
        // printf("\nd=>");
        // Print(d,n);
        // printf("============================");
    }
    
    // Step 5: Return the total number of successfully scheduled jobs
    return k; 
}

int main() {
    int n = 5;
    
    // We add a '0' at the start of these arrays to force 1-based indexing.
    // Notice the profits are ALREADY sorted highest to lowest, as the algorithm requires!
    int p[] = {0, 20, 15, 10, 5, 1}; 
    int d[] = {0, 2, 2, 1, 3, 3};
    
    // Array to store our final sequence of job indices
    int J[n + 1]; 
    
    // Run the algorithm
    int k = jobSequencing(d, J, n);
    
    // Print the results
    printf("Total jobs successfully scheduled: %d\n", k);
    printf("Optimal Job Sequence: ");
    
    int totalProfit = 0;
    
    // Loop through our scheduled jobs to print them and calculate total profit
    for (int i = 1; i <= k; i++) {
        printf("Job%d ", J[i]);
        totalProfit += p[J[i]];
    }
    
    printf("\nTotal Maximum Profit: %d\n", totalProfit);
    
    return 0;
}