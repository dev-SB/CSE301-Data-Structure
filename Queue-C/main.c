#include <stdio.h>

void enqueue(int arr[], int *front, int *rear, int value);

int dequeue(int arr[], int *front, int *rear);

void display(int arr[], int *front, int *rear);

int isEmpty( int *rear);

int isFull( int *front, int *rear);

int main() {
    int front = 0, rear = 0;
    int arr [10];

    enqueue(arr, &front, &rear, 1);
    enqueue(arr, &front, &rear, 9);
    enqueue(arr, &front, &rear, 8);
    printf("%d\n", dequeue(arr, &front, &rear));
    enqueue(arr, &front, &rear, 7);
    enqueue(arr, &front, &rear, 6);
    enqueue(arr, &front, &rear, 5);
    printf("%d\n", dequeue(arr, &front, &rear));
    enqueue(arr, &front, &rear, 4);
    enqueue(arr, &front, &rear, 3);
    enqueue(arr, &front, &rear, 2);
    printf("%d\n", dequeue(arr, &front, &rear));
    display(arr, &front, &rear);
    return 0;
}

void enqueue(int arr[], int *front, int *rear, int value) {
    if (isFull(front, rear) == 0) {
        arr[*rear] = value;
        *rear+=1;
    } else {
        printf("Queue is full\n");
    }
}

int dequeue(int arr[], int *front, int *rear) {
    if (isEmpty(rear) == 0) {
        int temp = arr[*front];
        for (int i = *front; i < *rear; i++) {
            arr[i] = arr[i + 1];
        }
        *rear-=1;
        return temp;
    } else {
        printf("Queue is empty\n");
    }
}

void display(int arr[], int *front, int *rear) {
    for (int i = *front; i < *rear; i++) {
        printf("%d, ", arr[i]);
    }
}


int isEmpty(int *rear) {
    if (rear == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(int *front, int *rear) {
    if (*rear == 10 && *front == 0) {
        return 1;
    } else {
        return 0;
    }
}

