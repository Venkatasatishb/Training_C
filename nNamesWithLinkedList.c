// nNames using linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define NAMES_FILE "nNames.dat"
#define NAME_LENGTH 50
typedef struct name
 {
 	char name[NAME_LENGTH];
 	struct name *next;
 }name;

name *start;

int main()
{
	start = '\0';
	showMenu();
}

// --------------------------------------------------
int showMenu()
{
	int choice;
	loadNamesInToList();
	do
	{
		printf("\n1. Add New Name\n2. Show All Names\n3. Update Name\n4. Delete Name\n5. Sort Names\n6. Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				addNewName();
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
				deleteName();
				// saveNames();
				break;
			case 5:
				sortNames();
				saveNames();
				break;
			case 6:
				exit(0);
			default:
				printf("\nChoose The Correct Option.\n");
		}
	} while (choice != 6);
}

// -----------------------------------------------
int loadNamesInToList()
{
	name *ptrName = start;
	char name[NAME_LENGTH];
	FILE *fpNames = fopen(NAMES_FILE, "r");
	while (fread(name, NAME_LENGTH, 1, fpNames) != '\0')
	{
		if (ptrName == '\0')
		{
			ptrName = malloc(sizeof(name));
			strcpy(ptrName->name, name);
			ptrName->next = '\0';
			start = ptrName;
		}
		else
		{
			while (ptrName->next != '\0')
			{
				ptrName = ptrName->next;
			}
			ptrName->next = malloc(sizeof(name));
			strcpy(ptrName->next->name, name);
			ptrName->next->next = '\0';

		}
	}
}
// --------------------------------------------------
int addNewName()
{
	int option;
	char tempName[NAME_LENGTH];
	name *ptrName = start;
	do
	{
		printf("\nEnter Name: ");
		fgets(tempName, NAME_LENGTH, stdin);
		removeNewLine(tempName);
		if (ptrName == '\0')
		{
			ptrName = malloc(sizeof(name));
			strcpy(ptrName->name, tempName);
			ptrName->next = '\0';
			start = ptrName;
		}
		else
		{
			while(ptrName->next != '\0')
			{
				ptrName = ptrName->next;
			}
			ptrName->next = malloc(sizeof(name));
			strcpy(ptrName->next->name, tempName);
			ptrName->next->next = '\0';
		}
		printf("\nDo You Want To Add Another Name? \n1. Yes\n2. No");
		printf("\nEnyer Your choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
}

// ------------------------------------------------------
int showAllNames()
{
	name *ptrName = start;
	int isListEmpty = 0;
	while(ptrName != '\0')
	{
		printf("%s\n", ptrName->name);
		ptrName = ptrName->next;
		isListEmpty = 1;
	}
}

// ------------------------------------------------------
int saveNames()
{
	FILE *fpNames = fopen(NAMES_FILE, "w");
	name *ptrName = start;
	while (ptrName != '\0')
	{
		fwrite(ptrName->name, NAME_LENGTH, 1, fpNames);
		ptrName = ptrName->next;
	}
	fclose(fpNames);
}

// -------------------------------------------------------
int updateName()
{
	name *ptrName;
	char nameToBeUpdated[NAME_LENGTH], newName[NAME_LENGTH];
	int nameUpdated = 0;
	printf("\nEnter The Name To Update: ");
	fgets(nameToBeUpdated, NAME_LENGTH, stdin);
	removeNewLine(nameToBeUpdated);
	ptrName = start;
	while(ptrName != '\0')
	{
		if (strcmp(ptrName->name, nameToBeUpdated) == 0)
		{
			printf("\nEnter New Name: ");
			fgets(newName, NAME_LENGTH, stdin);
			removeNewLine(newName);
			strcpy(ptrName->name, newName);
			printf("\nName Updated\n");
			nameUpdated = 1;
			break;
		}
		ptrName = ptrName->next;
	}
	if (nameUpdated == 0)
	{
		printf("\nName Not Found.\n");
	}
}

// ---------------------------------------------
/*int deleteName()
{
	name *ptrCurrentName, *ptrPrevName;
	char nameToBeDeleted[NAME_LENGTH];
	int nameDeleted = 0;
	printf("\nEnter Name To Delete: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	ptrCurrentName = start;
	ptrPrevName = '\0';
	while (ptrCurrentName != '\0')
	{
		if(strcmp(ptrCurrentName->name, nameToBeDeleted) == 0)
		{
			if (ptrPrevName == '\0')
			{
				start = ptrCurrentName->next;
				free(ptrCurrentName);
			}
			else
			{
				ptrPrevName->next = ptrCurrentName->next;
				free(ptrCurrentName);
			}
			nameDeleted = 1;
			break;
		}
		ptrPrevName = ptrCurrentName;
		ptrCurrentName = ptrCurrentName->next;
	}
	if (nameDeleted == 0)
	{
		printf("\nName Not Found.\n");
	}
	else
	{
		printf("\nName Deleted.\n");
	}
}*/
// -------------------------------------------------
/*int deleteName()
{
	name *indirect;
	indirect = malloc(sizeof(name));
	indirect->next = start;
	char nameToBeDeleted[NAME_LENGTH];
	printf("\nEnter Name To Delete: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	while (strcmp(indirect->next, nameToBeDeleted) != 0)
	{
		indirect = (indirect->next);
	}

	indirect->next = indirect->next->next;
}*/

/*int deleteName()
{
	name *indirect;
	indirect = &start;
	char nameToBeDeleted[NAME_LENGTH];
	printf("\nEnter Name To Delete: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	printf("%s\n", *indirect);
	// while (strcmp(*indirect, nameToBeDeleted) != 0)
	{
		// printf("%s\n", *indirect->name);
		indirect = &(indirect->next);
		printf("%s\n", (*indirect));
	}
	// *indirect = (*indirect)->next->next;
		// printf("%s\n", *indirect);
}*/
// --------------------------------------------------
/*int deleteName()
{
	name *ptrName1, *ptrName = start;
	char nameToBeSearched[NAME_LENGTH];
	printf("Enter The Name: ");
	fgets(nameToBeSearched, NAME_LENGTH, stdin);
	removeNewLine(nameToBeSearched);
	while (strcmp(ptrName->name, nameToBeSearched) != 0)
	{
		ptrName = ptrName->next;
	}
	printf("%s\n", ptrName->name);
	printf("%u\n", &(ptrName->next));
	ptrName1 = &start;
	// ptrName1 = &((*ptrName1)->next);
	// printf("%s\n", (ptrName->next));
		printf("%s\n", ptrName1->name);
		// ptrName1 = (ptrName1->next);
		// printf("%u\n", ptrName1);
		// printf("%s\n", ptrName1);
		// printf("%s\n", (ptrName1->next));

	// ptrName1 = &(ptrName1->next);
		// printf("%s\n", ptrName1);
		// printf("%u\n", &ptrName);
	// while (ptrName1 == ptrName)
	{
		// ptrName1 = *ptrName1
		// printf("%s\n", *ptrName1->next);
		// break;
	}
	// ptrName1 = ptrName1->next;

}*/


int deleteName()
{
	name *ptrName1, *ptrName = start;
	char nameToBeDeleted[NAME_LENGTH];
	printf("Enter The Name: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	while (strcmp(ptrName->name, nameToBeDeleted) != 0)
	{
		ptrName = ptrName->next;
	}
	removeName(ptrName);
	// printf("%s\n", ptrName->name);
}
removeName(name *entry)
{
    name **indirect = &start;
    while (*indirect != entry)
	{
	    indirect = &(*indirect)->next;
	}    
    *indirect = entry->next;
}
// --------------------------------------------------
 int sortNames()
 {
 	name *ptrName1, *ptrName2;
 	char tempName[NAME_LENGTH];
 	ptrName1 = start;
 	while (ptrName1 != '\0')
 	{
 		ptrName2 = ptrName1->next;
 		while (ptrName2 != '\0')
 		{
 			if (strcmp(ptrName1->name, ptrName2->name) > 0)
	 		{
	 			strcpy(tempName, ptrName1->name);
	 			strcpy(ptrName1->name, ptrName2->name);
	 			strcpy(ptrName2->name, tempName);
	 		}
	 		ptrName2 = ptrName2->next;
	 	}
 		ptrName1 = ptrName1->next;
 	}
 }


















































































/*
// nNames with linked list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define NAME_LENGTH 50
#define NAMES_FILE "nNames.dat"
typedef struct name
{
	char name[NAME_LENGTH];
	struct name *next;
}name;

name *start;

int main()
{
	start = '\0';
	showMenu();
}

// -------------------------
int showMenu()
{
	int choice;
	loadNamesInToLinkedList();
	do
	{
		printf("\n1. Add New Name\n2. Display All Names\n3. Sort Names\n4. Delete Name\n5. Update Name\n6. Save Names\n7. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				addNewName();
				break;
			case 2:
				displayAllNames();
				break;
			case 3:
				sortNames();
				break;
			case 4:
				deleteName();
				break;
			case 5:
				updateName();
				break;
			case 6:
				saveNames();
				break;
			case 7:
				exit(0);
			default:
				printf("\nChoose The Correct Option.\n");
		}
	} while (choice != 7);
}
// -----------------------------------------
int loadNamesInToLinkedList()
{
	name *ptrName = start;
	char tempName[NAME_LENGTH];
	FILE *fpNames = fopen(NAMES_FILE, "r");
	while (fread(tempName, NAME_LENGTH, 1, fpNames) != '\0')
	{
		if (ptrName == '\0')
		{
			ptrName = malloc(sizeof(name));
			strcpy(ptrName->name, tempName);
			ptrName->next = '\0';
			start = ptrName;
		}
		else
		{
			while (ptrName->next != '\0')
			{
				ptrName = ptrName->next;
			}
			ptrName->next = malloc(sizeof(name));
			strcpy(ptrName->next->name, tempName);
			ptrName->next->next = '\0';
		}

	}
}

// ----------------------------------------------
int addNewName()
{
	int option;
	name *ptrName;
	do
	{
		ptrName = start;
		char tempName[NAME_LENGTH];
		printf("\nEnter Name: ");
		fgets(tempName, NAME_LENGTH, stdin);
		removeNewLine(tempName);
		if (ptrName == '\0')
		{
			ptrName = malloc(sizeof(name));
			strcpy(ptrName->name, tempName);
			ptrName->next = '\0';
			start = ptrName;
		}
		else
		{
			while (ptrName->next != '\0')
			{
				ptrName = ptrName->next;
			}
			ptrName->next = malloc(sizeof(name));
			strcpy(ptrName->next->name, tempName);
			ptrName->next->next = '\0';
		}
		printf("\nDo You Want To Add Another Name? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	}while (option == 1);
	saveNames();
}

// ----------------------------------------------
int displayAllNames()
{
	int isListEmpty = 1;
	name *ptrName = start;
	while (ptrName != '\0')
	{
		printf("%s\n", ptrName->name);
		ptrName = ptrName->next;
		isListEmpty = 0;
	}
	if (isListEmpty == 1)
	{
		printf("\nNo Names Found.\n");
	}
}


//-----------------------------------------
int sortNames()
{
	name *ptrName1, *ptrName2;
	ptrName1 = start;
	char tempName[NAME_LENGTH];
	while(ptrName1->next != '\0')
	{
		ptrName2 = ptrName1->next;
		while (ptrName2 != '\0')
		{
			if (strcmp(ptrName1->name, ptrName2->name) > 0)
			{
				strcpy(tempName, ptrName1->name);
				strcpy(ptrName1->name, ptrName2->name);
				strcpy(ptrName2->name, tempName);
			}
			ptrName2 = ptrName2->next;
		}
		ptrName1 = ptrName1->next;
	}
}


// --------------------------------------------------------
int updateName()
{
	char nameToBeUpdated[NAME_LENGTH], newName[NAME_LENGTH];
	int compareValue, nameUpdated = 0;
	printf("\nEnter The Name To Update: ");
	fgets(nameToBeUpdated, NAME_LENGTH, stdin);
	removeNewLine(nameToBeUpdated);
	name *ptrName = start;
	while (ptrName != '\0')
	{
		compareValue = strcmp(ptrName->name, nameToBeUpdated);
		if (compareValue == 0)
		{
			printf("\nEnter New Name: ");
			fgets(newName, NAME_LENGTH, stdin);
			removeNewLine(newName);
			strcpy(ptrName->name, newName);
			printf("\nName Updated.\n");
			nameUpdated = 1;
			break;
		}
		ptrName = ptrName->next;
	}
	if (nameUpdated == 0)
	{
		printf("\nName Does Not Exist.\n");
	}
	else
	{
		saveNames();
	}
}

// ---------------------------------------
// int deleteName()
// {
// 	char nameToBeDeleted[NAME_LENGTH];
// 	int compareValue, nameDeleted = 0;
// 	printf("\nEnter The Name To Delete: ");
// 	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
// 	removeNewLine(nameToBeDeleted);
// 	name *ptrName = start;
// 	compareValue = strcmp(ptrName->name, nameToBeDeleted);
// 	if (compareValue == 0)
// 	{
// 		start = ptrName->next;
// 		printf("\nName Deleted.\n");
// 		nameDeleted = 1;
// 	}
// 	else
// 	{
// 		while (ptrName->next != '\0')
// 		{
// 			compareValue = strcmp(ptrName->next->name, nameToBeDeleted);
// 			if (compareValue == 0)
// 			{
// 				ptrName->next = ptrName->next->next;
// 				printf("\nName Deleted.\n");
// 				nameDeleted = 1;
// 				break;
// 			}
// 			ptrName = ptrName->next;
// 		}
// 	}
// 	if (nameDeleted == 0)
// 	{
// 		printf("\nName Does Not Exist.\n");
// 	}
// 	else
// 	{
// 		saveNames();
// 	}
// }

// --------------------------------------------------

int saveNames()
{
	name *ptrName = start;
	FILE *fpNames = fopen(NAMES_FILE, "w");
	while (ptrName != '\0')
	{
		fwrite(ptrName->name, NAME_LENGTH, 1, fpNames);
		ptrName = ptrName->next;
	}
	fclose(fpNames);
}



// -----------------------------------------
int deleteName()
{
	char nameToBeDeleted[NAME_LENGTH];
	printf("Enter The To Delete: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	name *prevName = start, *tempName =start;
	while (strcmp(tempName->name, nameToBeDeleted) != 0)
	{
		prevName = tempName;
		tempName = tempName->next;
	}
	if (prevName == '\0')
	{
		start = tempName->next;
	}
	else
	{
		prevName->next = tempName->next;
	}
}*/