#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode
{
	element data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

typedef struct
{
	DListNode* H;
	DListNode* T;
	int N;

}DListType;

DListNode* getNode()
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void init(DListType* DL)
{
	DL->H = getNode();
	DL->T = getNode();
	DL->H->next = DL->T;
	DL->T->prev = DL->H;
	DL->N = 0;
}

void insertFirst(DListType* DL, element e)
{
	DListNode* node = getNode();
	DListNode* p = DL->H;

	node->data = e;

	node->prev = p;
	node->next = p->next;

	p->next->prev = node;
	p->next = node;

	DL->N++;
}

void insertLast(DListType* DL, element e)
{
	DListNode* node = getNode();
	DListNode* p = DL->T;

	node->data = e;

	node->next = p;
	node->prev = p->prev;

	p->prev->next = node;
	p->prev = node;

	DL->N++;
}

void print(DListType* DL)
{
	DListNode* p = DL->H->next;
	for (p; p != DL->T; p = p->next)
	{
		printf("[%c] <=> ", p->data);
	}

	printf("\b\b\b\b    \n");
}

void insertPosition(DListType* DL, int pos, element e)
{
	if (pos < 1 || pos > DL->N + 1)
		printf("Invalid Position.\n");
	else
	{
		DListNode* node = getNode();
		DListNode* p = DL->H;

		node->data = e;

		for (int i = 0; i < pos-1; ++i)
		{
			p = p->next;
		}

		node->prev = p;
		node->next = p->next;

		p->next->prev = node;
		p->next = node;

		DL->N++;
	}
}

element deletePosition(DListType* DL, int pos)
{
	element e = -1;

	if (pos < 1 || pos > DL->N)
		printf("Invalid Position.\n");
	else
	{
		DListNode* p = DL->H;

		for (int i = 0; i < pos; i++)
		{
			p = p->next;
		}

		e = p->data;

		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		DL->N--;
	}

	return e;
}




int main()
{
	DListType DL;
	init(&DL);

	insertFirst(&DL, 'A'); print(&DL);
	insertFirst(&DL, 'B'); print(&DL);

	insertLast(&DL, 'C'); print(&DL);
	insertPosition(&DL, 2, 'D'); print(&DL);
	insertPosition(&DL, 3, 'E'); print(&DL);
	insertPosition(&DL, 1, 'F'); print(&DL);

	insertPosition(&DL, 1, 'G'); print(&DL);
	insertPosition(&DL, 4, 'H'); print(&DL);
	insertPosition(&DL, 1, 'I'); print(&DL);

	printf("[%c] is deleted.\n", deletePosition(&DL, 1));
	print(&DL);
	printf("[%c] is deleted.\n", deletePosition(&DL, 3));
	print(&DL);
	printf("[%c] is deleted.\n", deletePosition(&DL, 5));
	print(&DL);



	return 0;
}

//소스코드는 복붙하면 되고, 필기시험, 프로그래밍 시험 두개 봄