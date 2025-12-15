#include <stdio.h>
#include <stdlib.h>

// 3. Display Singly Linear Linked List in Reverse Order.

struct node {
    int data;
    struct node* next;
};

void printReverse(struct node* head);

int main() {
    struct node *head = NULL, *temp, *last;

    // Create list: 10 → 20 → 30
    temp = malloc(sizeof(struct node));
    temp->data = 10; 
    temp->next = NULL;
    head = temp;
    last = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 20; 
    temp->next = NULL;
    last->next = temp;
    last = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 30; 
    temp->next = NULL;
    last->next = temp;
    last = temp;

    printf("Reverse Print: ");
    printReverse(head);

    return 0;
}

void printReverse(struct node* head) 
{
    if (head == NULL)
        return;

    printReverse(head->next);
    printf("%d ", head->data);
}
