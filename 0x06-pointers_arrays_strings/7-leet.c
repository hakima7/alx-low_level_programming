#include "main.h"

/**
 * leet - encodes a string into 1337 (Leet Speak)
 * @str: The string to encode
 * Return: A pointer to the resulting encoded string
 */
char *leet(char *str)
{
	int i, j;
	char letters[] = "aAeEoOtTlL";
	char leet_chars[] = "4433007711";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = leet_chars[j];
			}
		}
	}
	return (str);
}
