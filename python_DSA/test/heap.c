#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A structure to represent a Min Heap
struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
};

// Function prototypes
struct MinHeap *createMinHeap(int capacity);
void MinHeapify(struct MinHeap *h, int i);
int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i)
{
    return (2 * i + 1);
}
int right(int i)
{
    return (2 * i + 2);
}

int extractMin(struct MinHeap *h);
void decreaseKey(struct MinHeap *h, int i, int new_val);
int getMin(struct MinHeap *h)
{
    return h->harr[0];
}
void deleteKey(struct MinHeap *h, int i);
void insertKey(struct MinHeap *h, int k);

// Constructor: Creates a heap of given capacity
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *h = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    h->heap_size = 0;
    h->capacity = capacity;
    h->harr = (int *)malloc(capacity * sizeof(int));
    return h;
}

// Inserts a new key 'k'
void insertKey(struct MinHeap *h, int k)
{
    if (h->heap_size == h->capacity)
    {
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    // First insert the new key at the end
    h->heap_size++;
    int i = h->heap_size - 1;
    h->harr[i] = k;

    // Fix the min heap property if it is violated
    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.
void decreaseKey(struct MinHeap *h, int i, int new_val)
{
    h->harr[i] = new_val;
    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int extractMin(struct MinHeap *h)
{
    if (h->heap_size <= 0)
        return INT_MAX;
    if (h->heap_size == 1)
    {
        h->heap_size--;
        return h->harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = h->harr[0];
    h->harr[0] = h->harr[h->heap_size - 1];
    h->heap_size--;
    MinHeapify(h, 0);

    return root;
}

// This function deletes key at index i.
void deleteKey(struct MinHeap *h, int i)
{
    decreaseKey(h, i, INT_MIN);
    extractMin(h);
}

// A recursive method to heapify a subtree with root at given index
void MinHeapify(struct MinHeap *h, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < h->heap_size && h->harr[l] < h->harr[i])
        smallest = l;
    if (r < h->heap_size && h->harr[r] < h->harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&h->harr[i], &h->harr[smallest]);
        MinHeapify(h, smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Driver program to test above functions
int main()
{
    struct MinHeap *h = createMinHeap(11);
    insertKey(h, 3);
    insertKey(h, 2);
    deleteKey(h, 1);
    insertKey(h, 15);
    insertKey(h, 5);
    insertKey(h, 4);
    insertKey(h, 45);
    printf("%d ", extractMin(h));
    printf("%d ", getMin(h));
    decreaseKey(h, 2, 1);
    printf("%d", getMin(h));

    // Free allocated memory
    free(h->harr);
    free(h);
    return 0;
}