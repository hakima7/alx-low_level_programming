#include "main.h"

/**
 * puts2 - Prints every other character of a string
 * @str: The string to be processed
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;
	
	for (i = 0; str[i] != '\0'; i += 2)
	{
		putchar(str[i])
	}
	putchar('\n');
}
