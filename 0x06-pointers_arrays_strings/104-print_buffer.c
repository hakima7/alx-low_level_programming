#include <stdio.h>
/**
 * print_buffer - Prints the content of a buffer.
 * @b: The buffer to print.
 * @size: The size of the buffer.
 *
 * The function prints the content of size bytes of the buffer pointed by b.
 * It prints 10 bytes per line
 * If size is 0 or less, it prints a new line only.
 */
void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}
	for (i = 0; i < size; i += 10)
	{
		int j;
	printf("%08x: ", i);
	for (j = i; j < i + 10; j += 2)
	{
		if (j < size)
			printf("%02x", b[j]);
		else
			printf("  ");
		if (j + 1 < size)
			printf("%02x ", b[j + 1]);
		else
			printf("   ");
	}
	printf(" ");
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
