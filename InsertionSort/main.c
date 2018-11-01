#include <stdio.h>

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int k = i;
        for (int j = k - 1; j >= 0; j--) {
            if (arr[j] > arr[k]) {
                arr[j] = arr[j] ^ arr[k];
                arr[k] = arr[j] ^ arr[k];
                arr[j] = arr[j] ^ arr[k];
                k--;
            }else{
                break;
            }
        }
    }
    print(arr, size);
}

int main() {
    int arr[] = {2, 5, 3, 10, 16, 9, 1, 7, 8, 4};

    int size = (int) sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    return 0;
}