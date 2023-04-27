#include <stdlib.h>
#include <stdio.h>

struct Queue
{
	int	size;
	int	front;
	int	rear;
	int	*Q;
};

void	Create(struct Queue *q, int size)
{
	q->size = size;
	q->front = 0;
	q->rear = 0;
	q->Q = (int *)malloc(sizeof(int) * size);
}

void	Display(struct Queue q)
{
	int	i;

	if (q.front == q.rear)
		printf("Queue is Empty\n");
	else
	{
		i = q.front + 1;
		printf("Front  ");
		while (i != (q.rear + 1) % q.size)
		{
			printf("  %d  ", q.Q[i]);
			i = (i + 1) % q.size;
		}
		printf("  Rear\n");
	}
}

void	enqueue(struct Queue *q, int x)
{
	if ((q->rear + 1) % q->size == q->front)
		printf("Queue is Full\n");
	else
	{
		q->rear = (q->rear + 1) % q->size;
		q->Q[q->rear] = x;
	}
}

int	dequeue(struct Queue *q)
{
	if (q->front == q->rear)
	{
		printf("Queue is Empty\n");
		return (-1);
	}
	else
	{
		q->front = (q->front + 1) % q->size;
		return (q->Q[q->front]);
	}
}


int main(void)
{
	struct Queue	q;

	Create(&q, 5);

	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);

	Display(q);
}
