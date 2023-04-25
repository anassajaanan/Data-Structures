#include <stdlib.h>
#include <stdio.h>

struct Node
{
	struct Node	*prev;
	int			data;
	struct Node	*next;
};


void	Append(struct Node **first,struct Node **last, int n)
{
	struct Node *new;
	struct Node *p;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = n;
	new->prev = NULL;
	new->next = NULL;
	if (*first == NULL)
	{
		(*first) = new;
		(*last) = new;
	}
	else
	{
		new->prev = *last;
		(*last)->next = new;
		(*last) = new;
		
	}
}

void	Display(struct Node *p)
{
	printf("NULL ");
	while (p)
	{
		printf("<--> %d ", p->data);
		p = p->next;
	}
	printf("--> NULL\n");
}

int	Length(struct Node *p)
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

void	Insert(struct Node **first, int index, int n)
{
	struct Node *new;
	struct Node *p;
	struct Node *q;
	int			i;

	if (index < 0 || index > Length(*first))
		return;
	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = n;
	if (index == 0)
	{
		new->prev = NULL;
		new->next = (*first);
		if (*first)
			(*first)->prev = new;
		(*first) = new;
	}
	else
	{
		i = 0;
		p = (*first);
		while (i < index - 1)
		{
			p = p->next;
			i++;
		}
		q = p->next;
		new->next = q;
		new->prev = p;
		if (q)
			q->prev = new;
		p->next = new;
	}
}

int	Delete(struct Node **first, int pos)
{
	struct Node *p;
	int			i;
	int			n;

	if (pos < 1 || pos > Length(*first))
		return (-1);
	p = *first;
	if (pos == 1)
	{
		n = p->data;
		if (p->next)
			p->next->prev = NULL;
		(*first) = p->next;
		free(p);
	}
	else
	{
		i = 0;
		while (i < pos - 1)
		{
			p = p->next;
			i++;
		}
		n = p->data;
		p->prev->next = p->next;
		if (p->next)
			p->next->prev = p->prev;
		free(p);
	}
	return (n);
}

void	Reverse(struct Node **first)
{
	struct Node *temp;
	struct Node *p;

	p = *first;
	while (p)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if (p && p->next == NULL)
			(*first) = p;
	}
}

int main(void)
{
	struct Node *first;
	struct Node *last;

	first = NULL;
	last = NULL;
	Append(&first, &last, 1);
	Append(&first, &last, 2);
	Append(&first, &last, 3);
	Append(&first, &last, 4);
	Append(&first, &last, 5);
	Append(&first, &last, 6);

	Display(first);

	Reverse(&first);

	Display(first);
}
