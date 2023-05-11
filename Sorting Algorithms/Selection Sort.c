#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	SelectionSort(int A[], int n)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < n - 1)
	{
		k = i;
		j = k + 1;
		while (j < n)
		{
			if (A[j] < A[k])
				k = j;
			j = j + 1;
		}
		swap(&A[i], &A[k]);
		i++;
	}
}