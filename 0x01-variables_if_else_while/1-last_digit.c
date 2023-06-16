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

	if (abs(n % 10) > 5)
	{
	printf("last digit of %d is %d and is greater than 5\n", n);
	}
	else if (abs(n % 10) == 0)
	{
	printf("last digit of %d is %d and is zero\n", n);
	}
	else
	{
	printf("last digit of %d is %d and is less than 6 and not 0\n", n);
	}

	return (0);

}
