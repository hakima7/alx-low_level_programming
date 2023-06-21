#include "main.h"

#include <stdio.h>


/**
 * print_to_98 - Prints all natiral numbers fromn to 98
 * @c: The number to start printing from
 * Return: Alwayse 0
 */
void Print_to_98(int n)
{
	if (n <= 98) 
	{
        for (; n <= 98; n++) 
	{
		printf("%d", n);
		if (n != 98) 
		{
                printf(", ");
		}
	}
	}
	else
	{
        for (; n >= 98; n--)
	       }
		printf("%d", n);
		if (n != 98)
		{
                printf(", ");
		}
	}
	}
	printf("\n");
}
