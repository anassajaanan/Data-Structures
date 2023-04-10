#include <stdio.h>

float taylor(int x, int term)
{
	static float n = 1;
	if (term == 0)
		return n;
	else {
		n = (1 + ((float)x / (float)term) * n);
		taylor(x, term - 1);
	}
}
