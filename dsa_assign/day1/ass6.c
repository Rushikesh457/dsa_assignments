#include <stdio.h>
#include <stdlib.h>
#define size 7

/*
6. To find rank of an element in a stream of integers. 
    rank: rank of a given integer "x", in stream is "total
    no. of elements's less than or equal to x (including x).
        Input: { 10, 20, 15, 3, 4, 4, 1 }
        Ouput: Rank of 4 is: 4
*/

int linear_search(int *arr, int key);

int main()
{
    int arr[size] = { 10, 20, 15, 3, 4, 4, 1 };
    int key;
    printf("please enter the element you want to find the rank of: ");
    scanf("%d", &key);
    int rank = linear_search(arr, key);
    if(rank == -1)
        printf("element %d not found\n", key);
    else
        printf("element %d has rank: %d\n", key, rank);


    return 0;
}

int linear_search(int *arr, int key)
{
    int rank=0;
    int flag_element_found=0;
    for(int i=0; i<size; i++)
    {
        /*
        rank: rank of a given integer "x", in stream is "total
        no. of elements's less than or equal to x (including x).
        */
        // { 10, 20, 15, 3, 4, 4, 1 }
        if(key <= arr[i])
            rank++;
        //printf("rank++ : %d\n", rank);
        if(key == arr[i])
            flag_element_found = 1;

    }
    if(flag_element_found == 1)
        return rank;
    else
        return -1;
}
