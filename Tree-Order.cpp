#include <stdio.h>
#include <stdlib.h>

// 노드, 루트, 서브트리 개념 확실히

typedef int element;

typedef struct TreeNode
{
	element key;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;

TreeNode* makeNode(element key, TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = left;
	node->right = right;

	return node;
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
	TreeNode* N4 = makeNode(1,NULL, NULL);
	TreeNode* N6 = makeNode(16,NULL,NULL);
	TreeNode* N7 = makeNode(25,NULL,NULL);
	TreeNode* N2 = makeNode(4,N4,NULL);
	TreeNode* N3 = makeNode(20,N6,N7);
	TreeNode* N1 = makeNode(15,N2,N3);

	printf("pre : "); preOrder(N1); printf("\n");
	printf("in : "); inOrder(N1); printf("\n");
	printf("post : "); postOrder(N1); printf("\n");
	

	return 0;
}
