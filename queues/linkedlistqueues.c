#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{

    int front;
    int rear;
    int content[SIZE];

} Queue;

int enqueue(Queue *ptr, int value)
{

    if (ptr->rear >= SIZE - 1)
    {
        printf("Queue is full!\n");
        return 1;
    }

    ptr->rear++;
    ptr->content[ptr->rear] = value;
    return 0;
}

int dequeue(Queue *ptr, int *value)
{

    if (ptr->front == -1)
    {
        printf("Queue is empty!\n");
        return 1;
    }

    *value = ptr->content[0];

    for (int i = 0; i < ptr->rear; i++)
    {

        ptr->content[ptr->rear] = ptr->content[ptr->rear + 1];
    };

    ptr->rear--;
    return 0;
}

void print(Queue *q){

    for(int i=0;i<=q->rear;i++){
        printf("%d. number:%d\n",i+1,q->content[i]);
    }


}

int main()
{

    Queue q;
    int removedValue;

    q.front = -1;
    q.rear=-1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    dequeue(&q, &removedValue);

    printf("Front: %d\n", q.front);
    printf("Rear: %d\n", q.rear);
    printf("Last Item: %d\n",q.content[q.rear]);

}
