#include <iostream>

#define FALSE 0
#define TRUE 1
#define INF 1000
#define N 7

int dist[N];
int visit[N];

void printStatus()
{
	static int step = 1;
	printf("STEP %d. ", step++);

	for (int i = 0; i < N; i++)
	{
		if (dist[i] == INF)
			printf(" * ");
		else
			printf("%2d ", dist[i]);
	}
	printf("\n");
	printf(" visit : ");
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == FALSE)
			printf("F  ");
		else
			printf("T  ");
	}
	printf("\n");
}

void print(int graph[N][N])
{
	printf("==================================\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (graph[i][j] == INF)
				printf("  * ");
			else
				printf("%3d ", graph[i][j]);
		printf("\n");
	}
	printf("==================================\n");

}

int findMin()
{
	int min = 2 * INF, minIdx;
	for (int i = 0; i < N; i++)
	{
		if (dist[i] < min && visit[i] == FALSE)
		{
			min = dist[i];
			minIdx = i;
		}
	}
	return minIdx;
}

void dijkstra(int graph[N][N], int start)
{
	int u, v;

	for (int i = 0; i < N; i++)
	{
		dist[i] = graph[start][i];
		visit[i] = FALSE;
	}
	visit[start] = TRUE;
	//printf("%d(%d) ", start, dist[start]);

	for (int i = 0; i < N - 1; i++)
	{
		printStatus();
		u = findMin();
		visit[u] = TRUE;
		//printf("%d(%d) ", u, dist[u]);
		
		for (v = 0; v < N; v++)
		{
			if (visit[v] == FALSE)
				if (dist[u] + graph[u][v] < dist[v])
					dist[v] = dist[u] + graph[u][v];
		}
	}
}

void floyd(int graph[N][N])
{
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (graph[i][k] + graph[k][j] < graph[i][j])
				graph[i][j] = graph[i][k] + graph[k][j];

		printf("k : %d\n", k);
		print(graph);
	}
}

int main()
{
	int graph[N][N] =
	{
		{0, 7, INF ,INF, 3, 10,  INF},
		{7, 0, 4, 10, 2 ,6 , INF},
		{INF, 4 , 0, 2, INF, INF, INF},
		{INF, 10, 2, 0, 11, 9, 4},
		{3, 2, INF, 11, 0, INF, 5},
		{10, 6, INF, 9, INF, 0, INF},
		{INF, INF, INF, 4, 5, INF, 0}
	};

	print(graph);
	//dijkstra(graph, 0);
	floyd(graph);
}

// 방향그래프 스킵