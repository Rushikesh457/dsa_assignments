#include <stdio.h>
#define size 5

// 3. Implement circular queue operations. To check empty and full use count of elements present in queue.

typedef struct c_queue{
    int arr[size];
    int front;
    int rear;
    int count;
}c_queue_t;

void queue_init(c_queue_t *pq);
void enqueue(int data,c_queue_t *pq);
void dequeue(c_queue_t *pq);
int queue_empty(c_queue_t *pq);
int queue_full(c_queue_t *pq);
int peek(c_queue_t *pq);

int main()
{
    c_queue_t Q;
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

void queue_init(c_queue_t *pq)
{
    pq->front = -1;
    pq->rear = -1;
    pq->count = 0;
}
void enqueue(int data,c_queue_t *pq)
{
    pq->rear = (pq->rear + 1) % size;   // pq->rear++;
    pq->arr[pq->rear] = data;
    pq->count++;
    if(pq->front == -1)
        pq->front = 0;
}
void dequeue(c_queue_t *pq)
{
    if(pq->front == pq->rear)   // deleteing last element
    {
        pq->arr[pq->front] = 0;
        pq->rear = -1;  // reset the front and rear to start the queue again
        pq->front = -1;
        pq->count = 0;
    }
    else
    {
        pq->arr[pq->front] = 0;
        pq->front = (pq->front + 1)%size;
        pq->count--;
    }
    
}
int peek(c_queue_t *pq)
{
    return pq->arr[pq->front];
}
int queue_empty(c_queue_t *pq)
{
    return (pq->count == 0);
    /*
    pq->count equals zero	    1
    pq->count not equal zero	0
    */

    if(pq->count == 0)
        return 1;
    else
        return 0;
}
int queue_full(c_queue_t *pq)
{
    return (pq->count == size);
    /*
    pq->count equals size	    1
    pq->count not equal size	0
    */
    if(pq->count == size)
        return 1;
    else
        return 0;

}
