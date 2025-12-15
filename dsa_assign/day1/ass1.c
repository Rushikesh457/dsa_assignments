#include <stdio.h>
#define size 7

// 1. Write a linear search algorithm to return index of last occurance of key.

int linear_search(int key, int arr[]);


int main()
{
    int arr[size] = {55, 70 ,65, 70, 75, 75, 70};
    int key;
    printf("please enter the key: ");
    scanf("%d", &key);

    int index = linear_search(key, arr);
    if(index == -1){
        printf("key %d not found\n", key);
    }
    else{
        printf("key %d found at index %d\n", key, index);
    }

    

    return 0;
}

int linear_search(int key, int arr[])
{
    int key_index = -1;
    // {55, 70 ,65, 70, 75, 75, 70};
    for(int i=0; i<size; i++) {
        if(arr[i] == key){
            key_index = i;
        }
    }
    
    return key_index;
}