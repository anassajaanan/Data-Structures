#include <stdio.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ShellSort(int A[], int n)
{
	int i;
	int j;
	int gap;

	gap = n / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < n)
		{
			j = i;
			while (j >= gap && A[j] < A[j - gap])
			{
				swap(&A[j], &A[j - gap]);
				j -= gap;
			}
			i += gap;
		}
		gap = gap / 2;
	}
}
