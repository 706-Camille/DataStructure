#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;

typedef struct
{
	element data[N];
	int front;
	int rear;
}QueueType;

void init(QueueType* Q)
{
	Q->front = -1;
	Q->rear = -1;
}

int isFull(QueueType* Q)
{
	return Q->rear == N - 1;
}

int isEmpty(QueueType* Q)
{
	return Q->front == Q->rear;
}

void enqueue(QueueType* Q, element e)
{
	if (isFull(Q))
		printf("Full\n");
	else
	{
		Q->rear++;
		Q->data[Q->rear] = e;
	}
}

element dequeue(QueueType* Q)
{
	if (isEmpty(Q))
	{
		printf("Empty\n");
		return 0;
	}
	Q->front++;
	return Q->data[Q->front];
}

void print(QueueType* Q)
{
	printf("Front : %d - rear : %d\n", Q->front, Q->rear);

	for (int i = Q->front + 1; i <= Q->rear; i++)
	{
		printf("%c ", Q->data[i]);
	}
	printf("\n");
}

int main()
{
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
	{
		enqueue(&Q, rand() % 26 + 65);
	}

	print(&Q);

	for (int i = 0; i < 4; i++)
	{
		printf("%c ", dequeue(&Q));
	}

	print(&Q);

	for (int i = 0; i < 7; i++)
	{
		enqueue(&Q, rand() % 26 + 65);
	}

	print(&Q);


	return 0;
}