#include "main.h"

/**
 * puts2 - Prints every other character of a string
 * @str: The string to be processed
 *
 * Return: void
 */
void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i += 2)
	{
		putchar(str[i]);
	}
	putchar('\n');;
}

int main(void)
{
    char str[] = "Lrmismdlrstae,cnettraiicn lt e oeumdtmo niiutu aoee ooemgaaiu.U nma ii eim usnsrdeectto lac aoi iiu lqi xe omd osqa.Di ueiuedlri erhnei nvlpaevltes ilmdlr ufga ul aitr xetu itocea uiaa o riet uti up u fii eeutmli nmi s aou.";
    puts2(str);

    return 0;
}
}

int main(void)
{
    char str[] = "Lrmismdlrstae,cnettraiicn lt e oeumdtmo niiutu aoee ooemgaaiu.U nma ii eim usnsrdeectto lac aoi iiu lqi xe omd osqa.Di ueiuedlri erhnei nvlpaevltes ilmdlr ufga ul aitr xetu itocea uiaa o riet uti up u fii eeutmli nmi s aou.";
    puts2(str);

    return 0;
}
