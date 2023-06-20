#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void makeList(int list[])
{
	for (int i = 0; i < SIZE; i++)
		list[i] = rand() % 100 + 1;
}

void printList(int list[])
{
	for (int i = 0; i < SIZE; i++)
		printf("[%d] ", list[i]);
	printf("\n");
}

void merge(int list[], int sorted[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1; k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	printList(list);
}

void mergeSort(int list[], int sorted[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		mergeSort(list, sorted, left, mid);
		mergeSort(list, sorted, mid + 1, right);
		merge(list, sorted, left, mid, right);
	}
}

int partition(int list[], int left, int right)
{
	
	int pivot, temp, low, high;

	pivot = list[left];
	low = left; high = right + 1;

	do
	{
		do
			low++;
		while (list[low] < pivot);
		
		do
			high--;
		while (list[high] > pivot);

		if (low < high)
		{
			//swap
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
		printList(list);

	} while (low < high);

	temp = list[left];
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
		quickSort(list, q + 1, right);
	}
}




int main()
{
	int list[SIZE], sorted[SIZE];
	srand(time(NULL));

	
	makeList(list);
	list[0] = 0;
	printList(list);

	
	mergeSort(list, sorted, 0, SIZE - 1);
	
	return 0;
}