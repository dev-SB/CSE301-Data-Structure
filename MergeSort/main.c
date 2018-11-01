#include <stdio.h>

int ansArr[10];
int arr[] = {2, 5, 3, 10, 16, 9, 1, 7, 8, 4};

void print(int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void merge(int minIndex, int midIndex, int maxIndex) {
    int inOne, inTwo, i;
    for (inOne = minIndex, inTwo = midIndex + 1, i = minIndex; inOne <= midIndex && inTwo <= maxIndex; i++) {
        if (arr[inOne] <= arr[inTwo]) {
            ansArr[i] = arr[inOne];
            inOne++;
        } else {
            ansArr[i] = arr[inTwo];
            inTwo++;
        }
    }
    while (inOne <= midIndex) {
        ansArr[i++] = arr[inOne++];
    }
    while (inTwo <= maxIndex) {
        ansArr[i++] = arr[inTwo++];
    }
    for(i=minIndex;i<=maxIndex;i++){
        arr[i]=ansArr[i];
    }

}

void sort(int minIndex, int maxIndex) {
    int midIndex;
    if (minIndex < maxIndex) {
        midIndex = (minIndex + maxIndex) / 2;
        sort(minIndex, midIndex);
        sort(midIndex + 1, maxIndex);
        merge(minIndex, midIndex, maxIndex);
    } else {
        return;
    }

}

int main() {
    int size = (int) sizeof(arr) / sizeof(arr[0]);
    sort(0, size - 1);
    print(10);
    return 0;
}