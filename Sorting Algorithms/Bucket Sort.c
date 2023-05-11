#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int			data;
	struct Node	*next;
};


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

void	Insert(struct Node **p, int data)
{
	struct Node *q;
	struct Node *new;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = data;
	new->next = NULL;
	if (*p == NULL)
		*p = new;
	else
	{
		q = *p;
		while (q->next)
			q = q->next;
		q->next = new;
	}
}

int	Delete(struct Node **first)
{
	int 		data;
	struct Node *q;

	q = *first;
	*first = (*first)->next;
	data = q->data;
	free(q);
	return (data);
}

void	BucketSort(int A[], int n)
{
	int i;
	int j;
	int max;
	struct Node	**Bins;

	max = getMax(A, n);
	Bins = (struct Node **)malloc(sizeof(struct Node *) * (max + 1));
	for (i = 0; i <= max; i++)
		Bins[i] = NULL;
	for (i = 0; i < n; i++)
		Insert(&Bins[A[i]], A[i]);
	i = 0;
	j = 0;
	while (i <= max)
	{
		while (Bins[i] != NULL)
			A[j++] = Delete(&Bins[i]);
		i++;
	}
	free(Bins);
}
