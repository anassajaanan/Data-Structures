#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int data;
	struct Node *next;
};


int isLoop(struct Node *first)
{
	struct Node *p;
	struct Node *q;

	p = first;
	q = first;
	while (q)
	{
		p = p->next;
		q = q->next;
		if (q)
			q = q->next;
		else
			break;
		if (p == q)
			return 1;
	}
	return (0);
}

void	DisplayCircular(struct Node *head)
{
	struct Node	*p;

	p = head;
	while (p)
	{
		printf(" -> %d ->", p->data);
		p = p->next;
		if (p == head)
			break;
	}
	printf("\n");
}

void	RDisplay(struct Node *head, struct Node *p)
{
	static int	counter = 0;
	
	if (p != head || counter == 0)
	{
		counter++;
		printf("%d ", p->data);
		RDisplay(head, p->next);
	}
	else
		printf("\n");
}

int	CountCircular(struct Node *h)
{
	struct Node *p;
	int			i;

	p = h;
	i = 0;
	if (p == NULL)
		return (0);
	while (p->next != h)
	{
		p = p->next;
		i++;
	}
	return (i + 1);
}

void	CircularInsert(struct Node **head, int index, int n)
{
	struct Node *new;
	struct Node *p;

	if (index < 0 || index > CountCircular(*head))
		return;
	p = (*head);
	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = n;
	if (index == 0)
	{
		if ((*head) == NULL)
		{
			(*head) = new;
			(*head)->next = (*head);
		}
		else
		{
			while (p->next != *head)
				p = p->next;
			new->next = p->next;
			p->next = new;
			*head = new;
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		new->next = p->next;
		p->next = new;
	}
}

int	CircularDelete(struct Node **head, int pos)
{
	struct Node *p;
	struct Node *q;
	int			i;
	int			n;

	if (pos < 1 || pos > CountCircular(*head))
		return (-1);
	p = (*head);
	if (pos == 1)
	{
		while (p->next != *head)
			p = p->next;
		n = (*head)->data;
		if (p == *head)
		{
			free(*head);
			*head = NULL;
			return (n);
		}
		p->next = (*head)->next;
		free(*head);
		*head = p->next;
		return (n);
	}
	else
	{
		i = 1;
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
}
