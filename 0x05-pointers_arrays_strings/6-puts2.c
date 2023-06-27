#include "main.h"

/**
 * puts2 - Prints every other character of a string
 * @str: The string to be treated
 * Return: void
 */
void puts2(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
    {
    j++;
    }

    for (i = 0; i < j; i += 2)
    {
    putchar(str[i]);
    }
    putchar('\n');
}
