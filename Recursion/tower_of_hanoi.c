#include <stdio.h>

void tower_of_hanoi(int disks, int A, int B, int C)
{
	if (disks > 0)
	{
		tower_of_hanoi(disks - 1, A, C, B);
		printf("Move from %d to %d\n", A, C);
		tower_of_hanoi(disks - 1, B, A, C);
	}
}
