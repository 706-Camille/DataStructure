#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNord
{
	element data;
	struct ListNord* next;

}ListNord;

typedef struct ListType
{
	ListNord* head;
	int size;
}ListType;

void init(ListType* L)
{
	L->head = nullptr;
	L->size = 0;
}

void insertFirst(ListType* L, element e)
{
	ListNord* nord = (ListNord*)malloc(sizeof(ListNord));
	nord->data = e;
	nord->next = L->head;
	L->head = nord;
	
	L->size++;
}

void insertLast(ListType* L, element e)
{
	ListNord* nord = (ListNord*)malloc(sizeof(ListNord));
	nord->data = e;
	nord->next = nullptr;

	if (L->size == 0)
		L->head = nord;
	else
	{
		ListNord* ptr = L->head;
		for (ptr; ptr->next != nullptr; ptr = ptr->next);
		ptr->next = nord;
	}

	L->size++;
}

void insert(ListType* L, int pos, element e)
{
	if (pos == 1)
		insertFirst(L, e);
	else if (pos == L->size + 1)
		insertLast(L, e);
	else
	{
		ListNord* nord = (ListNord*)malloc(sizeof(ListNord));
		nord->data = e;

		ListNord* ptr = L->head;
		for (int i = 1; i < pos - 1; i++)
		{
			ptr = ptr->next;
		}
		nord->next = ptr->next;
		ptr->next = nord;
	}
	L->size++;

}

void print(ListType* L)
{
	ListNord* ptr = L->head;

	for (ptr; ptr != nullptr; ptr = ptr->next)
	{
		printf("%c ", ptr->data);
	}
	printf("\n");
}

int main()
{
	ListType L;
	init(&L);
	
	insertFirst(&L, 'A');
	insertFirst(&L, 'B');
	insertFirst(&L, 'C');
	insertLast(&L, 'D');
	insertLast(&L, 'F');
	print(&L);

	insert(&L, 3, 'I');
	print(&L);
	return 0;
}