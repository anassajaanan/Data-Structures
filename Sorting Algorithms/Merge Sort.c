#include <stdio.h>

void	Merge(int A[], int l, int mid, int h)
{
	int i;
	int j;
	int k;
	int B[h + 1];

	i = l;
	j = mid + 1;
	k = l;
	while (i <= mid && j <= h)
	{
		if (A[i] < A[j])
			B[k++] = A[i++];
		else
			B[k++] = A[j++];
	}
	while (i <= mid)
		B[k++] = A[i++];
	while (j <= h)
		B[k++] = A[j++];
	for (int i = l; i <= h; i++)
		A[i] = B[i];
}

void	MergeSort(int A[], int n)
{
	int l;
	int h;
	int mid;
	int size;

	size = 1;
	while (size < n)
	{
		l = 0;
		while (l + size < n)
		{
			mid = l + size - 1;
			h = l + (size * 2) - 1;
			if (h >= n)
				h = n - 1;
			Merge(A, l, mid, h);
			l += size * 2;
		}
		size *= 2;
	}
}

void	RMergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		RMergeSort(A, low, mid);
		RMergeSort(A, mid + 1, high);
		Merge(A, low, mid, high);
	}
}
