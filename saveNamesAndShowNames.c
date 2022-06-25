/*// Read and Save the Names in file

#include <stdio.h>
#include <stdlib.h>
#include "removeNewLine.c"
#define FILE_NAME "namesFile.dat"
#define NAME_LENGTH 20
int main()
{
	int choice;
	do
	{	
		choice = showMenu();
	} while (choice != 5);
}

int showMenu()
{		
	int choice;
	printf("\n1. Save Names\n2. Show Names\n3. Clear Names\n4. Exit");
	printf("\nEnter you choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveNames();
			break;
		case 2:
			showNames();
			break;
		case 3:
			clearNames();
			break;
		case 4:
			exit(0);
	}
	return choice;
}

int saveNames()
{
	int choice;
	do
	{
		char name[NAME_LENGTH];
		FILE *fpNames;
		fpNames = fopen(FILE_NAME, "a");
		printf("Enter the name: ");
		fgets(name, NAME_LENGTH, stdin);
		removeNewLine(name);
		fprintf(fpNames, "%s\n", name);
		fclose(fpNames);
		printf("Do you want to add another name?\n1. Yes\n2. No\nEnter choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
}

int showNames()
{
	FILE *fpNames;
	fpNames = fopen(FILE_NAME, "r");
	char name[NAME_LENGTH];
	if (fpNames == '\0')
		{
			printf("File not found");
			exit(0);
		}
	else{
	printf("\nNames are:\n");
	while (fgets(name, NAME_LENGTH, fpNames) != '\0')
	{
		printf("%s", name);
	};
	fclose(fpNames);
	}
}

int clearNames()
{
	FILE *fpNames;
	fpNames = fopen(FILE_NAME, "w");
	fclose(fpNames);
	printf("\nAll the Saved Names are cleared\n");
}








// Read and Save the Names in file

#include <stdio.h>
#include <stdlib.h>
#include "removeNewLine.c"
#define FILE_NAME "namesFile.dat"
#define NAME_LENGTH 20
int main()
{
	int choice;
	do
	{	
		choice = showMenu();
	} while (choice != 4);
}

int showMenu()
{		
	int choice;
	printf("\n1. Save Names\n2. Show Names\n3. Clear Names\n4. Exit");
	printf("\nEnter you choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveNames();
			break;
		case 2:
			showNames();
			break;
		case 3:
			clearNames();
			break;
		case 4:
			exit(0);
	}
	return choice;
}

int saveNames()
{
	int choice;
	do
	{
		char name[NAME_LENGTH];
		FILE *fpNames;
		fpNames = fopen(FILE_NAME, "a");
		printf("Enter the name: ");
		fgets(name, NAME_LENGTH, stdin);
		removeNewLine(name);
		fprintf(fpNames, "%s\n", name);
		fclose(fpNames);
		printf("Do you want to add another name?\n1. Yes\n2. No\nEnter choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
}

int showNames()
{
	FILE *fpNames;
	fpNames = fopen(FILE_NAME, "r");
	char name[NAME_LENGTH];
	printf("\nNames are:\n");
	while (fgets(name, NAME_LENGTH, fpNames) != '\0')
	{
		printf("%s", name);
	};
	fclose(fpNames);
}

int clearNames()
{
	FILE *fpNames;
	fpNames = fopen(FILE_NAME, "w");
	fclose(fpNames);
	printf("\nAll the Saved Names are cleared\n");
}*/




// Save and show names

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define FILE_NAME "names.dat"
#define NAME_LENGTH 20
int main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 4);
}
int showMenu()
{
	int choice;
	printf("\n1. Save Name\n2. Show All Names\n3. Clear All Names\n4. Exit\n");
	printf("Enter your choice:");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveName();
			break;
		case 2:
			showAllNames();
			break;
		case 3:
			clearAllNames();
			break;
		case 4:
			exit(0);
		default:
			printf("\nChoose the correct option\n");
	} 
	return choice;
} 


int saveName()
{
	int choice;
	char name[NAME_LENGTH];
	FILE *fpNames = fopen(FILE_NAME, "a");
	do
	{
		printf("Enter a Name:");
		fgets(name, NAME_LENGTH, stdin);
		removeNewLine(name);
		fprintf(fpNames, "%s\n", name);
		printf("Do you want to save another name:\n1.Yes\n2. No\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	fclose(fpNames);
	} while (choice == 1);
}

int showAllNames()
{
	char name[NAME_LENGTH];
	FILE *fpNames = fopen(FILE_NAME, "r");
	if (fgets(name, NAME_LENGTH, fpNames) == '\0')
	{
		printf("\nNo Names Found\n");
	}
	else
	{
		do
		{
			printf("%s", name);
		} while (fgets(name, NAME_LENGTH, fpNames) != '\0');
	}
}

int clearAllNames()
{
	FILE *fpNames = fopen(FILE_NAME, "w");
	fclose(fpNames);
	printf("\nAll The Names Are Cleared\n");
}