#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int *array1;
	int *array2;

	array1 = (int *)malloc(sizeof(int) * 5);
	array1[0] = 1;
	array1[1] = 2;
	array1[2] = 3;
	array1[3] = 4;
	array1[4] = 5;

	
	array2 = (int *)malloc(sizeof(int) * 10);
	memcpy(array2, array1, sizeof(int) * 5);
	free(array1);
	array1 = array2;
	array2 = NULL;

	array1[5] = 6;
	array1[6] = 7;
	array1[7] = 8;
	array1[8] = 9;
	array1[9] = 10;

	
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", array1[i]);
	}	
}