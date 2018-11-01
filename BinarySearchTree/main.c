#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *node(int value);

void insert(int value, struct Node **root);

void inOrder(struct Node *root);

void preOrder(struct Node *root);

void postOrder(struct Node *root);

void search(int value, struct Node **root);

int main() {
    int noOfValues;
    struct Node *root = NULL;
    scanf("%d", &noOfValues);
    while (noOfValues--) {
        int value;
        scanf("%d", &value);
        insert(value, &root);
    }
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    search(5, &root);
    return 0;
}

void insert(int value, struct Node **root) {
    struct Node *temp = node(value);
    struct Node *ptr = *root;
    if (*root == NULL) {
        *root = temp;
    } else {
        while (1) {
            if (ptr->data > value) {
                if (ptr->left == NULL) {
                    ptr->left = temp;
                    break;
                } else {
                    ptr = ptr->left;
                }
            } else {
                if (ptr->right == NULL) {
                    ptr->right = temp;
                    break;
                } else {
                    ptr = ptr->right;
                }
            }
        }
    }
}

struct Node *node(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = value;
    return node;
}

void inOrder(struct Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d,", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d,", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d,", root->data);
    }
}

void search(int value, struct Node **root) {
    struct Node *ptr = *root;
    while (ptr != NULL) {
        if(ptr->data==value){
         return;
        }
        printf("%d,", ptr->data);
        if (value < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }
    printf("Element not found");
}