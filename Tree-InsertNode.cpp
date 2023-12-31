#include <stdio.h>
#include <stdlib.h>

#define N 10

// 노드, 루트, 서브트리 개념 확실히
// 한빛미디어 

typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct
{
	TreeNode* stack[N];
	int top;
}StackType;

typedef struct
{
	TreeNode* Queue[N];
	int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
	return Q->front == Q->rear;
}

void enqueue(QueueType* Q, TreeNode* e)
{
	Q->rear = (Q->rear + 1) % N;
	Q->Queue[Q->rear] = e;
}

TreeNode* dequeue(QueueType* Q)
{
	Q->front = (Q->front + 1) % N;
	return Q->Queue[Q->front];
}

void levelOrder(TreeNode* root)
{
	QueueType Q;
	initQueue(&Q);

	enqueue(&Q, root);
	while (!isEmpty(&Q))
	{
		root = dequeue(&Q);
		printf("[%d] ", root->key);

		if (root->left)
			enqueue(&Q, root->left);

		if (root->right)
			enqueue(&Q, root->right);

	}
}
void initStack(StackType* S)
{
	S->top = -1;
}

void push(StackType* S, TreeNode* e)
{
	if (S->top < N - 1)
		S->stack[++S->top] = e;
}

TreeNode* pop(StackType* S)
{
	TreeNode* e = NULL;

	if (S->top >= 0)
		e = S->stack[S->top--];
	return e;
}

void iterOrder(TreeNode* root)
{
	StackType S;
	initStack(&S);

	while (true)
	{
		for (; root != NULL; root = root->left)
			push(&S, root);

		root = pop(&S);

		if (root == NULL)
			break;

		printf("[%d] ", root->key);

		root = root->right;
	}
}

TreeNode* makeNode(element key)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;

	return node;
}

TreeNode* insertNode(TreeNode* root, element key)
{
	if (root == NULL)
		return makeNode(key);

	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if (key > root->key)
		root->right = insertNode(root->right, key);

	return root;
}

void preOrder(TreeNode* root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("[%d] ", root->key);
		inOrder(root->right);
	}
}

void postOrder(TreeNode* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("[%d] ", root->key);
	}
}


int main()
{
	TreeNode* root = NULL;

	root = insertNode(root, 35); root = insertNode(root, 68);
	root = insertNode(root, 99); root = insertNode(root, 18);
	root = insertNode(root, 7); root = insertNode(root, 3);
	root = insertNode(root, 12); root = insertNode(root, 26);
	root = insertNode(root, 22); root = insertNode(root, 68);

	preOrder(root); printf("\n");
	inOrder(root); printf("\n");
	postOrder(root); printf("\n");
	iterOrder(root); printf("\n");
	levelOrder(root); printf("\n");

	return 0;
}
