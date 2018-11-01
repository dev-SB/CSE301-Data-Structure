#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
};

void push(int data, struct Node **head);

void pushAtLast(int data, struct Node **head);

void pushBeforeVal(int data, int val, struct Node **head);

void pushAfterValue(int data, int val, struct Node **head);

void display(struct Node **head);

void deleteValue(int val, struct Node **head);

void deleteEnd(struct Node **head);

void deleteBeforeValue(int val, struct Node **head);

void deleteAfterValue(int val, struct Node **head);

int main() {
    struct Node *head = NULL;
    push(8, &head);
    push(6, &head);
    push(3, &head);
    push(2, &head);
    push(1, &head);
    display(&head);
    pushAtLast(9, &head);
    pushBeforeVal(4, 6, &head);
    pushAfterValue(5, 4, &head);
    pushAfterValue(7, 6, &head);
    display(&head);
    deleteValue(3, &head);
    display(&head);
    deleteEnd(&head);
    display(&head);
    deleteBeforeValue(5,&head);
    display(&head);
    deleteAfterValue(5,&head);
    display(&head);
    return 0;
}

void push(int data, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (*head != NULL) {
        struct Node *ptr = *head;
        node->data = data;
        node->next = *head;
        while (ptr->next != *head) {
            ptr = ptr->next;
        }
        ptr->next = node;
        (*head) = node;
    } else {
        node->data = data;
        (*head) = node;
        node->next = node;
    }
}

void pushAtLast(int data, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    struct Node *ptr = *head;
    node->data = data;

    while (ptr->next != *head) {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->next = *head;
}

void pushBeforeVal(int data, int val, struct Node **head) {
    struct Node *ptr = *head;
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    while (ptr->next->data != val) {
        ptr = ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;
}

void pushAfterValue(int data, int val, struct Node **head) {
    struct Node *ptr = *head;
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    while (ptr->data != val) {
        ptr = ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;
}

void display(struct Node **head) {
    printf("\n");
    struct Node *ptr = *head;
    while (ptr->next != *head) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("%d\n", ptr->data);
}

void deleteValue(int val, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->next->data != val) {
        ptr = ptr->next;
    }
    struct Node *delPtr = ptr->next;
    ptr->next = ptr->next->next;
    free(delPtr);

}

void deleteEnd(struct Node **head) {
    struct Node *ptr = *head;
    struct Node *pPtr;
    while (ptr->next->next != *head) {
        ptr = ptr->next;
    }
    pPtr = ptr;
    ptr=ptr->next;
    pPtr->next = *head;
    free(ptr);
}

void deleteBeforeValue(int val, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->next->next->data != val) {
        ptr = ptr->next;
    }
    struct Node *delPtr = ptr->next;
    ptr->next = ptr->next->next;
    free(delPtr);
}

void deleteAfterValue(int val, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->data != val) {
        ptr = ptr->next;
    }
    struct Node *delPtr = ptr->next;
    ptr->next = ptr->next->next;
    free(delPtr);

}
