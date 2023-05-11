#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	InsertionSort(int A[], int n)
{
	int i;
	int j;

	i = 1;
	while (i < n)
	{
		j = i;
		while (j > 0 && A[j] < A[j - 1])
		{
			swap(&A[j], &A[j - 1]);
			j--;
		}
		i++;
	}
}
