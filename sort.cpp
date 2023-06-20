#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void makeList(int list[], int N)
{
	for (int i = 0; i < N; i++)
		list[i] = rand() % 100 + 1;
}

void printList(int list[], int N)
{
	for (int i = 0; i < N; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}

void merge(int list[], int sorted[], int left, int right)
{
	int i, j, k;
	int mid = (left + right) / 2;
	i = left; j = mid + 1; k = left;
	
	while (i <= mid && j <= right)
	{
		if (list[i] < list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid)
		for (int l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (int l = i; i <= mid; i++)
			sorted[k++] = list[l];

	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}

void mergeSort(int list[],int sorted[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(list, sorted, left, mid);
		mergeSort(list, sorted, mid + 1, right);
		merge(list, sorted, left, right);
	}
}

int partition(int list[], int left, int right)
{
	int low = left; int high = right + 1; int pivot = list[left];
	
	do
	{
		do
			low++;
		while (list[low] < pivot && low < right);
		
		do
			high--;
		while (list[high] > pivot);

		// swap
		if (low < high)
		{
			int temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}

	} while (low < high);

	int temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	return high;
}

void quickSort(int list[], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quickSort(list, left, q - 1);
		quickSort(list, q+1, right);
	}
}

void selectSort(int list[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int minidx = i;
		for (int j = i + 1; j < N; j++)
		{
			if (list[minidx] > list[j])
				minidx = j;
		}
		
		int temp = list[i];
		list[i] = list[minidx];
		list[minidx] = temp;
	}
}

void insertionSort(int list[], int N)
{
	for (int i = 1; i < N; i++)
	{
		int key = list[i];
		int j = i - 1;


		while (key < list[j] && j >= 0)
		{
			list[j + 1] = list[j];
			j--;
		}
		
		list[j + 1] = key;
	}
}

int main()
{
	int list[SIZE];
	int sorted[SIZE];

	srand(time(NULL));
	printf("\n mergeSort----------------------------------------\n");
	makeList(list, SIZE);
	printList(list, SIZE);
	mergeSort(list, sorted, 0, SIZE - 1);
	printList(sorted, SIZE);
	
	printf("\n quickSort----------------------------------------\n");
	makeList(list, SIZE);
	printList(list, SIZE);
	quickSort(list, 0, SIZE - 1);
	printList(list, SIZE);
	printf("\n selectSort----------------------------------------\n");
	makeList(list, SIZE);
	printList(list, SIZE);
	selectSort(list, SIZE);
	printList(list, SIZE);
	printf("\n insertionSort----------------------------------------\n");
	makeList(list, SIZE);
	printList(list, SIZE);
	insertionSort(list, SIZE);
	printList(list, SIZE);


	return 0;
}