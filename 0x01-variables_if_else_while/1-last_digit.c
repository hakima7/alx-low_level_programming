#include <stdlib.h>

#include <time.h>

#include <stdio.h>



/**
 * main - prints a text according number
 * Return: Always (Success)
 *
 */

int main(void)

{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("Last digit of %d is %d ", n, abs(n % 10));

	if (abs(n % 10) > 5)
	{
	printf("and is greater than 5\n");
	}
	else if (abs(n % 10) == 0)
	{
	printf("and is 0\n");
	}
	else
	{
	printf("and is less than 6 and not 0\n");
	}
	return (0);
}
