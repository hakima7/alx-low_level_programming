#include <unistd.h>


/**
 * _putchar - writes the characted c to stdout 
 * @c: The characted to print
 * Return: On Success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)

{

	return (write(1, &c, 1));

}
