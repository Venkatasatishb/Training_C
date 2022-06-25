// Program to save multiple names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mytools.c"
#define NAMES "llnam.dat"
#define MAX_LENGTH 30
struct node
{
	char name[MAX_LENGTH];
	struct node *nextNode;
};
struct node *start;

//_________________
// Function to load names into the linked list.

int loadList()
{
	struct node *newNode, *tempNode;
	char names[MAX_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES, "r");
	while (fread(names, sizeof(names), 1, fpNames) != '\0')
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		strcpy(newNode -> name, names);
		newNode -> nextNode = '\0';
		tempNode = start;
		if (tempNode == '\0')
		{
;
			start = newNode;
		}
		else
		{
			while (tempNode -> nextNode != '\0')
			{
				tempNode = tempNode -> nextNode;
			}
			tempNode -> nextNode = newNode;
		}
	}
	fclose(fpNames);
}

//___________________
// Save the names into the file. 

saveNames()
{
	struct node *tempNode;
	char names[MAX_LENGTH];
	FILE *fpNames;
	fpNames = fopen(NAMES, "w");
	tempNode = start;
	while (tempNode != '\0')
	{
		fwrite(tempNode->name, sizeof(names), 1, fpNames);
		tempNode = tempNode -> nextNode;
	}
	fclose(fpNames);
}

//__________________
// Function to show the menu.

int showMenu()
{
	int choice;
	do
	{
		printf("\n1. Load the Name into the list.\n2. Show All Names.\n3. Update a Name.\n4. Sort all Names.\n5. Delete a Name.\n6. Exit.");
		printf("\nEnter the choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				loadName();
				saveNames();
				break;
			case 2:
				showAllNames();
				break;
			case 3:
				updateName();
				saveNames();
				break;
			case 4:
				sortNames();
				break;
			case 5:
				deleteName();
				saveNames();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nEnter the Correct Choice!\n");
				break;
		}
	} while (choice != 6);
}

//____________________-
// Main Function.

int main()
{
	//writeNames();
	loadList();
	showMenu();
}


//____________________
//Function to show all the names.

int showAllNames()
{
	
	struct node *tempNode;
	tempNode = start;
	if (start == '\0')
	{
		printf("\nNo Names Found!\n");
	}
	else
	{
		printf("\nNames are:\n\n");
		while (tempNode != '\0')
		{
			printf("%s", tempNode -> name);
			tempNode = tempNode -> nextNode;
		}
	}
}

//_________________
// Function to load name into Linked List. 

int loadName()
{
	struct node *newNode, *tempNode;
	char nextName[MAX_LENGTH];
	newNode = (struct node*) malloc(sizeof(struct node));
	printf("Enter the name: ");
	fgets(nextName, MAX_LENGTH, stdin);
	strcpy(newNode -> name, nextName);
	newNode -> nextNode = '\0';
	tempNode = start;
	if (tempNode == '\0')
	{
		start = newNode;
	}
	else
	{
		while (tempNode -> nextNode != '\0')
		{
			tempNode = tempNode -> nextNode;
		}
		tempNode -> nextNode = newNode;
	}
}
	
//_________________
// Function to update a name.

int updateName()
{
	struct node *tempNode;
	char nameSearched[MAX_LENGTH];
	int status = 0;
	showAllNames();
	tempNode = start;
	printf("Enter the name do you want to modify: ");
	fgets(nameSearched, MAX_LENGTH, stdin);
	while (tempNode != '\0')
	{
		if (strcmp(tempNode -> name, nameSearched) == '\0')
		{
			printf("Enter the modified name: ");
			fgets(tempNode -> name, MAX_LENGTH, stdin);
			printf("\nName Updated!");
			status = 1;
			break;
		}
		else
		{
			tempNode = tempNode -> nextNode;
		}
	}
	if (status == 0)
	{
		printf("\nNo Name Found!\n");
	}
}

//__________________
// Function to sort all the names. 

int sortNames()
{
	
}

//__________________
// Function to delete a name.

int deleteName()
{
	struct node *tempNode, *previousNode = start;
	char nameToBeDeleted[MAX_LENGTH];
	int status = 0;
	showAllNames();
	tempNode = start;
	printf("Enter the name do you want to delete: ");
	fgets(nameToBeDeleted, MAX_LENGTH, stdin);
	while(tempNode != '\0')
	{
		if (strcmp(tempNode -> name, nameToBeDeleted) == 0)
		{
			if (previousNode == start)
			{
				start = tempNode -> nextNode;
				free(tempNode);
			}
			else
			{
				previousNode -> nextNode = tempNode -> nextNode;
				free(tempNode);
			}
		}
		else
		{
			previousNode = tempNode;
			tempNode = tempNode -> nextNode;
		}
	}
}