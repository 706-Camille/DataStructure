#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct
{
	element* data;
	int size;
}DataTable;

void init(DataTable* DT)
{
	DT->size = 0;
}

void makeDataTable(DataTable* DT, int n)
{
	srand(time(NULL));
	DT->data = (element*)malloc(sizeof(element) * n );
	for (int i = 0; i < n; i++)
	{
		DT->data[i] = rand() % 100;
		DT->size++;
	}
}

void printDataTable(DataTable* DT)
{
	for (int i = 0; i < DT->size; i++)
		printf("[%d] ", DT->data[i]);
	printf("\n");
}

void swap(DataTable* DT, int a, int b)
{
	int temp = DT->data[a];
	DT->data[a] = DT->data[b];
	DT->data[b] = temp;
}

void insertionSort(DataTable* DT)
{
	int i, j;
	element item;

	for (i = 1; i < DT->size; i++)
	{
		item = DT->data[i];
		for (j = i - 1; j >= 0 && DT->data[j] > item; j--)
			DT->data[j + 1] = DT->data[j];
		DT->data[j + 1] = item;
	}
}

int findElement(DataTable* DT, int key)
{
	int low = 0;
	int middle;
	int high = DT->size - 1;

	while (low <= high)
	{
		middle = (low + high) / 2;
		if (key == DT->data[middle])
			return middle;
		else if (key < DT->data[middle])
			high = middle - 1;
		else
			low = middle + 1;
	}

	return -1;
}

int rFindElement(DataTable* DT, int key, int low, int high)
{
	int middle;
	if (low <= high)
	{
		middle = (low + high) / 2;
		if (key == DT->data[middle])
			return middle;
		else if (key < DT->data[middle])
			return rFindElement(DT, key, low, middle - 1);
		else
			return rFindElement(DT, key, middle + 1, high);
	}
	return -1;
}

int main()
{
	DataTable DT;
	init(&DT);

	int n;
	scanf("%d", &n);

	makeDataTable(&DT, n); printDataTable(&DT);
	insertionSort(&DT); printDataTable(&DT);

	scanf("%d", &n);
	n = findElement(&DT, n);
	(n == -1) ? printf("No Such Key\n") : printf("key Index : %d", n);

	printf("\n");
	scanf("%d", &n);
	n = rFindElement(&DT, n, 0, DT.size - 1);
	(n == -1) ? printf("No Such Key\n") : printf("key Index : %d", n);
}