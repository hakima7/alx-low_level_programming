#include "main.h"

#include <ctype.h>


/**
 * main - check the code.
 *
 * Return: Always 0.
 */

int _isalpha(int c);

int main(void)
{
    int r;

    r = isalpha('H');
    _putchar(r + '0');
    r = isalpha('o');
    _putchar(r + '0');
    r = isalpha(108);
    _putchar(r + '0');
    r = _isalpha(';');
    _putchar(r + '0');
    _putchar('\n');
    return (0);
}
