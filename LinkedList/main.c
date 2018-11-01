#include <stdio.h>
#include <malloc.h>

struct Node {
    int data;
    struct Node *next;
};


void display(struct Node **head);

void push(int data, struct Node **head);

void pushAtLast(int data, struct Node **head);

void pushBeforeValue(int data, int value, struct Node **head);

void pushAfterValue(int data, int value, struct Node **head);

void delete(struct Node **head);

void deleteValue(int data, struct Node **head);

void deleteEnd(struct Node **head);

void deleteBeforeValue( int value, struct Node **head);

void deleteAfterValue( int value, struct Node **head);

void reverse(struct Node **head);


int main() {
    struct Node *head = NULL;
    push(8, &head);
    push(6, &head);
    push(3, &head);
    push(2, &head);
    push(1, &head);
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

void push(int data, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = (*head);
    *head = node;
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

void pushAtLast(int data, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    struct Node *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = node;
}

void pushBeforeValue(int data, int value, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;

    struct Node *ptr = *head;
    struct Node *pPtr = *head;
    while (ptr->data != value) {
        pPtr = ptr;
        ptr = ptr->next;
    }
    pPtr->next = node;
    node->next = ptr;

}

void pushAfterValue(int data, int value, struct Node **head) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    struct Node *ptr = *head;
    struct Node *nPtr = *head;
    while (ptr->data != value) {
        ptr = ptr->next;
    }
    nPtr = ptr->next;
    ptr->next = node;
    node->next = nPtr;
}

void delete(struct Node **head) {
    struct Node *ptr = *head;
    *head = ptr->next;
    free(ptr);

}

void deleteValue(int data, struct Node **head) {
    struct Node *ptr = *head;
    struct Node *pPtr = *head;
    while (ptr->data != data) {
        pPtr = ptr;
        ptr = ptr->next;
    }
    pPtr->next = ptr->next;
    free(ptr);
}

void deleteEnd(struct Node **head) {
    struct Node *ptr = *head;
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void deleteBeforeValue( int value, struct Node **head){
    struct Node *ptr=*head;
    while(ptr->next->next->data!=value){
        ptr=ptr->next;
    }
    struct Node *delPtr=ptr->next;
    ptr->next=delPtr->next;
    free(delPtr);
}

void deleteAfterValue( int value, struct Node **head){
    struct Node* ptr=*head;
    while(ptr->data!=value){
        ptr=ptr->next;
    }
    struct Node* delPtr=ptr->next;
    ptr->next=delPtr->next;
    free(delPtr);
}

void reverse(struct Node **head){
    struct Node* ptr=*head;
    struct Node* nPtr=*head;
    struct Node* pPtr=*head;
    ptr=ptr->next;
    nPtr->next=NULL;
    while(ptr->next!=NULL){
        pPtr=nPtr;
        nPtr=ptr;
        ptr=ptr->next;
        nPtr->next=pPtr;
    }
    ptr->next=nPtr;
    *head=ptr;

}