#include <stdio.h>

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int tempIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[tempIndex]) {
                tempIndex = j;
            }
        }
        if (i != tempIndex) {
            arr[i] = arr[i] ^ arr[tempIndex];
            arr[tempIndex] = arr[i] ^ arr[tempIndex];
            arr[i] = arr[i] ^ arr[tempIndex];
        }
    }
    print(arr, size);
}

int main() {
    int arr[] = {2, 5, 3, 10, 16, 9, 1, 7, 8, 4};
    int size = (int) sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    return 0;
}