#include <stdio.h>
#include "main.h"

/**
 * print_rev - Prints a string in reverse.
 * @s: The string to print.
 *
 * Return: void.
 */
void print_rev(char *s)
{
	int length = 0;
	int c = 0;

	while (s[length] != '\0')
	{
		length++;
	}
	
	for (c -= 1; c >= 0; c--)
	{
	    putchar(s[c]);
	}

	putchar('\n');
}
