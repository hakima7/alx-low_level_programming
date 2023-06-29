#include "main.h"
#include <stdio.h>

/**
 * print_number - prints an integer
 * @n: The integer to print
 */

void print_number(int n)
{
	int divisor = 1;

	if (n < 0)
	{
		putchar('-');
		n = -n;
	}

	while (n / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		putchar('0' + n / divisor);
		n %= divisor;
		divisor /= 10;
	}
}
