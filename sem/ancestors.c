#include <stdio.h>
#include <stdlib.h>

#define MAX 50 

// struct node adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// struct Jungle Graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX];
};

// Function to create a new node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

//create a graph with V vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < MAX; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addPath(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}


// DFS
void dfs(int ancestor, int curNode, struct Graph* graph, int ancestors[MAX][MAX]) {
    
    struct Node* adjList = graph->adjLists[curNode];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int neighbor = temp->dest;

        if (ancestors[neighbor][ancestor] == 0) {
            // Rec. it
            ancestors[neighbor][ancestor] = 1;
            
            // Continue the neighbour
            dfs(ancestor, neighbor, graph, ancestors);
        }
        temp = temp->next;
    }
}

int main() {
    int V = 11; // pass the nno. of points 
    struct Graph* jungle = createGraph(V);

    int ancestors[MAX][MAX] = {0};


  // rec. the paths
    addPath(jungle, 1, 3);
    addPath(jungle, 1, 7);
    addPath(jungle, 2, 3);
    addPath(jungle, 2, 10);
    addPath(jungle, 2, 11);
    addPath(jungle, 3, 6);
    addPath(jungle, 4, 3);
    addPath(jungle, 4, 10);
    addPath(jungle, 4, 5);
    addPath(jungle, 5, 11);
    addPath(jungle, 6, 9);
    addPath(jungle, 6, 10);
    addPath(jungle, 7, 8);

    //DFS
    for (int i = 1; i <= V; i++) {
        dfs(i, i, jungle, ancestors);
    }

    printf("\n path List \n");
    for (int i = 1; i <= V; i++) {
        printf("Point %d : { ", i);
        
        int hasAncestor = 0;
        for (int j = 1; j <= V; j++) {
            if (ancestors[i][j] == 1) {
                printf("%d ", j);
                hasAncestor = 1;
            }
        }
        
        if (hasAncestor == 0) {
            printf("- ");
        }
        printf("}\n");
    }

    return 0;
}