#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
	int			data;
	struct Node	*next;
};

void	Push(struct Node **top, int x)
{
	struct Node *new;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = x;
	new->next = *top;
	*top = new;
}

int	Pop(struct Node **top)
{
	struct Node *p;
	int			x;

	if (*top)
	{
		p = *top;
		*top = (*top)->next;
		x = p->data;
		free(p);
	}
	else
	{
		printf("Stack is Empty\n");
		x = -1;
	}
	return (x);
}

int	Peek(struct Node *top, int pos)
{
	struct Node *p;

	p = top;
	for (int i = 1; p && i < pos; i++)
		p = p->next;
	if (p)
		return (p->data);
	else
		return (-1);
}

int	StackTop(struct Node *top)
{
	if (top)
		return (top->data);
	else
		return (-1);
}

int	isEmpty(struct Node *top)
{
	if (top)
		return (0);
	return (1);
}

int	isFull()
{
	struct Node *t;

	t = (struct Node *)malloc(sizeof(struct Node));
	if (t)
	{
		free(t);
		return (0);
	}
	return (1);
}

void	enqueue(struct Node	**top1, int x)
{
	Push(top1, x);
}

int	dequeue(struct Node **top1, struct Node **top2)
{
	if (isEmpty(*top2))
	{
		if (isEmpty(*top1))
		{
			printf("Queue is Empty\n");
			return (-1);
		}
		while (!isEmpty(*top1))
			Push(top2, Pop(top1));
	}
	return (Pop(top2));
}

void	Display(struct Node **top1, struct Node **top2)
{
	if (isEmpty(*top2))
	{
		if (isEmpty(*top1))
			return;
		while (!isEmpty(*top1))
			Push(top2, Pop(top1));
	}
	while (!isEmpty(*top2))
		printf("%d  ", Pop(top2));
	Display(top1, top2);
	printf("\n");
}

int main(void)
{
	struct Node *top1;
	struct Node *top2;

	top1 = NULL;
	top2 = NULL;

	enqueue(&top1, 10);
	enqueue(&top1, 20);
	enqueue(&top1, 30);
	enqueue(&top1, 40);
	enqueue(&top1, 50);

	dequeue(&top1, &top2);
	dequeue(&top1, &top2);
	dequeue(&top1, &top2);
	dequeue(&top1, &top2);
	dequeue(&top1, &top2);

	enqueue(&top1, 60);
	enqueue(&top1, 70);
	enqueue(&top1, 80);
	enqueue(&top1, 90);
	enqueue(&top1, 100);

	Display(&top1, &top2);
}