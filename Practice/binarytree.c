#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int newdata);
void search(struct node *root, int key);
void displayInOrder(struct node *root);
void displayPreOrder(struct node *root);
struct node *createNode(int data);

int main() {
    struct node *root = NULL;
    insert(&root, 50);
    insert(&root, 59);
    insert(&root, 12);
    insert(&root, 20);
    insert(&root, 67);
    insert(&root, 5);

    printf("\n\nCurrent BST (In Order Traversal): \n");
    displayInOrder(root);

    printf("\n\nCurrent BST (Pre Order Traversal): \n");
    displayPreOrder(root);

    int key;
    printf("\n\nEnter an element to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}

struct node *createNode(int data) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void insert(struct node **root, int newdata) {
    if (*root == NULL) {
        *root = createNode(newdata);
    } else {
        if (newdata < (*root)->data) {
            insert(&((*root)->left), newdata);
        } else {
            insert(&((*root)->right), newdata);
        }
    }
}

void search(struct node *root, int key) {
    if (root == NULL) {
        printf("\nSearch unsuccessful!\n%d does not exist in the BST\n", key);
    } else if (key < root->data) {
        search(root->left, key);
    } else if (key > root->data) {
        search(root->right, key);
    } else {
        printf("\n%d found in the BST.\n", key);
    }
}

void displayInOrder(struct node *root) {
    if (root != NULL) {
        displayInOrder(root->left);
        printf("%d\t", root->data);
        displayInOrder(root->right);
    }
}

void displayPreOrder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        displayPreOrder(root->left);
        displayPreOrder(root->right);
    }
}

