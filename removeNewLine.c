// Remove new line at the last of the string
#include <string.h>
int removeNewLine(char *string)
{
	string[strlen(string) - 1] = '\0';
}
/*{	int size;
	size = strlen(string);
	string[size - 1] = '\0';
}*/