#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *A[3];

	A[0] = (int *)malloc(sizeof(int) * 4);
	A[1] = (int *)malloc(sizeof(int) * 4);
	A[2] = (int *)malloc(sizeof(int) * 4);

	int n = 1;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			A[i][j] = n;
			n++;
		}
		
	}

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");	
	}
	

}