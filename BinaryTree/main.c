#include <stdio.h>
#include <malloc.h>
#include <math.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int);

int insert(struct Node *temp, struct Node **root, int level, int filled);

int perLevel = 0;
int noOfElements = 0;
int filled = 0;

int main() {
    int value;
    struct Node *root = NULL;
    while (1) {
        int level = 1;
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        noOfElements++;
        struct Node *temp = createNode(value);
        filled = insert(temp, &root, level, filled);
    }
    return 0;
}


struct Node *createNode(int value) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = value;
    return node;
}

int insert(struct Node *temp, struct Node **root, int level, int filled) {

    if (*root == NULL) {
        *root = temp;
    } else if ((*root)->left != NULL) {
        if ((*root)->right != NULL) {
            if (level > perLevel && filled == 1) {
                filled = insert(temp, &(*root)->right, level + 1, 1);
                return filled;
            } else {
                filled = insert(temp, &(*root)->left, level + 1, 0);
                return filled;
            }
        } else {
            (*root)->right = temp;
            if (filled == 1 && noOfElements > 3) {
                filled = 0;
            } else if (noOfElements > 3) {
                filled = 1;
            }
        }
    } else {
        (*root)->left = temp;
    }
    for (int i = 0; i < noOfElements; i++) {
        if (noOfElements - 1 == (int) pow(2, i)) {
            perLevel = i;
            break;
        }
    }

    return filled;
}




