#include <stdio.h>

int arr[] = {2, 5, 3, 10, 16, 9, 1, 7, 8, 4};

int partition(int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    int j = start;
    while (j < end) {
        if (arr[j] <= pivot) {
            i += 1;
            if (i != j) {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
        }
        j += 1;
    }
    i += 1;
    if (i != end) {
        arr[i] = arr[i] ^ arr[end];
        arr[end] = arr[i] ^ arr[end];
        arr[i] = arr[i] ^ arr[end];
    }
    return i;
}

void quickSort(int start, int end) {
    if (start < end) {
        int middle = partition(start, end);
        quickSort(start, middle - 1);
        quickSort(middle + 1, end);
    }
}

int main() {

    int size = (int) sizeof(arr) / sizeof(arr[0]);
    quickSort(0, size - 1);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

