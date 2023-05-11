#include <stdio.h>
#include <stdlib.h>

void	swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	BubbleSort(int A[], int n)
{
	int i;
	int j;
	int flag;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		flag = 0;
		while (j < n - 1 - i)
		{
			if (A[j] > A[j + 1])
			{
				swap(&A[j], &A[j + 1]);
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return;
		i++;
	}
}
