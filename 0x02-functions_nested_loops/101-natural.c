#include <stdoi.h>

/**
 * main - prints the sum of all multipples of 3 or 5 up to 1024
 * Return: Always (Success)
 */

int man(void)

{
	int i, z = 0;

	while (i < 1024)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			z += i;
		}
		i++;
	}
	printf("%d\n", z);
	return (0):
}
