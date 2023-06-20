#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key, TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = left;
	node->right = right;
	return node;
}

void preOrder(TreeNode* node)
{
	if (node != NULL)
	{
		printf("[%d] ", node->key);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(TreeNode* node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		printf("[%d] ", node->key);
		inOrder(node->right);
	}
}

void postOrder(TreeNode* node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		inOrder(node->right);
		printf("[%d] ", node->key);
	}
}

typedef struct QueueType
{
	TreeNode* data[100];
	int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
	Q->front = -1;
	Q->rear = -1;
}

int is_Empty(QueueType* Q)
{
	return Q->front == Q->rear;
}

void enqueue(QueueType* Q, TreeNode* e)
{
	Q->rear++;
	Q->data[Q->rear] = e;
}

TreeNode* dequeue(QueueType* Q)
{
	Q->front++;
	return Q->data[Q->front];
}

typedef struct StackType
{
	TreeNode* data[100];
	int top = -1;
}StackType;

void push(StackType* S, TreeNode* p)
{
	S->data[++S->top] = p;
}

TreeNode* pop(StackType* S)
{
	TreeNode* e = NULL;

	if(S->top >= 0)
		e = S->data[S->top--];

	return e;
}


void iterOrder(TreeNode* node)
{
	StackType S;

	while (true)
	{
		while (node != NULL)
		{
			push(&S, node);
			node = node->left;
		}

		node = pop(&S);

		if (node == NULL)
			break;
		printf("[%d] ", node->key);

		node = node->right;
	}
}

void levelOrder(TreeNode* node)
{
	QueueType Q;
	initQueue(&Q);
	
	enqueue(&Q, node);
	while (!is_Empty(&Q))
	{
		node = dequeue(&Q);
		printf("[%d] ", node->key);

		if (node->left != NULL)
			enqueue(&Q, node->left);
		if (node->right != NULL)
			enqueue(&Q, node->right);	
	}
}

int main()
{
	TreeNode* N4 = makeNode(1, NULL, NULL);
	TreeNode* N6 = makeNode(16,NULL,NULL);
	TreeNode* N7 = makeNode(25,NULL,NULL);
	TreeNode* N2 = makeNode(4,N4,NULL);
	TreeNode* N3 = makeNode(20,N6,N7);
	TreeNode* N1 = makeNode(15, N2, N3);

	preOrder(N1); printf("\n");

	inOrder(N1); printf("\n");
	postOrder(N1); printf("\n");
	
	levelOrder(N1); printf("\n");
	iterOrder(N1); printf("\n");
	return 0;
}