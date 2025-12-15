#include <stdio.h>
#define size 6

void insertion_sort(int arr[size]); // arr[size] = *arr
void display(int *arr);
void insertion_sort_des(int arr[size]); // arr[size] = *arr

/*
1. Modify the selection sort algorithm to sort the array in descending order
    {30,20,60,50,10,40};
    sorted array {60, 50, 40, 30, 20, 10}
*/

int main()
{
    int arr[size] = {30,20,60,70,10,40};
    //int arr[size] = {11,22,33,44,55,66}; // sorted array
    printf("\n Before Sort :\n");
    display(arr);
    printf("\n After ascending Sort :\n");
    insertion_sort(arr);
    display(arr);
    printf("\n After descending Sort :\n");
    insertion_sort_des(arr);
    display(arr);

    return 0;
}

void insertion_sort(int arr[size]) // arr[size] = *arr
{
    int i, j, temp;
    for(i=1; i<size; i++)
    {
        temp = arr[i];
        for(j = i-1; j>=0 && temp < arr[j]; j--)
        {
            // shift arr[j] to j+1 index
            arr[j+1] = arr[j];
        }
        // copy temp to j+1 index
        arr[j+1] = temp;
    }
}

void display(int *arr)
{
    for(int i =0; i<size; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void insertion_sort_des(int arr[size]) // arr[size] = *arr
{
    int i, j, temp;
    for(i=1; i<size; i++)
    {
        temp = arr[i];
        for(j = i-1; j>=0 && temp > arr[j]; j--)
        {
            // shift arr[j] to j+1 index
            arr[j+1] = arr[j];
        }
        // copy temp to j+1 index
        arr[j+1] = temp;
    }
}