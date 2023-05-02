#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct node
{
	void		*data;
	struct node	*next;
} node;

typedef struct queue
{
	node	*front;
	node	*rear;
} queue;

void	createQueue(queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}

void	Enqueue(queue *q, void	*data)
{
	node	*newNode;

	newNode = (node *)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	if (q->front == NULL)
	{
		q->front = newNode;
		q->rear = newNode;
	}
	else
	{
		q->rear->next = newNode;
		q->rear = newNode;
	}
}

void	*Dequeue(queue *q)
{
	node	*p;
	void	*data;

	if (q->front == NULL)
		return (NULL);
	else
	{
		p = q->front;
		q->front = q->front->next;
		data = p->data;
		free(p);
		return (data);
	}
}

void	*QueueFront(queue q)
{
	if (q.front == NULL)
		return (NULL);
	return (q.front->data);
}

int	queueIsEmpty(queue q)
{
	if (q.front == NULL)
		return (1);
	return (0);
}

#endif /* QUEUE_H */