#include <unistd.h>

/**
* main - Entry point
*
* Return: Always 1 (success)
*/
int main(void)
{
	ssize_t len;
	char *message="and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	len=write(2, message, 59);
	(void)len;/* To silence unused variable warning */
	return (1);
}
