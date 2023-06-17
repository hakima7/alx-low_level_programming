#include <stdlib.h>

#include <time.h>

#include <stdio.h>

/**
 * main - Entry point
 * Return: Always (Success)
 */

int main(void)

{
	int a, b, c;

	for (a ='0'; a <= '9'; a++)
	{

	for (b = a + 1; b <= '9'; b++)
	{
	
	for (c = b + 1; c <= '9'; c++)
	{
	if ((b != a) != c)
	{
	puchtar(a);
	puchtar(b);
	putchar(c)
	}
        }
        }	
	putchar('\n');
	return (0);
}
