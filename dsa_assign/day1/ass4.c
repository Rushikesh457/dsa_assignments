#include <stdio.h>

#define size 7

// 4. Implement linear search algorithm to find the nth occurence of the given element. If nth occurrence is not found, return -1.

int linear_search(int key, int n, int arr[]);

int main()
{
    int arr[size] = {55, 70, 65, 70, 75, 75, 70};
    int key, n;
    printf("please enter the key and the occurance of the key want: ");
    scanf("%d %d", &key, &n);

    int index = linear_search(key, n, arr);
    if (index == -1)
    {
        printf("key %d not found\n", key);
    }
    else
    {
        printf("key %d found at index %d with it %d occurence\n", key, index, n);
    }

    return 0;
}

int linear_search(int key, int n, int arr[])
{
    int key_index = -1;
    int count = 0;
    // {55, 70 ,65, 70, 75, 75, 70};
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            key_index = i;
            count++;
        }
        if(count == n)
            return key_index;
    }

    return -1;
}
