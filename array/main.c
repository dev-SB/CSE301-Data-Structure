#include <stdio.h>

void insert(int arr[], int value, int size);
int secondLargest(int arr[],int size);
void delete(int arr[], int index, int size);
void print(int arr[],int size);
int main() {
    int size=0, value=0;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &value);
    insert(arr, value, size);
    int index;
    scanf("%d", &index);
    delete(arr, index, size);
    printf("%d\n",secondLargest(arr);
    return 0;
}

void insert(int arr[], int value, int size) {
    arr[size]=value;
    print(arr,size);
}

void delete(int arr[], int index, int size){
    for(int i=index;i<size;i++){
        arr[i+1]=arr[i];
    }
    arr[size]=0;
    print(arr,size);
}
void print(int arr[],int size){
    for(int i=0;i<=size;i++){
        printf("%d ",arr[i]);
    }printf("\n");
}
int secondLargest(int arr[]){
    int largest=0;
    int secLar=0;
    for(int i=0;i<size;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }else if(arr[i]<largest && arr[i]>secLar){
            secLar=arr[i];
        }
    }
    return secLar;
}
