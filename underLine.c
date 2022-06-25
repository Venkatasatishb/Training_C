// Under line the text

#include <stdio.h>
#include <string.h>
int underLine(char *string)
{
	int characterCounter, StringLength;
	StringLength = strlen(string);
	for(characterCounter = 0; characterCounter < StringLength; characterCounter++)
	{
		printf("-");
	}
}