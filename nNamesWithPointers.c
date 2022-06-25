// Read and print n names using pointers

#include <stdio.h>
#include <stdlib.h>
#include "removeNewLine.c"
#define NAME_LENGTH 25
int main()
{
	int namesCount, namesCounter;
	char **names;
	printf("How many names do you want to enter? ");
	scanf("%d", &namesCount);
	fflush(stdin);
	names = malloc(namesCount * sizeof(char*));
	for (namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		names[namesCounter] = malloc(NAME_LENGTH * sizeof(char));
		printf("Enter name %d of %d: ", namesCounter + 1, namesCount);
		fgets(names[namesCounter], NAME_LENGTH, stdin);
		removeNewLine(names[namesCounter]);
	}
	printf("\n\nEntered names are:\n");
	for (namesCounter = 0; namesCounter < namesCount; namesCounter++)
	{
		printf("Name %d: %s.\n", namesCounter + 1, names[namesCounter]);
	}
}