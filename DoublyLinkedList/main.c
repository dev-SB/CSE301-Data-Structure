#include <stdio.h>
#include<malloc.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node **head);

void push(int data, struct Node **head);

void pushAtLast(int data, struct Node **head);

void pushBeforeValue(int data, int value, struct Node **head);

void pushAfterValue(int data, int value, struct Node **head);

void delete(struct Node **head);

void deleteValue(int value, struct Node **head);

void deleteEnd(struct Node **head);

void deleteBeforeValue(int value, struct Node **head);

void deleteAfterValue(int value, struct Node **head);

void reverse(struct Node **head);

int main() {
    struct Node *head = NULL;
    push(8, &head);
    push(6, &head);
    display(&head);
    push(3, &head);
    push(2, &head);
    push(1, &head);
    display(&head);
    pushAtLast(9, &head);
    pushBeforeValue(4, 6, &head);
    pushAfterValue(5, 4, &head);
    pushAfterValue(7, 6, &head);
    display(&head);
    delete(&head);
    display(&head);
    deleteValue(3,&head);
    display(&head);
    deleteEnd(&head);
    display(&head);
    deleteBeforeValue(5,&head);
    display(&head);
    deleteAfterValue(5,&head);
    display(&head);
    reverse(&head);
    display(&head);
    return 0;
}

void display(struct Node **head) {
    printf("\n");
    struct Node *ptr = *head;
    while (ptr->next != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void push(int data, struct Node** head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = *head;
    node->prev = NULL;
    if((*head)!=NULL){
        (*head)->prev=node;
    }

    *head=node;
}

void pushAtLast(int data, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    struct Node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = node;
    node->prev = ptr;
}

void pushBeforeValue(int data, int value, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    struct Node *ptr = *head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    struct Node *pPtr = ptr->prev;
    node->next = ptr;
    node->prev = pPtr;
    pPtr->next = node;
    ptr->prev = node;

}

void pushAfterValue(int data, int value, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    struct Node *ptr = *head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    node->next = ptr->next;
    ptr->next = node;
    node->prev = ptr;
    node->next->prev = node;
}

void delete(struct Node **head) {
    struct Node *ptr = *head;
    *head = ptr->next;
    ptr->next->prev = NULL;
    free(ptr);
}

void deleteValue(int value, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->data != value) {
        ptr=ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
}

void deleteEnd(struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
}

void deleteBeforeValue(int value, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    ptr->prev->prev->next = ptr;
    struct Node *dPtr = ptr->prev;
    ptr->prev = ptr->prev->prev;
    free(dPtr);
}

void deleteAfterValue(int value, struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    struct Node *delPtr = ptr->next;
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
    free(delPtr);

}

void reverse(struct Node **head) {
    struct Node *ptr = *head;
    struct Node *nPtr = *head;
    while (ptr->next != NULL) {
        nPtr = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = nPtr;
        ptr = nPtr;
    }
    ptr->next = ptr->prev;
    ptr->prev = NULL;
    *head = ptr;

}