#include <stdlib.h>
#include <stdio.h>

struct Element
{
	int	i;
	int	j;
	int	x;
};

struct Sparse
{
	int				m;
	int				n;
	int				num;
	struct Element	*e;
};

void	Create(struct Sparse *s)
{
	printf("Eneter Dimensions (row, col): ");
	scanf("%d %d", &s->m, &s->n);
	printf("Enter number of non-zero Elements: ");
	scanf("%d", &s->num);
	s->e = (struct Element *)malloc(s->num * sizeof(struct Element));
	for (int i = 0; i < s->num; i++)
	{
		printf("Enter an element (row, col, value): ");
		scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
	}
}

int	Get(struct Sparse s, int row, int col)
{
	for (int i = 0; i < s.num; i++)
	{
		if (s.e[i].i == row && s.e[i].j == col)
			return (s.e[i].x);
	}
	return (0);
}

void	Display(struct Sparse s)
{
	printf("\nThe Sparse Matrix is: \n");
	for (int i = 1; i <= s.m; i++)
	{
		for (int j = 1; j <= s.n; j++)
		{
			printf("%d ", Get(s, i, j));
		}
		printf("\n");
	}
}

struct Sparse	*Sum(struct Sparse s1, struct Sparse s2)
{
	int				i;
	int				j;
	int				k;
	struct Sparse	*sum;

	if (s1.m != s2.m || s1.n != s2.n)
		return (0);
	sum = (struct Sparse *)malloc(sizeof(struct Sparse));
	sum->e = (struct Element *)malloc(sizeof(struct Element) * (s1.num + s2.num));
	i = 0;
	j = 0;
	k = 0;
	while (i < s1.num && j < s2.num)
	{
		if (s1.e[i].i < s2.e[j].i)
			sum->e[k++] = s1.e[i++];
		else if (s1.e[i].i > s2.e[j].i)
			sum->e[k++] = s2.e[j++];
		else
		{
			if (s1.e[i].j < s2.e[j].j)
				sum->e[k++] = s1.e[i++];
			else if (s1.e[i].j > s2.e[j].j)
				sum->e[k++] = s2.e[j++];
			else
			{
				sum->e[k] = s1.e[i];
				sum->e[k++].x += s1.e[i++].x + s2.e[j++].x;
			}
		}
	}
	while (i < s1.num)
		sum->e[k++] = s1.e[i++];
	while (j < s2.num)
		sum->e[k++] = s2.e[j++];
	sum->m = s1.m;
	sum->n = s1.n;
	sum->num = k;
	return (sum);
}

int main(void)
{
	struct Sparse	s1;
	struct Sparse	s2;
	struct Sparse	*s;

	Create(&s1);
	printf("========\n");
	Create(&s2);
	printf("========\n");
	Display(s1);
	printf("========\n");
	Display(s2);

	s = Sum(s1, s2);

	Display(*s);


}
