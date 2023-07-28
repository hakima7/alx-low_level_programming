#include <stdio.h>

void print_message_constructor(void) __attribute__((constructor));
/**
 * first - prints a sentence before the main
 * function is  executed
 */
void print_message_constructor(void)
{
	printf("you're beat! and yet, you must allow,\n");
	printf("i bore my house upon my back!\n");
}
