#include <stdlib.h>
#include <stdio.h>

struct Matrix
{
	int	*A;
	int	n;
};

// ================Diagonal Matrix=====================//
// Size of 1 dimension Array = n
// Row-Major Mapping = i - 1;

void	SetDiagonal(struct Matrix *m, int i, int j, int x)
{
	if (i == j)
	{
		m->A[i - 1] = x;
	}
}

int	GetDiagonal(struct Matrix m, int i, int j)
{
	if (i == j)
		return (m.A[i - 1]);
	return (0);
}

void	DisplayDiagonal(struct Matrix m)
{
	printf("\nThe Diagonal Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d  ", GetDiagonal(m, i, j));
		printf("\n");
	}
}

// ================LowerTriangle Matrix=====================//
// Size of 1 dimension Array = n * (n + 1) / 2
// Row-Major Mapping = i * (i - 1) / 2 + (j - 1)
// Col-Major Mapping = [n * (j - 1) - (j - 2) * (j - 1) / 2] + (i - j)

void	SetLowerTriangle(struct Matrix *m, int i, int j, int x)
{
	if (i >= j)
		m->A[i * (i - 1) / 2 + (j - 1)] = x;
}

int	GetLowerTriangle(struct Matrix m, int i, int j)
{
	if (i >= j)
		return (m.A[i * (i - 1) / 2 + (j - 1)]);
	return (0);
}

void	DisplayLowerTriangle(struct Matrix m)
{
	printf("\nThe Lower Triangle Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d ", GetLowerTriangle(m, i, j));
		printf("\n");
	}
}

// ================UpperTriangle Matrix=====================//
// Size of 1 dimension Array = n * (n + 1) / 2
// Row-Major Mapping = j * (j - 1) / 2 + (i - 1)
// Col-Major Mapping = [n * (i - 1) - (i - 2) * (i - 1) / 2] + (j - i)

void	SetUpperTriangle(struct Matrix *m, int i, int j, int x)
{
	if (i <= j)
		m->A[j * (j - 1) / 2 + (i - 1)] = x;
}

int	GetUpperTriangle(struct Matrix m, int i, int j)
{
	if (i <= j)
		return (m.A[j * (j - 1) / 2 + (i - 1)]);
	return (0);
}

void	DisplayUpperTriangle(struct Matrix m)
{
	printf("\nThe Upper Triangle Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d ", GetUpperTriangle(m, i, j));
		printf("\n");
	}
}

// ================Symmetric Matrix=====================//
// Size of 1 dimension Array = n * (n + 1) / 2
// Lower Row-Major Mapping = i * (i - 1) / 2 + (j - 1)
// Lower Col-Major Mapping = [n * (j - 1) - (j - 2) * (j - 1) / 2] + (i - j)

void	SetSymmetricMatrix(struct Matrix *m, int i, int j, int x)
{
	if (i >= j)
		SetLowerTriangle(m, i, j, x);
	else
		SetLowerTriangle(m, j, i, x);
}

int	GetSymmetricMatrix(struct Matrix m, int i, int j)
{
	if (i >= j)
		GetLowerTriangle(m, i, j);
	else
		GetLowerTriangle(m, j, i);
}

void	DisplaySymmetricMatrix(struct Matrix m)
{
	printf("\nThe Symmetric Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d ", GetSymmetricMatrix(m, i, j));
		printf("\n");
	}
}

// ================Tridiagonal Matrix=====================//
// Size of 1 dimension Array = 3 * n - 2
// (lower diagonal)Mapping (i - j = 1) = i - 2 
// (main diagonal)Mapping  (i - j = 0) = n - 1 + i - 1
// (upper diagonal)Mapping (i - j = -1) = 2 * n - 1 + j - 2

void	SetTridiagonalMatrix(struct Matrix *m, int i, int j, int x)
{
	if (i - j == 0)
		m->A[m->n - 1 + i - 1] = x;
	else if (i - j == 1)
		m->A[i - 2] = x;
	else if (i - j == -1)
		m->A[2 * m->n - 1 + j - 2] = x;
}

int	GetTridiagonalMatrix(struct Matrix m, int i, int j)
{
	if (i - j == 0)
		return m.A[m.n - 1 + i - 1];
	else if (i - j == 1)
		return m.A[i - 2];
	else if (i - j == -1)
		return m.A[2 * m.n - 1 + j - 2];
	else
		return 0;
}

void	DisplayTridiagonalMatrix(struct Matrix m)
{
	printf("\nThe Tridiagonal Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d ", GetTridiagonalMatrix(m, i, j));
		printf("\n");
	}
}

// ================Toeplitz Matrix=====================//
// Size of 1 dimension Array = n + (n - 1)
// if i <= j -> Mapping = j - i
// if i > j -> Mapping = n + (i - j - 1)

void	SetToeplitzMatrix(struct Matrix *m, int i, int j, int x)
{
	if (i <= j)
		m->A[j - i] = x;
	else
		m->A[m->n + i - j - 1] = x;
}

int	GetToeplitzMatrix(struct Matrix m, int i, int j)
{
	if (i <= j)
		return m.A[j - i];
	else
		return m.A[m.n + i - j - 1];
}

void	DisplayToeplitzMatrix(struct Matrix m)
{
	printf("\nThe Toeplitz Matrix is\n");
	for (int i = 1; i <= m.n; i++)
	{
		for (int j = 1; j <= m.n; j++)
			printf("%d ", GetToeplitzMatrix(m, i, j));
		printf("\n");
	}	
}

// ===================END=====================//

int main(void)
{
	struct Matrix	m;
	
	m.n = 5;
	m.A = (int *)malloc(sizeof(int) * (2 * m.n - 1));

	SetToeplitzMatrix(&m, 1, 1, 2);
	SetToeplitzMatrix(&m, 1, 2, 3);
	SetToeplitzMatrix(&m, 1, 3, 4);
	SetToeplitzMatrix(&m, 1, 4, 5);	
	SetToeplitzMatrix(&m, 1, 5, 6);	
	SetToeplitzMatrix(&m, 2, 1, 7);	
	SetToeplitzMatrix(&m, 3, 1, 8);	
	SetToeplitzMatrix(&m, 4, 1, 9);	
	SetToeplitzMatrix(&m, 5, 1, 6);	

	
	DisplayToeplitzMatrix(m);


}