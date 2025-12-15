#include <stdio.h>
#include <stdlib.h>
#define size 11

// 5. find the first non-repeating element: Input: { 1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8 } Output: 3

int linear_search(int *arr);

int main()
{
    int arr[] = {1, 2, 8, -1, 2, 1, 3, 4, -1, 4, 8};
    int first_non_repeat_element = linear_search(arr);
    if(first_non_repeat_element == -1)
        printf("no non repeating element found\n");
    else
        printf("first non repeating element is: %d\n", first_non_repeat_element);

    return 0;
}

int linear_search(int *arr)
{
    /*
    For each element, you want to know: “Does this element appear anywhere else in the array?”
    Use linear search to scan the rest of the array and index occurrences of the current element.
    The first element whose index stays 1 is your answer → stop immediately.
    */

    // 1, 2, 3, -1, 2, 1, 0, 4, -1, 7, 8
    int index = 0;
    while (index < size)
    {
        int occurance = 0;
        int check_element = arr[index];

        for (int i = 0; i < size; i++)
        {
            if (check_element == arr[i])
            {
                occurance++;
                //printf("%d: %d\n", check_element, occurance );
            }
            if(occurance > 1)
                break;
        }
        if(occurance == 1)
            return check_element;
        index++;
    }
    return -1;
}
