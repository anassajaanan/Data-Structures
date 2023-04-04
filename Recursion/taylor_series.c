#include <stdio.h>

int exponent(int base, int power)
{
    if (power == 0)
        return 1;
    if (power % 2 == 0)
    {
        return exponent(base * base, power / 2);
    }
    else
    {
        return base * exponent(base * base, (power - 1) / 2);
    }
}

int factorial(int n)
{
    if (n > 0)
        return factorial(n - 1) * n;
    return 1;
}

float taylor(int x, int n_term)
{
    if (n_term == 1)
        return 1;
    else
    {
        return taylor(x, n_term-1) + ((float)exponent(x, n_term-1) / (float)factorial(n_term - 1));
    }
}
