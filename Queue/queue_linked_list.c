#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int			data;
	struct Node	*next;
};

void	Display(struct Node *front)
{
	struct Node	*p;

	p = front;
	printf("Front  ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf(" Rear\n");
}

void	enqueue(struct Node **front, struct Node **rear, int x)
{
	struct Node	*new;

	new = (struct Node *)malloc(sizeof(struct Node));
	if (new == NULL)
		printf("Queue is Full\n");
	else
	{
		new->data = x;
		new->next = NULL;
		if (*front == NULL)
		{
			*front = new;
			*rear = new;
		}
		else
		{
			(*rear)->next = new;
			(*rear) = new;
		}
	}
}

int	dequeue(struct Node **front, struct Node **rear)
{
	struct Node *p;
	int			x;

	if (*front == NULL)
		return (-1);
	else
	{
		p = *front;
		x = p->data;
		*front = (*front)->next;
		free(p);
		return (x);
	}
}

int main(void)
{
	struct Node	*front;
	struct Node	*rear;

	front = NULL;
	rear = NULL;

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);
	enqueue(&front, &rear, 40);

	printf("%d\n", dequeue(&front, &rear));
	printf("%d\n", dequeue(&front, &rear));

	Display(front);
}
