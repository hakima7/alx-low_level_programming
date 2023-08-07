#include "main.h"

/**
 * append_text_to_file - Appends text at the end a file
 * @file name: Apointer to the name of the file
 * @text_contebt: the string to add to the end of file
 *
 * Return: if the function faile or filename is NULL --1
 * if the file does not exist the user lacks write permissions --1
 * Otherwise -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++
	}

	O = open(filename, O_WRONLY | O_APPEND);
	W = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(0);

	return (1);
}
