#include "main.h"
/**
 * _isalpha - checks for letters puts 1 if input is a letter and 0 if not
 *
 * @c: an ASCII char
 *
 * Return: 1 for alphabetic character or 0 for anything else
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
