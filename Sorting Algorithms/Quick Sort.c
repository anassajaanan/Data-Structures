#include <stdio.h>


int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int A[], int low, int high)
{
	int i;
	int j;
	int pivot;

	i = low - 1;
	j = low;
	pivot = A[high];
	while (j < high)
	{
		if (A[j] <= pivot)
			swap(&A[++i], &A[j]);
		j++;
	}
	swap(&A[++i], &A[high]);
	return (i);
}

void	QuickSort(int A[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(A, low, high);
		QuickSort(A, low, pi - 1);
		QuickSort(A, pi + 1, high);
	}
}
