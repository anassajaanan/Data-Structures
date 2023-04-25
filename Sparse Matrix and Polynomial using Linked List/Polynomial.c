#include <stdlib.h>
#include <stdio.h>

struct Node
{
	int	coeff;
	int	exp;
	struct Node	*next;
};

int power(int base, int exponent)
{
	int result;

	result = 1;
	for (exponent; exponent > 0; exponent--)
		result = result * base;
	return result;
}

void	Append(struct Node **first, int coeff, int exp)
{
	struct Node *new;
	struct Node *current;

	new = (struct Node *)malloc(sizeof(struct Node));
	new->coeff = coeff;
	new->exp = exp;
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

void	Create(struct Node **Poly)
{
	int	n;
	int	coeff;
	int	exp;

	printf("Enter the number of terms: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d term (coeff, exp) : ", i + 1);
		scanf("%d %d", &coeff, &exp);
		Append(Poly, coeff, exp);
	}
}

void	Dispaly(struct Node *p)
{
	printf("\nP(x) = ");
	while (p)
	{
		printf("%dx^%d + ", p->coeff, p->exp);
		p = p->next;
	}
	printf("\n");
}

int	P(struct Node *p, int x)
{
	int sum;

	sum = 0;
	while (p)
	{
		sum += p->coeff * power(x, p->exp);
		p = p->next;
	}
	return (sum);
}

struct Node *Add(struct Node *p1, struct Node *p2)
{
	struct Node *p3;
	
	p3 = NULL;
	while (p1 && p2)
	{
		if (p1->exp > p2->exp)
		{
			Append(&p3, p1->coeff, p1->exp);
			p1 = p1->next;
		}
		else if (p1->exp < p2->exp)
		{
			Append(&p3, p2->coeff, p2->exp);
			p2 = p2->next;
		}
		else
		{
			Append(&p3, p1->coeff + p2->coeff, p1->exp);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1)
	{
		Append(&p3, p1->coeff, p1->exp);
		p1 = p1->next;
	}
	while (p2)
	{
		Append(&p3, p2->coeff, p2->exp);
		p2 = p2->next;
	}
	return (p3);
}

int main(void)
{
	struct Node	*p1;
	struct Node	*p2;
	struct Node	*p3;

	p1 = NULL;
	p2 = NULL;
	Create(&p1);
	Create(&p2);

	Dispaly(p1);
	Dispaly(p2);

	p3 = Add(p1, p2);

	Dispaly(p3);
}