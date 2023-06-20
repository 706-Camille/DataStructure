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
	ListNode* head;
	int size;
}ListType;

void init(ListType* L)
{
	L->head = NULL;
	L->size = 0;
}

void insertFirst(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = L->head;
	L->head = node;
	L->size++;

}

void insertLast(ListType* L, element e)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = e;
	node->next = NULL;

	if (L->size == 0)
		L->head = node;
	else
	{
		ListNode* p;
		for (p = L->head; p->next != NULL; p = p->next);

		p->next = node;
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
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		ListNode* p = L->head;

		for (int i = 1; i < pos - 1 ; i++)
			p = p->next;

		node->data = e;
		node->next = p->next;
		p->next = node;
	}
	L->size++;
}

void print(ListType* L)
{
	ListNode* p;
	for (p = L->head; p != NULL; p = p->next)
		printf("%c => ", p->data);
	printf("\n");
}

element deleteFirst(ListType* L)
{
	if (L->size == 0)
	{
		printf("No element.\n");
		return -1;
	}

	ListNode* temp = L->head;
	element e = temp->data;
	L->head = temp->next;
	free(temp);
	L->size--;
	return e;
}

element delete2(ListType* L, int pos)
{
	if (L->size == 0)
	{
		printf("no element\n");
		return -1;
	}

	if (pos < 1 || pos > L->size)
	{
		printf("invalid pos.\n");
		return -1;
	}
	else
	{
		ListNode* p = L->head;
		ListNode* q;
		element e;
		
		if (pos == 1)
			e = deleteFirst(L);
		else
		{
			for (int i = 1; i < pos; ++i)
			{
				p = p->next;
			}
			q = p;
			e = p->data;
			q->next = p->next;
			free(p);
			L->size--;
		}
		return e;
	}
}

void deleteLast(ListType* L)
{
	if (L->size == 1)
	{
		free(L->head);
		L->head = NULL;
	}
	else
	{

	}
	{
		ListNode* p = L->head;

		for (int i = 1; i < L->size - 1; ++i)
		{
			p = p->next;
		}

		ListNode* temp = p->next;
		p->next = NULL;
		free(temp);
	}
	L->size--;
}

void deleteList(ListType* L)
{
	ListNode* removeNode = L->head;
	ListNode* temp;

	while (removeNode != NULL)
	{
		temp = removeNode;
		removeNode = removeNode->next;
		free(temp);
	}
	L->head = NULL;
	L->size = 0;
}


int main()
{
	ListType L;	

	init(&L);

	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertLast(&L, 'C'); print(&L);
	insertLast(&L, 'D'); print(&L);

	insert(&L, 3, 'A');
	insert(&L, 3, 'A');
	insert(&L, 3, 'A');
	print(&L);

	printf("%c is deleted\n", deleteFirst(&L)); print(&L);
	printf("%c is deleted\n", delete2(&L,3)); print(&L);
	

	deleteList(&L);

	print(&L);

	return 0;
}