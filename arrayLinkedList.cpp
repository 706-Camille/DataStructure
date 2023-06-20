#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef char element;

typedef struct ListType
{
	element data[N];
	int size;
}ListType;

void init(ListType* L)
{
	L->size = 0;
}

int isEmpty(ListType* L)
{
	return L->size == 0;
}

int isFull(ListType* L)
{
	return L->size == 10;
}

void insertLast(ListType* L,element e)
{
	if (isFull(L))
		printf("FULL\n");
	else
	{
		L->data[L->size] = e;
		L->size++;
	}
}

void insertFirst(ListType* L, element e)
{
	if (isFull(L))
		printf("FULL\n");
	else
	{
		for (int i = L->size - 1; i >= 0; --i)
		{
			L->data[i + 1] = L->data[i];
		}
		
		L->data[0] = e;
		
		L->size++;
	}
}

void insertPosition(ListType* L, int pos, element e)
{
	if (isFull(L) || pos < 0 || pos > L->size)
		printf("Invalid.\n");
	else
	{
		for (int i = L->size - 1; i >= pos; --i)
		{
			L->data[i + 1] = L->data[i];
		}

		L->data[pos] = e;

		L->size++;
	}
}

element deletePosition(ListType* L, int pos)
{
	if (isEmpty(L) || pos < 0 || pos > L->size - 1)
		printf("Invalid.\n");
	else
	{
		element e = L->data[pos];

		for (int i = pos + 1; i < L->size; ++i)
		{
			L->data[i - 1] = L->data[i];
		}

		L->size--;
		return e;
	}
}

element deleteLast(ListType* L)
{
	if (isEmpty(L))
	{
		printf("EMPTY.\n");
		return -1;
	}
	else
	{
		L->size--;
		element e = L->data[L->size];
		
		return e;
	}
}

void print(ListType* L)
{
	for (int i = 0; i < L->size; ++i)
	{
		printf("[%c] ", L->data[i]);
	}

	printf("\n");
}

int main()
{
	ListType L;
	init(&L);

	insertLast(&L, 'A'); print(&L);
	insertLast(&L, 'B'); print(&L);
	insertLast(&L, 'C'); print(&L);

	insertFirst(&L, 'D'); print(&L);
	insertFirst(&L, 'E'); print(&L);
	insertFirst(&L, 'F'); print(&L);

	insertPosition(&L, 1,'G'); print(&L);
	insertPosition(&L, 5,'H'); print(&L);
	insertPosition(&L, 8,'I'); print(&L);

	printf("%c is deleted.\n", deleteLast(&L)); print(&L);
	printf("%c is deleted.\n", deleteLast(&L)); print(&L);

	printf("%c is deleted.\n", deletePosition(&L, 2)); print(&L);
	printf("%c is deleted.\n", deletePosition(&L, 5)); print(&L);





	return 0;
}

