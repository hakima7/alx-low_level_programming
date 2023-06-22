#include "main.h"
#include <stdio.h>

/**
 * main - prints a Fizz Buzz program
 * Return: Alwayse 0 (Success)
 */

int main(void)

{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
	{
		printf("FizzBuz z");
	}
	else if (i % 3 == 0)
	{
		printf("Fizz ");
	}
	else if (i % 5 == 0)
	{
		printf("Buzz ");
	}
	else
	{
		printf("%d ", i);
	}
	if (i != 100)
	{
		printf(" ");
	}
	}
	printf("\n");
	return (0);
}
