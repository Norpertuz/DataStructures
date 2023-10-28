#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

struct Element{
    int data;
    struct Element* left;
    struct Element* right;
};

struct Element* createElement(int data){
    struct Element* newElement = (struct Element*)malloc(sizeof(struct Element));
    if(newElement){
        newElement -> data = data;
        newElement -> left = newElement -> right = NULL;
    }

    return newElement;
}

struct Element* insert(struct Element* root, int data) {
    if (root == NULL) {
        return createElement(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(struct Element* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {

    struct Element* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}