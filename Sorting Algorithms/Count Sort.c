#include <stdio.h>
#include <stdlib.h>

int getMax(int A[], int n)
{
	int max;

	for (int i = 0; i < n; i++)
	{
		if (A[i] > max)
			max = A[i];
	}
	return (max);
}

void	CountSort(int A[], int n)
{
	int *H;
	int i;
	int j;
	int max;

	max = getMax(A, n);
	H = (int *)malloc(sizeof(int) * (max + 1));
	for (i = 0; i <= max; i++)
		H[i] = 0;
	for (i = 0; i < n; i++)
		H[A[i]]++;
	i = 0;
	j = 0;
	while (i <= max)
	{
		if (H[i] > 0)
		{
			A[j++] = i;
			H[i]--;
		}
		else
			i++;
	}
	free(H);
}
