// Show Names

#include <stdio.h>
#define FILE_NAME "namesFile.dat"
int showNames(NAME_LENGTH)
{
	FILE *ptrNames;
	ptrNames = fopen(FILE_NAME, "r");
	char name[NAME_LENGTH];
	printf("\nNames are:\n");
	while(fgets(name, NAME_LENGTH, ptrNames) != '\0')
	{
		printf("%s", name);
	};
	fclose(ptrNames);
}