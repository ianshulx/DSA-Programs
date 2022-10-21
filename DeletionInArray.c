#include <stdio.h>

void display(int arr[], int *size){
    printf("Array is: ");
    for (int i = 0; i < *size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int deletionBegin(int arr[], int *size){
    printf("Deletion from beginning\n");
    for(int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    *size -= 1;
    return 1;
}

int deletionEnd(int arr[], int *size){
    printf("Deletion from end\n");
    *size -= 1;
    return 1;
}

int deletionIndex(int arr[], int *size){
    int index;
    printf("Deletion at any position\n");
    printf("Enter the index from where you want to delete the element: ");
    scanf("%d", &index);
    for(int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    *size -= 1;
    return 1;
}

int main(){
    int arr[100] = {2, 4, 9, 1, 74};
    int size = 5, index = 2;
    display(arr, &size);
    deletionBegin(arr, &size);
    display(arr, &size);
    deletionEnd(arr, &size);
    display(arr, &size);
    deletionIndex(arr, &size);
    display(arr, &size);

    return 0;
}
