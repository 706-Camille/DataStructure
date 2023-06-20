#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef char element;

typedef struct DequeType
{
	element data[N];
	int front;
	int rear;

}DequeType;

void init(DequeType* D)
{
	D->front = 0;
	D->rear = 0;
}

int isEmpty(DequeType* D)
{
	return D->front == D->rear;
}

void print(DequeType* D)
{
	for (int i = D->front; i != D->rear;)
	{
		i = (i + 1) % N;
		printf("[%c] ", D->data[i]);
	}

	printf("\n");
}

int isFull(DequeType* D)
{
	return (D->rear + 1) % N == D->front;
}

void add_front(DequeType* D, element e)
{
	if (isFull(D))
		printf("FULL\n");
	else
	{
		D->data[D->front] = e;
		D->front = (D->front - 1 + N) % N;
	}
}

void add_rear(DequeType* D, element e)
{
	if (isFull(D))
		printf("FULL\n");
	else
	{
		D->rear = (D->rear + 1) % N;
		D->data[D->rear] = e;
	}
}

element delete_front(DequeType* D)
{
	if (isEmpty(D))
	{
		printf("EMPTY\n");
		return -1;
	}
	else
	{
		D->front = (D->front + 1) % N;
		element e = D->data[D->front];

		return e;
	}
}

element delete_rear(DequeType* D)
{
	if (isEmpty(D))
	{
		printf("EMPTY\n");
		return -1;
	}
	else
	{
		element e = D->data[D->rear];
		
		D->rear = (D->rear - 1 + N) % N;

		return e;
	}
}

int main()
{
	DequeType D;
	init(&D);
	
	add_front(&D, 'A'); print(&D);
	add_front(&D, 'A'); print(&D);
	add_front(&D, 'A'); print(&D);

	add_rear(&D, 'B'); print(&D);
	add_rear(&D, 'B'); print(&D);
	add_rear(&D, 'B'); print(&D);

	add_front(&D, 'C'); print(&D);
	add_front(&D, 'C'); print(&D);
	add_front(&D, 'C'); print(&D);

	printf("%c is deleted.\n", delete_front(&D)); print(&D);
	printf("%c is deleted.\n", delete_front(&D)); print(&D);

	printf("%c is deleted.\n", delete_rear(&D)); print(&D);
	printf("%c is deleted.\n", delete_rear(&D)); print(&D);


	printf("%c is deleted.\n", delete_front(&D)); print(&D);
	printf("%c is deleted.\n", delete_front(&D)); print(&D);

	printf("%c is deleted.\n", delete_rear(&D)); print(&D);
	printf("%c is deleted.\n", delete_rear(&D)); print(&D);

	add_front(&D, 'D'); print(&D);
	add_front(&D, 'D'); print(&D);
	add_front(&D, 'D'); print(&D);

	add_rear(&D, 'E'); print(&D);
	add_rear(&D, 'E'); print(&D);
	add_rear(&D, 'E'); print(&D);

	add_front(&D, 'F'); print(&D);
	add_front(&D, 'F'); print(&D);
	add_front(&D, 'F'); print(&D);

	return 0;
}