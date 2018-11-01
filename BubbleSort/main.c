#include <stdio.h>

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int arr[], int size) {
    while (1) {
        int isSwapped = 0;
        for (int i = 0; i < size-1; i++) {

            if (arr[i] > arr[i + 1]) {
                arr[i] = arr[i] ^ arr[i + 1];
                arr[i + 1] = arr[i] ^ arr[i + 1];
                arr[i] = arr[i] ^ arr[i + 1];
                isSwapped = 1;
            }
        }
        if (isSwapped == 0) {
            break;
        }
    }
    print(arr, size);
}

int main() {
    int arr[] = {2, 5, 3, 10, 16, 9, 1, 7, 8, 4};
    int size = (int) sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    return 0;
}