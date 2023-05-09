#include <stdio.h>
#include <stdlib.h>

struct BinaryHeap
{
	int capacity;
	int size;
	int *heapArray;
};

struct BinaryHeap	*createHeap(int capacity)
{
	struct BinaryHeap	*heap;

	heap = (struct BinaryHeap *)malloc(sizeof(struct BinaryHeap));
	heap->heapArray = (int *)malloc(sizeof(int) * (capacity + 1));
	heap->capacity = capacity;
	heap->size = 0;
	return (heap);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	Insert(struct BinaryHeap *heap, int n)
{
	int	i;

	if (heap->size >= heap->capacity)
	{
		printf("Heap is Full\n");
		return;
	}
	heap->size++;
	i = heap->size;
	heap->heapArray[i] = n;
	while (i > 1 && heap->heapArray[i] > heap->heapArray[i / 2])
	{
		swap(&heap->heapArray[i], &heap->heapArray[i / 2]);
		i = i / 2;
	}
}

int	Delete(struct BinaryHeap *heap)
{
	int x;

	if (heap->size == 0)
	{
		printf("Heap is Empty\n");
		return (-1);
	}
	x = heap->heapArray[1];
	swap(&heap->heapArray[1], &heap->heapArray[heap->size]);
	heap->size--;
	int i = 1;
	int j = 2 * i;
	while (j <= heap->size)
	{
		if ((j + 1 <= heap->size) && heap->heapArray[j] < heap->heapArray[j + 1])
			j = j + 1;
		if (heap->heapArray[i] < heap->heapArray[j])
		{
			swap(&heap->heapArray[i], &heap->heapArray[j]);
			i = j;
			j = 2 * j;
		}
		else
			break;
	}
	return (x);
}

void heapify(int arr[], int size)
{
	int	i;
	int j;
	int k;

	i = size;
	while (i >= 1)
	{
		k = i;
		j = 2 * k;
		while (j <= size)
		{
			if ((j + 1 <= size) && arr[j + 1] > arr[j])
				j = j + 1;
			if (arr[j] > arr[k])
			{
				swap(&arr[j], &arr[k]);
				k = j;
				j = 2 * k;
			}
			else
				break;
		}
		i--;
	}
}


int main(void)
{
	struct BinaryHeap *heap;

	int A[] = {0, 5, 10, 30, 20, 35, 40, 15};

	heapify(A, 7);

	for (int i = 1; i <= 7; i++)
		printf("%d ", A[i]);
	
	
}
