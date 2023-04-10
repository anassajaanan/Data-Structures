#include <stdlib.h>
#include <stdio.h>

struct Array
{
	int A[10];
	int size;
	int length;
};

void	Display(struct Array arr)
{
	printf("\nElements are: \n");
	for (size_t i = 0; i < arr.length; i++)
	{
		printf("%d ", arr.A[i]);
	}
	printf("\n");
}

void	Append(struct Array *arr, int n)
{
	if (arr->length < arr->size)
		arr->A[arr->length++] = n;
}

void	Insert(struct Array *arr, int index, int n)
{
	if (index >= 0 && index <= arr->length)
	{
		for (size_t i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = n;
		arr->length++;
	}
}

int	Delete(struct Array *arr, int index)
{
	int	res;

	res = 0;
	if (index >= 0 && index < arr->length)
	{
		res = arr->A[index];
		for (size_t i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];
		arr->length--;
	}
	return (res);
}

void swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	LinearSearch(struct Array *arr, int key)
{
	for (size_t i = 0; i < arr->length; i++)
	{
		if (arr->A[i] == key)
		{
			// Move key to Front/Head.
			swap(&arr->A[0], &arr->A[i]);
			return (i);
		}
	}
	return (-1);
}

int	BinarySearch(struct Array arr, int key)
{
	int	l;
	int	h;
	int	mid;

	l = 0;
	h = arr.length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return (mid);
		else if (key > arr.A[mid])
			l = mid + 1;
		else if (key < arr.A[mid])
			h = mid - 1;
	}
	return (-1);
}

int	R_BinarySearch(int *A, int l, int h, int key)
{
	int	mid;

	if (l > h)
		return (-1);
	mid = (l + h) / 2;
	if (key == A[mid])
		return (mid);
	else if (key > A[mid])
		l = mid + 1;
	else if (key < A[mid])
		h = mid - 1;
	R_BinarySearch(A, l, h, key);
}

int	Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return (arr.A[index]);
	return (-1);
}

void	Set(struct Array *arr, int index, int n)
{
	if (index >= 0 && index < arr->length)
		arr->A[index] = n;
}

int	Max(struct Array arr)
{
	int	max;

	max = arr.A[0];
	for (size_t i = 1; i < arr.length; i++)
	{
		if (arr.A[i] > max)
			max = arr.A[i];
	}
	return (max);
}

int	Min(struct Array arr)
{
	int	min;

	min = arr.A[0];
	for (size_t i = 1; i < arr.length; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
	}
	return (min);
}

int	Sum(struct Array arr)
{
	int	sum;

	sum = 0;
	for (size_t i = 0; i < arr.length; i++)
		sum += arr.A[i];
	return (sum);
}

float	Avg(struct Array arr)
{
	return ((float)Sum(arr) / arr.length);
}

void	Reverse(struct Array *arr)
{
	int	temp;

	for (size_t i = 0; i < arr->length / 2; i++)
	{
		temp = arr->A[i];
		arr->A[i] = arr->A[arr->length - 1 - i];
		arr->A[arr->length - 1 - i] = temp;
	}
}

void	LeftShift(struct Array *arr)
{
	for (size_t i = 0; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->A[arr->length - 1] = 0;
}

void	LeftRotate(struct Array *arr)
{
	int	first;

	first = arr->A[0];
	for (size_t i = 0; i < arr->length - 1; i++)
	{
		arr->A[i] = arr->A[i + 1];
	}
	arr->A[arr->length - 1] = first;
}

void	InsertSort(struct Array *arr, int n)
{
	int	i;

	if (arr->length < arr->size)
	{
		i = arr->length - 1;
		while (arr->A[i] > n && i>= 0)
		{
			arr->A[i + 1] = arr->A[i];
			i--;
		}
		arr->A[i + 1] = n;
		arr->length++;
	}
}

int	isSorted(struct Array arr)
{
	for (size_t i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return (0);
	}
	return (1);
}

void	ReArrange(struct Array *arr)
{
	int	i;
	int	j;

	i = 0;
	j = arr->length - 1;
	while (i < j)
	{
		while(arr->A[i] < 0)
			i++;
		while (arr->A[j] >= 0)
			j--;
		if (i < j)
			swap(&arr->A[i], &arr->A[j]);
	}
}

struct Array	*Merge(struct Array *arr1, struct Array *arr2)
{
	int				i;
	int				j;
	int				k;
	struct Array	*arr3;

	arr3 = (struct Array *)malloc(sizeof(struct Array));
	i = 0;
	j = 0;
	k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	while (i < arr1->length)
		arr3->A[k++] = arr1->A[i++];
	while (j < arr2->length)
		arr3->A[k++] = arr2->A[j++];
	arr3->length = arr1->length + arr2->length;
	arr3->size = arr3->length;
	return (arr3);
}

struct Array	*Union(struct Array *arr1, struct Array *arr2)
{
	int				i;
	int				j;
	int				k;
	struct Array	*arr3;

	arr3 = (struct Array *)malloc(sizeof(struct Array));
	i = 0;
	j = 0;
	k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr1->A[i] > arr2->A[j])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	while (i < arr1->length)
		arr3->A[k++] = arr1->A[i++];
	while (j < arr2->length)
		arr3->A[k++] = arr2->A[j++];
	arr3->length = k;
	return (arr3);
}

struct Array	*Intersection(struct Array *arr1, struct Array *arr2)
{
	int				i;
	int				j;
	int				k;
	struct Array	*arr3;

	arr3 = (struct Array *)malloc(sizeof(struct Array));
	i = 0;
	j = 0;
	k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	arr3->length = k;
	return (arr3);
}

struct Array	*Difference(struct Array *arr1, struct Array *arr2)
{
	int				i;
	int				j;
	int				k;
	struct Array	*arr3;

	arr3 = (struct Array *)malloc(sizeof(struct Array));
	i = 0;
	j = 0;
	k = 0;
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr1->A[i] > arr2->A[j])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	while (i < arr1->length)
		arr3->A[k++] = arr1->A[i++];
	arr3->length = k;
	return (arr3);
}


void FindMissingElement(struct Array arr) // using Hash Table
{
	int l;
	int h;
	int	*H;

	l = Min(arr);
	h = Max(arr);
	H = (int *)malloc(sizeof(int) * h + 1);
	for (int i = 0; i < h; i++)
		H[i] = 0;
	for (int j = 0; j < arr.length; j++)
		H[arr.A[j]] = 1;
	for (int k = l; k <= h; k++)
	{
		if (H[k] == 0)
			printf("the missing is : %d\n", k);
	}
	free(H);
}

void	FindDuplicate1(struct Array arr) // For sorted Array
{
	int	count;

	for (size_t i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] == arr.A[i + 1])
		{
			count = 1;
			while (arr.A[i] == arr.A[i + 1] && i < arr.length - 1)
			{
				i++;
				count++;
			}
			printf("%d is duplicated %d times\n", arr.A[i], count);
		}
	}	
}

void	FindDuplicate2(struct Array arr) // For unsorted Array(Hash Table)
{
	int	h;
	int	*H;

	h = Max(arr);
	H = (int *)malloc(sizeof(int) * (h + 1));
	for (int i = 0; i <= h; i++)
		H[i] = 0;
	for (int i = 0; i < arr.length; i++)
		H[arr.A[i]]++;
	for (int i = 0; i <= h; i++)
	{
		if (H[i] > 1)
			printf("%d is duplicated %d times\n", i, H[i]);
	}
	free(H);
}

void	FindPairWithSumK1(struct Array arr, int k) // Time complexity is (n * n) - Insorted Array
{
	for (int i = 0; i < arr.length; i++)
	{
		for (int j = i + 1; j < arr.length; j++)
		{
			if (arr.A[i] + arr.A[j] == k)
			{
				printf("A pair found!!, %d and %d\n", arr.A[i], arr.A[j]);
			}
		}
	}
}

void	FindPairWithSumK2(struct Array arr, int k) // Time comlexity is (n) : Hash Table - Insorted Array
{
	int	*H;
	int	h;

	h = Max(arr);
	H = (int *)malloc(sizeof(int) * (h + 1));
	for (int i = 0; i <= h; i++)
		H[i] = 0;
	for (int i = 0; i < arr.length; i++)
	{
		if (H[k - arr.A[i]] != 0)
			printf("A pair found!!, %d and %d\n", arr.A[i], k - arr.A[i]);
		H[arr.A[i]]++;
	}
}

void	FindPairWithSumK3(struct Array arr, int k) // Sorted Array
{
	int	i;
	int	j;

	i = 0;
	j = arr.length - 1;
	while (i < j)
	{
		if (arr.A[i] + arr.A[j] == k)
			printf("A pair found!!, %d and %d\n", arr.A[i++], arr.A[j--]);
		else if (arr.A[i] + arr.A[j] > k)
			j--;
		else
			i++;
	}
}

void	FindMinMax(struct Array arr)
{
	int max;
	int min;

	max = arr.A[0];
	min = arr.A[0];
	for (int i = 1; i < arr.length - 1; i++)
	{
		if (arr.A[i] < min)
			min = arr.A[i];
		else if (arr.A[i] > max)
			max = arr.A[i];
	}
	printf("The min is %d and the max is %d\n", min, max);
}


int main(void)
{
	struct Array	arr = {{5, 8, -3, 9, 6, 2, 10, 77, -1, 4}, 10, 10};
	
	FindMinMax(arr);
}
