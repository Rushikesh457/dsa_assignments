#include <stdio.h>

#define size 10

// 3. Implement binary search algorithm if array is sorted in descending order.
int binary_search_des(int *arr, int key);

int main()
{
    int arr[size] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int left = 0, right = size - 1, mid;
    mid = (left + right) / 2;

    int key = 70;

    int result = binary_search_des(arr, key);
    if(result == -1)
    {
        printf("key %d not found\n", key);
    }
    else
        printf("key %d found\n", key);

    return 0;
}

int binary_search_des(int *arr, int key)
{
    // 100, 90, 80, 70, 60, 50, 40, 30, 20, 10
    int left = 0, right = size - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        printf("mid element : %d\n", arr[mid]);
        if (key == arr[mid])
            return mid;
        else if (key < arr[mid])
        {
            left=mid+1;
        }
        else    // key > arr[mid]
        {
            right = mid-1;
        }
    }
    return -1;
}
