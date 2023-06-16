#include <stdlib.h>

#include <time.h>

#include <stdio.h>



/**
 * main - Entry point
 * Return: Always (Success)
 *
 */

int main(void)

{
	int num;

	for (num = '0'; num <= '9'; num++)
	{
	putchar(num);
	if (num != '9')
	{
	putchar(',');
	putchar('');
	}
	}
}
