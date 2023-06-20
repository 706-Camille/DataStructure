#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode
{
	element data;
	struct ListNode* next;
}ListNode;

typedef struct ListType
{
	ListNode* tail;
	int size;
}ListType;

void init(ListType* L)
{
	L->size = 0;
}

void print(ListType* L)
{
	ListNode* p = L->tail;

	for (int i = 0; i < L->size; ++i)
	{
		printf("[%c] ", p->next->data);
		p = p->next;
	}
	
	printf("\n");
}

void insertLast(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;

	if (L->size == 0)
	{
		L->tail = node;
		node->next = node;
	}
	else
	{
		node->next = L->tail->next;
		L->tail->next = node;
		L->tail = node;
	}
	
	L->size++;
}

void insertFirst(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;

	if (L->size == 0)
	{
		L->tail = node;
		node->next = node;
	}
	else
	{
		node->next = L->tail->next;
		L->tail->next = node;
	}
	L->size++;
}

void insertPosition(ListType* L, int pos, element e)
{
	if (pos < 1 || pos > L->size + 1)
		printf("Invalid pos.\n");
	else
	{
		if (pos == 1)
			insertFirst(L, e);
		else if (pos == L->size + 1)
			insertLast(L, e);
		else
		{
			ListNode* node = (ListNode*)malloc(sizeof(ListNode));
			node->data = e;

			ListNode* horse = L->tail;
			
			for (int i = 0; i < pos - 1; i++)
			{
				horse = horse->next;
			}

			node->next = horse->next;
			horse->next = node;
			L->size++;
		}
		
	}
}

element deleteLast(ListType* L)
{
	if (L->size == 0)
	{
		printf("NULL\n");
		return -1;
	}
	else
	{
		element e = L->tail->data;

		if (L->tail == L->tail->next)
		{
			free(L->tail);
			L->tail = NULL;
		}
		else
		{
			ListNode* horse = L->tail;

			for (int i = 0; i < L->size - 1; ++i)
			{
				horse = horse->next;
			}
			horse->next = L->tail->next;
			free(L->tail);
			L->tail = horse;
		}

		L->size--;
		return e;
	}
}

element deleteFirst(ListType* L)
{
	if (L->size == 0)
	{
		printf("EMPTY\n");
		return -1;
	}
	else
	{
		ListNode* removeNode = L->tail->next;
		element e = removeNode->data;

		L->tail->next = removeNode->next;
		free(removeNode);
		L->size--;
		
		return e;
	}
}

element deletePosition(ListType* L, int pos)
{
	if (pos < 1 || pos > L->size)
	{
		printf("Invalid pos.\n");
		return -1;
	}
	else
	{
		if (pos == L->size)
			deleteLast(L);
		else
		{
			ListNode* horse = L->tail;
			ListNode* removeNode;
			element e;

			for (int i = 0; i < pos - 1; ++i)
				horse = horse->next;

			removeNode = horse->next;
			e = removeNode->data;

			horse->next = removeNode->next;
			free(removeNode);

			L->size--;
			return e;
		}
		
	}
}

int main()
{
	ListType L;
	init(&L);

	insertLast(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertFirst(&L, 'C'); print(&L);
	insertFirst(&L, 'D'); print(&L);
	insertPosition(&L, 3, 'E'); print(&L);
	insertPosition(&L, 5, 'F'); print(&L);
	insertPosition(&L, 1, 'G'); print(&L);
	printf("%c is deleted.\n", deleteLast(&L)); print(&L);
	printf("%c is deleted.\n", deleteFirst(&L)); print(&L);

	printf("%c is deleted.\n", deletePosition(&L, 3)); print(&L);
	printf("%c is deleted.\n", deletePosition(&L, 1)); print(&L);


	
	
	
}