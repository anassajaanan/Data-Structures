#include <stdlib.h>
#include <stdio.h>

struct Term
{
	int	coeff;
	int	exp;
};

struct Poly
{
	int	n;
	struct Term	*t;
};

void	Create(struct Poly *p)
{
	printf("Enter the number of non_zero terms: ");
	scanf("%d", &p->n);
	p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
	printf("Enter Terms\n");
	for (int i = 0; i < p->n; i++)
	{
		printf("Enter %d term (coeff, exp) :", i + 1);
		scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
	}
}

void	Display(struct Poly p)
{
	printf("\nP(x) = ");
	for (int i = 0; i < p.n; i++)
	{
		if (i == 0)
			printf("%dx^%d ", p.t[i].coeff, p.t[i].exp);
		else
			printf("+ %dx^%d ", p.t[i].coeff, p.t[i].exp);
	}
	printf("\n");
}

struct Poly	*add(struct Poly *p1, struct Poly *p2)
{
	struct Poly	*p3;
	int	i;
	int	j;
	int	k;

	p3 = (struct Poly *)malloc(sizeof(struct Poly));
	p3->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));
	i = 0;
	j = 0;
	k = 0;
	while (i < p1->n && j < p2->n)
	{
		if (p1->t[i].exp > p2->t[j].exp)
			p3->t[k++] = p1->t[i++];
		else if (p1->t[i].exp < p2->t[j].exp)
			p3->t[k++] = p2->t[j++];
		else
		{
			p3->t[k].exp = p1->t[i].exp;
			p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
		}
	}
	while (i < p1->n)
		p3->t[k++] = p1->t[i++];
	while (j < p2->n)
		p3->t[k++] = p2->t[j++];
	p3->n = k;
	return (p3);
}

int main(void)
{
	struct Poly p1;
	struct Poly p2;

	Create(&p1);
	printf("\n\n");
	Create(&p2);
	printf("\n\n");

	Display(p1);
	Display(p2);

	struct Poly *p3 = add(&p1, &p2);
	Display(*p3);
}

