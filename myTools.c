#include <stdio.h>
#include <string.h>

// Underline the string
int underline(char *string)
{
	int stringLength, characterCounter;
	stringLength = printf("%s", string);
	printf("\n");
	for (characterCounter = 0; characterCounter < stringLength; characterCounter++)
	{
		printf("-");
	}
}

// Remove new line at the last of the string
int removeNewLine(char *string)
{
	string[strlen(string) - 1] = '\0';
}
/*{	int size;
	size = strlen(string);
	string[size - 1] = '\0';
}*/

// Print characters
int printCharacters(char *string)
{
	while(*string != '\0')
	{
		printf("%c\n", *string++);
	}
}
// Compare two strings

/*compareStrings(char *string1, char *string2)
{
	int characterCounter, compareValue = 0;
	for (characterCounter = 0; string1[characterCounter] != '\0' && string2[characterCounter] != '\0'; characterCounter++)
	{
		if (string1[characterCounter] != string2[characterCounter])
		{
			compareValue = 1;
			break;
		}
	}
	return compareValue;
}
*/