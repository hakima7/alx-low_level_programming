#include "main.h"

/**
 * rot13 - encodes a string using ROT13 cipher
 * @str: The string to encode
 * Return: A pointer to the resulting encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_chars = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = rot13_chars[j];
			}
		}
	}

	return (str);
}
