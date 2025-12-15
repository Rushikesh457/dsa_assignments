#include <stdio.h>
#include <stdlib.h>
#define size 5

// 1. Implement descending stack (Initialize top = SIZE)

typedef struct stack
{
    int arr[size];
    int top;

} stack_t;

void stack_init(stack_t *ps);
void push(int data, stack_t *ps);
void pop(stack_t *ps);
int peek(stack_t *ps);
int stack_full(stack_t *ps);
int stack_empty(stack_t *ps);

int main()
{
    stack_t S;
    stack_init(&S);
    int choice;
    do
    {
        printf("0.Exit\n1.Push\n2.Pop\n3.Peek :\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
        case 1: // push
            if (stack_full(&S))
            {
                printf("Stack is Full !\n");
            }
            else
            {
                int data;
                printf("enter the data to push :");
                scanf("%d", &data);
                push(data, &S);
                printf("Data pushed = %d\n", data);
            }
            break;
        case 2: // pop
            if (stack_empty(&S))
            {
                printf("Stack is empty !\n");
            }
            else
            {
                int val = peek(&S);
                pop(&S);
                printf("Value popped = %d\n", val);
            }
            break;
        case 3: // Peek
            if (stack_empty(&S))
            {
                printf("Stack empty ! peek not possible !\n");
            }
            else
            {
                int val = peek(&S);
                printf("Topmost value = %d\n", val);
            }
            break;
        default:
            printf("Invalid Choice !");
        }
    } while (choice != 0);

    return 0;
}

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