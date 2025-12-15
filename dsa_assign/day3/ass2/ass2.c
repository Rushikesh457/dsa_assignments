#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define size 5

// 2. Create an array of integers. Reverse the array using stack

void add_to_stack(int arr[], stack_t *ps);
void get_from_stack(int rev_arr[], stack_t *ps);
void display(int *arr);

int main()
{
    stack_t S;
    stack_init(&S);
    
    int arr[size] = {11, 20, 10, 5, 30};
    display(arr);
    int rev_arr[size];
    add_to_stack(arr, &S);

    get_from_stack(rev_arr, &S);
    

    return 0;
}

void add_to_stack(int arr[], stack_t *ps)
{
    for(int i=0; i<size; i++)
    {
        push(arr[i], ps);
    }
}

void get_from_stack(int rev_arr[], stack_t *ps)
{
    for(int i=0; i<size; i++)
    {
        rev_arr[i] = peek(ps);
        pop(ps);
    }
}


