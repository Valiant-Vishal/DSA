#include<stdio.h>
#include<stdbool.h>

#define max 10
#define INF 9999

int n = 4;
int min_cost = INF;
int C[4][4] = {
{0, 10, 15, 20},
{5, 0, 9, 10},
{6, 13, 0, 12},
{8, 8, 9, 0}
};

int best_route[max];    
int current_route[max]; 

void printPath() {
    printf("Path: ");
    for (int i = 0; i <= n; i++) {
        printf("%d%s", best_route[i], (i == n) ? "" : " -> ");
    }
    printf("\n");
}

void Findpath ( int current,int visitedNode,int currentCost,bool visited[]) {

    current_route[visitedNode - 1] = current;

    if (visitedNode == n) {
        int final_cost = currentCost + C[current][0];

        if (final_cost < min_cost) {
            min_cost = final_cost;
            for (int i = 0; i < n; i++) {
                best_route[i] = current_route[i];
            }
            best_route[n] = 0;
        }
        return;
    }
    for (int nextNode = 0 ; nextNode < n ; nextNode++ ) {
        if ( visited[nextNode] == false) {
            visited[nextNode] = true;
            Findpath(nextNode, visitedNode + 1, currentCost + C[current][nextNode], visited );
            visited[nextNode] = false;
        }

    }

}


int main(){
    
    bool visited[max] = {false};
    visited[0] = true;

    Findpath(0, 1, 0, visited);

    printf("The minimum cost to visit all cities and return is: %d\n", min_cost);

    printPath(4);

    return 0;
}