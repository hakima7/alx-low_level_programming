#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints the content of a buffer.
 * @b: The buffer to print.
 * @size: The size of the buffer.
 *
 * The function prints the content of size bytes of the buffer pointed by b.
 * It prints 10 bytes per line.
 * If size is 0 or less, it prints a new line only.
 */

void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", i);

		for (j = i; j < i + 10; j++)
		{
			if (j < size)
				printf("%02x", b[j]);
			else
				printf("  ");

			if (j % 2 == 1)
				printf(" ");
		}

		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				if (b[j] >= 32 && b[j] <= 126)
					printf("%c", b[j]);
				else
					printf(".");
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}
}
