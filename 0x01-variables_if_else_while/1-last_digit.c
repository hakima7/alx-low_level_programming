#include <stdlib.h>

#include <time.h>

#include <stdio.h>



/**
 * main - prints if number  is greater than 5, zero or is less than 6 and not 0
 * Return: Always (Success)
 *
 */

int main(void)

{
	int n,lastd;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastd = n% 10;

	if (abs(lastd > 5)
	{
	printf("last digit of %d id %d and is greater than 5\n", n, lastd);
	}
	else if (lastd == 0)
	{
	printf("last digit of %d is %d and is zero\n", n, lastd);
	}
	else if (lastd < 6 && lastd !=0)
	{
	printf("last digit of %d is %d and is less than 6 and not 0\n", n, lastd);
	}


	return (0);

}
