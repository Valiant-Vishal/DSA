#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertbegin(struct Node* head, int newdata){

    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = head;
    return newnode;
    

};


void printList(struct Node* ptr){
    while (ptr != NULL){
        printf("Elements in the linked list: %d\n",ptr -> data);
        ptr = ptr -> next;

    }
    
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    head =  (struct Node*) malloc(sizeof(struct Node));
    first = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;
    
    second->data = 3;
    second->next = NULL;

    printList(head);

    head = insertbegin(head, 0);

    printList(head);
}

