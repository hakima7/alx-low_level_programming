#include "main.h"
#include <stdio.h>

/**
 * rot13 - encodes rot13
 * @str: The string to encode
 * Return: A pointer to the resulting encoded string
 */

char *rot13(char *str)
{
	int i, j;
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_chars = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i] !='\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = rot13_chars[j];
				break;
			}
		}
	}

	return (str);
}
