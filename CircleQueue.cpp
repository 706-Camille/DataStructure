#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef char element;

typedef struct QueueType 
{
	element data[N];
	int front;
	int rear;

}QueueType;

void init(QueueType* Q)
{
	Q->front = 0;
	Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
	return Q->front == Q->rear;
}

int isFull(QueueType* Q)
{
	return (Q->rear + 1) % N == Q->front;
}

void enqueue(QueueType* Q, element e)
{
	if (isFull(Q))
		printf("FULL\n");
	else
	{
		Q->rear = (Q->rear + 1) % N;
		Q->data[Q->rear] = e;
	}
}

element dequeue(QueueType* Q)
{
	if (isEmpty(Q))
	{
		printf("EMPTY\n");
		return -1;
	}
	
	Q->front = (Q->front + 1) % N;

	return Q->data[Q->front];
}

void print(QueueType* Q)
{
	for (int i = Q->front; i != Q->rear;)
	{
		i = (i + 1) % N;
		printf("[%c] ", Q->data[i]);
	}

	printf("\n");
}

int get_count(QueueType* Q)
{
	if (Q->rear - Q->front > 0)
		return Q->rear - Q->front;
	else if (Q->rear == Q->front)
		return 0;
	else
		return Q->rear - Q->front + 5;
}

int main()
{
	QueueType Q;
	init(&Q);

	enqueue(&Q, 'A'); print(&Q); printf("%d\n", get_count(&Q));
	enqueue(&Q, 'B'); print(&Q); printf("%d\n", get_count(&Q));
	enqueue(&Q, 'C'); print(&Q); printf("%d\n", get_count(&Q));
	enqueue(&Q, 'D'); print(&Q); printf("%d\n", get_count(&Q));
	
	dequeue(&Q); print(&Q); printf("%d\n", get_count(&Q));
	dequeue(&Q); print(&Q); printf("%d\n", get_count(&Q));
	dequeue(&Q); print(&Q); printf("%d\n", get_count(&Q));

	enqueue(&Q, 'C'); print(&Q); printf("%d\n", get_count(&Q));
	enqueue(&Q, 'D'); print(&Q); printf("%d\n", get_count(&Q));

	printf("%d", get_count(&Q));

	return 0;
}