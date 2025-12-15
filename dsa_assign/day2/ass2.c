#include <stdio.h>
#define size 5

// 2. Write program to implement linear queue in which front and rear starts at 0.

typedef struct queue
{
    int arr[size];
    int rear;
    int front;
}queue_t;

void queue_init(queue_t *pq);
void enqueue(int data, struct queue *pq);
void dequeue(queue_t *pq);
int peek(struct queue *pq);
int queue_full(struct queue *pq);
int queue_empty(struct queue *pq);

int main()
{
    queue_t Q;
    queue_init(&Q);
    int front;

    if(queue_full(&Q))
    {
        printf("queue is full\n");
    }
    else
    {
        enqueue(10, &Q);
        front = peek(&Q);
        printf("first element : %d\n", front);
    }
    
    if(queue_empty(&Q))
    {
        printf("queue is empty\n");
    }
    else
    {
        front = peek(&Q);
        dequeue(&Q);
        printf("removed elemet: %d\n", front);
    }

    if(queue_full(&Q))
    {
        printf("queue is full\n");
    }
    else
    {
        enqueue(20, &Q);
        front = peek(&Q);
        printf("first element : %d\n", front);
    }
    if(queue_empty(&Q))
    {
        printf("queue is empty\n");
    }
    else
    {
        front = peek(&Q);
        dequeue(&Q);
        printf("removed elemet: %d\n", front);
    }
    if(queue_empty(&Q))
    {
        printf("queue is empty\n");
    }
    else
    {
        front = peek(&Q);
        dequeue(&Q);
        printf("removed elemet: %d\n", front);
    }


    return 0;
}

void queue_init(queue_t *pq)
{
    pq->front = 0;
    pq->rear = 0;
}
void enqueue(int data, struct queue *pq)
{
    pq->arr[pq->rear] = data;
    pq->rear++;
}
void dequeue(queue_t *pq)
{
    pq->arr[pq->front] = 0;
    pq->front++;
}

int peek(struct queue *pq)
{
    return pq->arr[pq->front];
}
int queue_full(struct queue *pq)
{
    if(pq->rear == size)
        return 1;
    else
        return 0;
}
int queue_empty(struct queue *pq)
{
    // In a linear queue where front and rear both start at 0: queue is empty when front == rear
    if(pq->front == pq->rear)
        return 1;
    else
        return 0;
}

