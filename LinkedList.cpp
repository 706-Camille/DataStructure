#include <stdlib.h>
#include <stdio.h>

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
	if (pos == 1)
	{
		insertFirst(L, e);
	}
	else if (pos < 1 || pos > L->size + 1)
	{
		printf("Invalid pos\n");
	}
	else
	{
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = e;
		
		ListNode* p = L->tail;

		for (int i = 1; i < L->size - 1; i++)
			p = p->next;
		
		node->next = p->next;
		p->next = node;
		L->size++;
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
		if (L->tail == L->tail->next)
		{
			element temp = L->tail->data;
			free(L->tail);
			L->tail = NULL;
			L->size--;
			return temp;
		}
		else
		{
			ListNode* p = L->tail;
		
			while (p->next != L->tail)       // tail 이전 노드로 이동
				p = p->next;
			
			element temp = L->tail->data;     // tail에 데이터를 임시변수에 담는다

			p->next = L->tail->next;         // tail 이전 노드 next 지정
			free(L->tail);
			L->tail = p;
			L->size--;
			return temp;
			
		}
	}
}

element deleteFirst(ListType* L)
{
	if (L->size == 0)
	{
		printf("empty\n");
		return -1;
	}
	else
	{
		if (L->tail == L->tail->next)
		{
			element temp = L->tail->data;
			free(L->tail);
			return temp;
		}

		ListNode* temp = L->tail->next;
		element e = temp->data;

		L->tail->next = temp->next;
		free(temp);
		L->size--;
		return e;
	}

}

element deletePosition(ListType* L, int pos)
{
	if (pos < 1 || pos > L->size)
	{
		printf("invalid pos\n");
		return -1;
	}
	else
	{
		if (pos == 1)
			deleteFirst(L);
		else
		{
			ListNode* p = L->tail;
			for (int i = 1; i < L->size - 1; i++)
			{
				p = p->next;
			}
			
			ListNode* temp = p->next;
			element e = temp->data;
			
			p->next = temp->next;
			free(temp);

			L->size--;
			return e;

		}
	}

}

void print(ListType* L)
{
	if (L->size == 0)
		printf("null\n");
	else
	{
		ListNode* p = L->tail;
		for (int i = 0; i < L->size; i++)
		{
			p = p->next;
			printf("%c => ", p->data);
		}
		printf("\b\b\b   \n");

	}
}

int main()
{
	ListType L;
	init(&L);
	
	insertFirst(&L,'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);
	insertFirst(&L, 'C'); print(&L);

	insertLast(&L, 'D'); print(&L);
	insertLast(&L, 'E'); print(&L);
	insertLast(&L, 'F'); print(&L);

	insertPosition(&L, 3,'K'); print(&L);
	insertPosition(&L, 3, 'K'); print(&L);
	insertPosition(&L, 3, 'K'); print(&L);

	printf("%c is deleted\n", deleteFirst(&L)); print(&L);
	printf("%c is deleted\n", deleteFirst(&L)); print(&L);

	printf("%c is deleted\n", deleteLast(&L)); print(&L);
	printf("%c is deleted\n", deleteLast(&L)); print(&L);

	printf("%c is deleted\n", deletePosition(&L, 2)); print(&L);
}