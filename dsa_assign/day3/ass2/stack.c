#include "stack.h"

void stack_init(stack_t *ps)
{
    ps->top = size;
}
void push(int data, stack_t *ps)
{
    ps->top--;
    ps->arr[ps->top] = data;
}
void pop(stack_t *ps)
{
    ps->arr[ps->top] = 0;
    ps->top++;
}
int peek(stack_t *ps)
{
    return ps->arr[ps->top];
}
int stack_full(stack_t *ps)
{
    if (ps->top == 0)
        return 1;
    else
        return 0;
}
int stack_empty(stack_t *ps)
{
    if (ps->top == size)
        return 1;
    else
        return 0;
}