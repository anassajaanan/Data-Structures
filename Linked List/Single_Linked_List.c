#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void	Display(struct Node *p)
{
	while (p)
	{
		printf("%d -> ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void	RecursiveDisplay(struct Node *p)
{
	if (p)
	{
		printf("%d -> ", p->data);
		RecursiveDisplay(p->next);
	}
	else
	{
		printf("NULL\n");
		return;
	}
}

void	RevRecursiveDisplay(struct Node *p)
{
	if (p)
	{
		RevRecursiveDisplay(p->next);
		printf(" <- %d", p->data);
	}
	else
	{
		printf("NULL");
		return;
	}
}

int	count(struct Node *p)
{
	int counter;

	counter = 0;
	while (p)
	{
		counter++;
		p = p->next;
	}
	return (counter);
}

int	RecursiveCount(struct Node *p)
{
	static int counter = 0;

	if (p)
	{
		counter++;
		RecursiveCount(p->next);
	}
	return (counter);
}

int	Sum(struct Node *p)
{
	int	sum;

	sum = 0;
	while (p)
	{
		sum += p->data;
		p = p->next;
	}
	return (sum);
}

int RecursiveSum(struct Node *p)
{
	if (p)
		return (RecursiveSum(p->next) + p->data);
	else
		return 0;
}

int	Max(struct Node *p)
{
	int	max;

	while(p)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
	}
	return (max);
}

int	RecursiveMax(struct Node *p)
{
	static int max;

	if (p)
	{
		if (p->data > max)
			max = p->data;
		RecursiveMax(p->next);
	}
	return (max);
}

int	Min(struct Node *p)
{
	int	min;

	while(p)
	{
		if (p->data < min)
			min = p->data;
		p = p->next;
	}
	return (min);
}

struct Node	*LSearch(struct Node *p, int key) // Linear Search
{
	while (p)
	{
		if (key == p->data)
			return (p);
		p = p->next;
	}
	return (NULL);
}

struct Node	*Search1(struct Node **first, int key) // Linear Search (Improved with : Move to Front/Head)
{
	struct Node	*p;
	struct Node *q;

	p = (*first);
	q = NULL;
	while (p)
	{
		if (key == p->data && q == NULL)
			return (p);
		else if (key == p->data && q)
		{
			q->next = p->next;
			p->next = (*first);
			(*first) = p;
			return (p);
		}
		q = p;
		p = p->next;
	}
	return (NULL);
}

void	Append(struct Node **first, int n)
{
	struct Node *new;
	struct Node *current;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = n;
	new->next = NULL;
	if (*first == NULL)
		(*first) = new;
	else
	{
		current = (*first);
		while (current->next)
			current = current->next;
		current->next = new;
	}	
}

void	Insert(struct Node **first, int index, int x)
{
	struct Node	*new;
	struct Node *p;
	int			i;

	if (index < 0 || index > count(*first))
		return;
	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	if (index == 0)
	{
		new->next = (*first);
		(*first) = new;
		return;
	}
	i = 0;
	p = (*first);
	while (i < index - 1)
	{
		p = p->next;
		i++;
	}
	new->next = p->next;
	p->next = new;
}

void	SortedInsert(struct Node **first, int x)
{
	struct Node *p;
	struct Node *q;
	struct Node *new;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	new->next = NULL;
	p = (*first);
	q = NULL;
	if (p == NULL)
		(*first) = new;
	else
	{
		while (p && p->data < x)
		{
			q = p;
			p = p->next;
		}
		new->next = p;
		if (q == NULL)
			(*first) = new;
		else
			q->next = new;
	}
}

int	Delete(struct Node **first, int pos)
{
	struct Node *p;
	struct Node *q;
	int			i;
	int			n;

	if (pos < 1 || pos > count(*first))
		return (-1);
	i = 1;
	p = (*first);
	if (pos == 1)
	{
		(*first) = p->next;
		n = p->data;
		free(p);
		return (n);
	}
	while (i < pos - 1)
	{
		p = p->next;
		i++;
	}
	q = p->next;
	p->next = q->next;
	n = q->data;
	free(q);
	return (n);
}

int	isSorted(struct Node *p)
{
	while (p->next)
	{
		if (p->data > p->next->data)
			return (0);
		p = p->next;
	}

	return (1);
}

void	RemoveDuplicates(struct Node *p)
{
	struct Node *q;

	q = p->next;
	while (q)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			free(q);
			q = p->next;
		}
	}
	
}

void	RRemoveDuplicates(struct Node *p) // Using Recursion
{
	struct Node *q;

	q = p->next;
	if (q)
	{
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
			RemoveDuplicates(p);
		}
		else
			RemoveDuplicates(p->next);
	}
	else
		return;
}

void	Reverse(struct Node **first) // Using Sliding Pointers
{
	struct Node	*p;
	struct Node	*q;
	struct Node	*r;

	p = (*first);
	q = NULL;
	r = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	(*first) = q;
}

void	RecursiveReverse(struct Node **first, struct Node *p, struct Node *q)
{
	if (p)
	{
		RecursiveReverse(first, p->next, p);
		p->next = q;
	}
	else
		(*first) = q;
}

void	ReverseElements(struct Node **first) // Reversing Elements
{
	int			i;
	struct Node	*p;
	int			A[count(*first)];

	p = (*first);
	while (p)
	{
		A[i++] = p->data;
		p = p->next;
	}
	p = (*first);
	i--;
	while (p)
	{
		p->data = A[i--];
		p = p->next;
	}
}

void	Concatenate(struct Node *p, struct Node *q)
{
	while (p->next)
		p = p->next;
	p->next = q;
}

struct Node *Merge(struct Node *first, struct Node *second)
{
	struct Node	*third;
	struct Node	*last;

	if (first->data < second->data)
	{
		third = first;
		last = first;
		first = first->next;
	}
	else
	{
		third = second;
		last = second;
		second = second->next;
	}
	while (first && second)
	{
		if (first->data < second->data)
		{
			last->next = first;
			last = first;
			first = first->next;
		}
		else
		{
			last->next = second;
			last = second;
			second = second->next;
		}
	}
	if (first)
		last->next = first;
	if (second)
		last->next = second;
	return (third);
}

struct Node *Merge1(struct Node *p, struct Node *q)
{
	struct Node *res;

	res = NULL;
	while (p && q)
	{
		if (p->data < q->data)
		{
			Append(&res, p->data);
			p = p->next;
		}
		else if (p->data > q->data)
		{
			Append(&res, q->data);
			q = q->next;
		}
		else
		{
			Append(&res, p->data);
			p = p->next;
			q = q->next;
		}
	}
	while (p)
	{
		Append(&res, p->data);
		p = p->next;
	}
	while (q)
	{
		Append(&res, q->data);
		q = q->next;
	}
	return (res);
}

struct Node	*FindMiddleNode(struct Node *p)
{
	struct Node *q;

	q = p;
	while (p)
	{
		p = p->next;
		if (p)
			p = p->next;
		if (p)
			q = q->next;
	}
	return (q);
}


int main(void)
{
	struct Node *first;
	struct Node *mid;

	first = NULL;
	Append(&first, 8);
	Append(&first, 6);
	Append(&first, 3);
	Append(&first, 9);
	Append(&first, 10);
	Append(&first, 4);
	Append(&first, 2);
	Append(&first, 7);

	mid = FindMiddleNode(first);

	printf("%d\n", mid->data);

}