#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define FALSE 0
#define TRUE 1

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

void printPass(int A[], int i)
{
	printf(" %d Pass >> ", i);
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void insertionSort(int A[])
{
	printf("Before Sort : ");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<   Insertion Sort   >>>>>>>>>>>>>>>>>>>>\n");

	for (int i = 1; i <= N - 1; i++)
	{
		int key = A[i];

		int j = i - 1;
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;

		printPass(A, j);
	}
}

void bubbleSort(int A[])
{
	printf("Before Sort : ");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<   Bubble Sort   >>>>>>>>>>>>>>>>>>>>\n");

	for (int i = 1; i < N - 1; i++)
	{
		int temp, flag = FALSE;

		for (int j = 1; j <= N - i; j++)
		{
			if (A[j - 1] > A[j])
			{
				SWAP(A[j - 1], A[j], temp);
				flag = TRUE;
			}
		}

		if (flag == FALSE)
			break;

		printPass(A, i);
	}

}


int main()
{
	int A[N];
	srand(time(NULL));

	for (int i = 0; i < N; i++)
		A[i] = rand() % 100;

	//insertionSort(A);
	bubbleSort(A);
}