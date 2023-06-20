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
	L->tail = NULL;
	L->size = 0;
}

void insertLast(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;

	if (L->size == 0)
	{
		L->tail = node;
		node->next = L->tail;
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
	if (L->size == 0)
	{
		L->tail = node;
		node->next = L->tail;
	}
	else
	{

	}
}

void insert(ListType* L, int pos, element e)
{
	if (pos == 1)
		insertFirst(L, e);
	else if (pos == L->size + 1)
		insertLast(L, e);
	else
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		ListNode* p = L->tail;

		for (int i = 1; i < pos; i++)
			p = p->next;

		node->data = e;
		node->next = p->next;
		p->next = node;
	}
	L->size++;
}
void print(ListType* L)
{
	ListNode* p = L->tail;

	do 
	{
		printf("%c => ", p->next->data);
		p = p->next;
	} while (p != L->tail);
	printf("\b\b\b   \n");
}

element deleteFirst(ListType* L)
{
	ListNode* p = L->tail;
	ListNode* q = p->next;

	element e = q->data;
	p->next = q->next;

	if (p == q)
		L->tail = NULL;
	
	free(q);
	L->size--;
	
	return e;
}

element deleteLast(ListType* L)
{
	ListNode* p = L->tail;
	ListNode* q = p->next;

	element e = p->data;
	
	if (p->next == L->tail)
		L->tail = NULL;
	else
	{
		while (q->next != p)
		{
			q = q->next;
		}

		q->next = p->next;
		L->tail = q;
	}

	free(q);
	L->size--;

	return e;
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

	insert(&L, 1, 'F'); print(&L);
	insert(&L, 4, 'G'); print(&L);
	insert(&L, 7, 'H'); print(&L);

	deleteFirst(&L); print(&L);
	return 0;
}