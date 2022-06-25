//Save Names

#include <stdio.h>
#include "removeNewLine.c"
#define FILE_NAME "namesFile.dat"
int saveNames(NAME_LENGTH)
{
	int choice;
	do
	{
		char name[NAME_LENGTH];
		FILE *ptrNames;
		ptrNames = fopen(FILE_NAME, "a");
		printf("Enter the name: ");
		fgets(name, NAME_LENGTH, stdin);
		removeNewLine(name);
		fprintf(ptrNames, "%s\n", name);
		fclose(ptrNames);
		printf("Do you want to add another name?\n1. Yes\n2. No\nEnter choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
}