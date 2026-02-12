/*
Step  1:Graph Structure: Represent the graph as an array of linked lists. The array index represents the vertex (e.g., array[0] is for vertex 0).

Step  2:List Node Structure: Each node in a linked list contains the destination vertex number (dest) and a next pointer.

Step  3:Add Edge (src, dest): Create a new node for dest and insert it at the head of array[src]'s list. For an undirected graph, also create a src node and add it to the head of array[dest]'s list.

Step  4:Add Vertex: Increment the total vertex count. Use realloc to resize the main array to fit the new count. Initialize the new vertex's list head to NULL.

Step  5:Print Graph: Iterate through the entire array. For each vertex, traverse its linked list and print all dest values.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in adjacency list
typedef struct AdjListNode {
    int dest;                      // Adjacent vertex
    struct AdjListNode* next;      // Pointer to next adjacent node
} AdjListNode;

// Structure to represent adjacency list
typedef struct AdjList {
    AdjListNode* head;             // Pointer to the head node of list
} AdjList;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;               // Number of vertices
    AdjList* array;                // Array of adjacency lists
} Graph;

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = V;

    // Create an array of adjacency lists
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\nAdjacency list of vertex %d\n head", v);
        while (pCrawl) {
            printf(" -> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to dynamically add a new node to the graph
void addNode(Graph** graphRef) {
    Graph* graph = *graphRef;
    int newVertex = graph->numVertices;
    graph->numVertices++;

    // Reallocate memory for the adjacency list array
    graph->array = (AdjList*)realloc(graph->array, graph->numVertices * sizeof(AdjList));
    graph->array[newVertex].head = NULL;

    printf("\nNew node %d added successfully!\n", newVertex);
}

// Function to add adjacent nodes to a particular node
void addAdjacentNodes(Graph* graph) {
    int node, adj, count;
    printf("\nEnter the node to which you want to add adjacent nodes: ");
    scanf("%d", &node);

    if (node >= graph->numVertices) {
        printf("Invalid node number!\n");
        return;
    }

    printf("How many adjacent nodes do you want to add to node %d? ", node);
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter adjacent node #%d: ", i + 1);
        scanf("%d", &adj);

        if (adj >= graph->numVertices) {
            printf("Node %d does not exist. Add it first.\n", adj);
            continue;
        }
        addEdge(graph, node, adj);
    }
}

int main() {
    int V, choice;

    printf("Enter initial number of vertices: ");
    scanf("%d", &V);

    Graph* graph = createGraph(V);

    while (1) {
        printf("\n===== GRAPH MENU =====");
        printf("\n1. Add Edge");
        printf("\n2. Add Node");
        printf("\n3. Add Adjacent Nodes to a Node");
        printf("\n4. Display Graph");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int src, dest;
            printf("Enter source and destination: ");
            scanf("%d %d", &src, &dest);
            if (src < V && dest < V)
                addEdge(graph, src, dest);
            else
                printf("Invalid vertices!\n");
            break;
        }
        case 2:
            addNode(&graph);
            break;
        case 3:
            addAdjacentNodes(graph);
            break;
        case 4:
            printGraph(graph);
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}