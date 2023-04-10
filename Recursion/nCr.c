#include <stdio.h>

int nCr(int n, int r)
{
	if (r == 0 || n == r)
		return 1;
	return nCr(n - 1, r) + nCr(n - 1, r - 1);
}
