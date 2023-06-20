#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct
{
	int n;
	int adjMat[N][N];
}GraphType;

void init(GraphType* G)
{
	G->n = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			G->adjMat[i][j] = 0;
}

void makeVertex(GraphType* G)
{
	G->n++;
}

void insertEdge(GraphType* G, int u, int v)
{
	if (u >= G->n || v >= G->n)
		printf("Error.\n");
	else
		G->adjMat[u][v] = G->adjMat[v][u] = 1;
}

void print(GraphType* G)
{
	for (int i = 0; i < G->n; i++)
	{
		for (int j = 0; j < G->n; j++)
			printf(" %d", G->adjMat[i][j]);
		printf("\n");
	}
}

int visited[N];

void dfsMat(GraphType* G, int u)
{
	printf("[%d] ", u);
	visited[u] = 1;

	for (int v = 0; v < G->n; v++)
		if (G->adjMat[u][v] && !visited[v])
			dfsMat(G, v);
}

int main()
{
	GraphType G;
	init(&G);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		makeVertex(&G);
	}

	insertEdge(&G, 0, 1); insertEdge(&G, 0, 2); insertEdge(&G, 0, 4);
	insertEdge(&G, 1, 2); insertEdge(&G, 2, 3); insertEdge(&G, 2, 4);
	insertEdge(&G, 3, 4); print(&G);

	dfsMat(&G, 1);


	return 0;
}