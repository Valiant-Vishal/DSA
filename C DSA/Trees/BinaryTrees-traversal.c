/*
Step 1: If the current tree (root) is empty, create a new node with the value and return it as the new root.

Step 2: If the new value is less than the root's data, set the root's left child to the result of recursively inserting the value into the left subtree.

Step 3: If the new value is greater than the root's data, set the root's right child to the result of recursively inserting the value into the right subtree.

Step 4: (If the value is equal, no change is made).

Step 5: Return the pointer to the original root.
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Inorder traversal: left, root, right
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Preorder traversal: root, left, right
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Postorder traversal: left, right, root
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int nodeValue;
    char choice;


    do {
        printf("Input a value to insert into the binary tree: ");
        scanf("%d", &nodeValue);
        root = insertNode(root, nodeValue);
        printf("Want to insert another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nIn-order Traversal: ");
    inOrderTraversal(root);
    printf("\nPre-order Traversal: ");
    preOrderTraversal(root);
    printf("\nPost-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    freeTree(root);
    return 0;
}