
#include <stdio.h>
int printCharacters(char *string)
{
	while(*string != '\0')
	{
		printf("%c\n", *string++);
	}
}
