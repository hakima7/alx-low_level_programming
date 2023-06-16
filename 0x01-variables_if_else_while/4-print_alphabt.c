#include <stdlib.h>

#include <time.h>

#include <stdio.h>

/**
 * main - Entry point
 * Return: Always (Success)
 */


int main(void)

{
	char low;

	for (low = 'a'; low <= 'z'; low++)
	{
	if (low != 'q' && low != 'e')
	{
	putchar(low);
	}
	}

	putchar('\n');

	return (0);
}
