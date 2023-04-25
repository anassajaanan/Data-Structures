#include <stdlib.h>
#include <stdio.h>

struct Node
{
	struct Node	*prev;
	int			data;
	struct Node	*next;
};

void	Display(struct Node *head)
{
	struct Node *p;
	int count;

	p = head;
	count = 0;
	while (p != head || count == 0)
	{
		count++;
		printf("<- %d -> ", p->data);
		p = p->next;
	}
	printf("\n");
}

int	Length(struct Node *head)
{
	struct Node *p;
	int			count;

	p = head;
	count = 0;
	while (p && (p != head || count == 0))
	{
		count++;
		p = p->next;
	}
	return (count);
}

void	Insert(struct Node **head, int index, int n)
{
	struct Node *new;
	struct Node *p;
	int			i;

	if (index < 0 || index > Length(*head))
		return;
	new = (struct Node *)malloc(sizeof(struct Node));
	new->data = n;
	if (index == 0)
	{
		if (*head == NULL)
		{
			new->next = new;
			new->prev = new;
			(*head) = new;
			return;
		}
		else
		{
			new->next = *head;
			new->prev = (*head)->prev;
			(*head)->prev->next = new;
			(*head)->prev = new;
			(*head) = new;
		}
	}
	else
	{
		p = *head;
		i = 0;
		while (i < index - 1)
		{
			p = p->next;
			i++;
		}
		new->next = p->next;
		new->prev = p;
		p->next->prev = new;
		p->next = new;
	}
}

int	Delete(struct Node **head, int pos)
{
	struct Node *p;
	int			i;
	int			n;

	if (pos < 1 || pos > Length(*head))
		return (-1);
	p = *head;
	if (pos == 1)
	{
		n = p->data;
		if ((*head)->prev == *head)
			*head = NULL;
		else
		{
			(*head) = (*head)->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
		}
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
		p->next->prev = p->prev;
		free(p);
	}
	return (n);
}

int main(void)
{
	struct Node *head;

	head = NULL;
	Insert(&head, 0, 7);
	Insert(&head, 0, 6);
	Insert(&head, 0, 5);
	Insert(&head, 0, 4);
	Insert(&head, 0, 3);
	Insert(&head, 0, 2);
	Insert(&head, 0, 1);

	Display(head);

	printf("%d\n", Delete(&head, 1));

	Display(head);
}