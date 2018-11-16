#include <stdio.h>

void push(int value, int *top, int stack[]);

int peek(int stack[], int *top);

int pop(int stack[], int *top);

int isFull(int *top);

int isEmpty(int *top);

void display(int stack[], int *top);

int main() {
    int stack[10];
    int top = -1;
    push(1, &top, stack);
    push(2, &top, stack);
    push(3, &top, stack);
    int v=peek(stack, &top);
    printf("%d ", peek(stack, &top));
    printf("%d ", pop(stack, &top));
    push(4, &top, stack);
    push(5, &top, stack);
    push(6, &top, stack);
    push(7, &top, stack);
    push(8, &top, stack);
    push(9, &top, stack);
    push(10, &top, stack);
    display(stack, &top);
    return 0;
}

void push(int value, int *top, int stack[]) {
    if (isFull(top) == 1) {
        printf("Stack is full");
        return;
    } else {
        stack[++*top] = value;
    }
}

int peek(int stack[], int *top) {
    if (isEmpty(top) == 1) {
        printf("Stack is empty\n");
        return 0;
    } else {
        return stack[*top];
    }
}

int pop(int stack[], int *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return 0;
    } else {
        int temp=stack[*top];
        --*top;
        return temp;
    }
}

int isFull(int *top) {
    if (*top < 9) {
        return 0;
    } else {
        return 1;
    }
}

int isEmpty(int *top) {
    if (*top == -1) {
        return 1;
    } else {
        return 0;
    }
}
void display(int stack[],int *top){
    for(int i=*top;i>=0;i--){
        printf("%d ",stack[i]);

    }
}
