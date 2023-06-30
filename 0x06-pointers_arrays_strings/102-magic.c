#include <stdio.h>

/*
 * This is the main function.
 * It serves as the entry point of the program.
 */

int main(void);
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;

	/* Add your line of code here */
	a[2] = *(&n + 7) - 4;

	/* ...so that this prints 98\n */
	printf("a[2] = %d\n", a[2]);
	return (0);
}
