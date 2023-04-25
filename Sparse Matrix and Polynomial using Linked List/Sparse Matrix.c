#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int			col;
	int			value;
	struct Node	*next;
};

struct Sparse
{
	int m;
	int n;
	int num;
	struct Node	**A;
};

void	Append(struct Node **first, int col, int value)
{
	struct Node *new;
	struct Node *current;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->col = col;
	new->value = value;
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

void	Create(struct Sparse *s)
{
	struct Node *new;
	struct Node *p;
	int 		row;
	int 		col;
	int 		value;

	printf("Eneter Dimensions (row, col): ");
	scanf("%d %d", &s->m, &s->n);
	printf("Enter number of non-zero Elements: ");
	scanf("%d", &s->num);
	s->A = (struct Node **)malloc(sizeof(struct Node *) * s->num);
	for (int i = 0; i < s->num; i++)
		s->A[i] = NULL;
	for (int i = 0; i < s->num; i++)
	{
		printf("Enter an element (row, col, value): ");
		scanf("%d %d %d", &row, &col, &value);
		Append(&s->A[row], col, value);
	}
}

int	Get(struct Sparse s, int row, int col)
{
	struct Node *p;

	p = s.A[row];
	while (p)
	{
		if (p->col == col)
			return (p->value);
		p = p->next;
	}
	return (0);
}

void	Display(struct Sparse s)
{
	for (int i = 0; i < s.m; i++)
	{
		for (int j = 0; j < s.n; j++)
		{
			printf("%d ", Get(s, i, j));
		}
		printf ("\n");
	}
}

struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
	struct Sparse	*s3;
	struct Node		*p;
	struct Node		*q;
	int				count;

	if (s1->m != s2->m || s1->n != s2->n)
		return (NULL);
	s3 = (struct Sparse *)malloc(sizeof(struct Sparse));
	s3->A = (struct Node **)malloc(sizeof(struct Node) * s1->m);
	count = 0;
	for (int i = 0; i < s1->m; i++)
	{
		p = s1->A[i];
		q = s2->A[i];
		while (p && q)
		{
			if (p->col < q->col)
			{
				Append(&s3->A[i], p->col, p->value);
				p = p->next;
				count++;
			}
			else if (p->col > q->col)
			{
				Append(&s3->A[i], q->col, q->value);
				q = q->next;
				count++;
			}
			else
			{
				Append(&s3->A[i], p->col, p->value + q->value);
				p = p->next;
				q = q->next;
				count++;
			}
		}
		while (p)
		{
			Append(&s3->A[i], p->col, p->value);
			p = p->next;
			count++;
		}
		while (q)
		{
			Append(&s3->A[i], q->col, q->value);
			q = q->next;
			count++;
		}
	}
	s3->m = s1->m;
	s3->n = s1->n;
	s3->num = count;
	return (s3);
}


int main(void)
{
	struct Sparse	s1;
	struct Sparse	s2;
	struct Sparse	*s3;

	Create(&s1);
	printf("========\n");
	Create(&s2);
	printf("========\n");
	Display(s1);
	printf("========\n");
	Display(s2);
	printf("========\n");

	s3 = Add(&s1, &s2);

	Display(*s3);
}

