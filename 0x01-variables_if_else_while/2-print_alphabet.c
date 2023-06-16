#include <stdio.h>

/**
 * main - printf the alphabetic
 * Return: Always (Success)
 */

int main(void)

{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{

	putchar(letter);
	}
	putchar('\n');

	return (0);
}
