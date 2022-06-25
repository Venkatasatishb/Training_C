// CRUDS Framework

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define DATA_FILE "framework.dat"
#define FIELD_NAMES_FILE "fieldNames.cfg"
#define MENU_FILE "menu.cfg"
#define LINE_LENGTH 100
#define FIELD_VALUE_LENGTH 30
char **fieldNames;
int fieldNamesCount, fieldNamesCounter;

char **countAndLoadLines(char *fileName)
{
	char line[LINE_LENGTH], **lines;
	int linesCounter, linesCount = 0;
	FILE *fpLines = fopen(fileName, "r");
	while (fgets(line, LINE_LENGTH, fpLines) != '\0')
	{
		linesCount++;
	}
	lines = malloc((linesCount + 1) * sizeof(char*)); // We need one extra element to store the linesCount
	lines[0] = malloc(LINE_LENGTH);
	sprintf(lines[0], "%d", linesCount);
	rewind(fpLines);
	for (linesCounter = 1; linesCounter <= linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(LINE_LENGTH);
		fgets(lines[linesCounter], LINE_LENGTH, fpLines);
	}
	fclose(fpLines);
	return lines;
}

// ------------------------------------------
int main()
{
	fieldNames = countAndLoadLines(FIELD_NAMES_FILE);
	fieldNamesCount = atoi(fieldNames[0]);
	for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
	{
		removeNewLine(fieldNames[fieldNamesCounter]);
	}
	showMenu();
}

// -----------------------------
int showMenu()
{
	int choice, menuLinesCounter, menuLinesCount;
	char **menuLines;
	menuLines = countAndLoadLines(MENU_FILE);
	menuLinesCount = atoi(menuLines[0]);
	do
	{
		for (menuLinesCounter = 1; menuLinesCounter <= menuLinesCount; menuLinesCounter++)
		{
			printf("%s", menuLines[menuLinesCounter]);
		}
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				saveRecord();
				break;
			case 2:
				showAllRecords();
				break;
			case 3:
				searchRecord();
				break;
			case 4:
				exit(0);
			default:
				printf("\nChoose A Correct Option.\n");
		}
	} while (choice != 4);
}

// ----------------------------------
int saveRecord()
{
	FILE *fpData = fopen(DATA_FILE, "a");
	char fieldValue[FIELD_VALUE_LENGTH];
	int option;
	do
	{
		for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
		{
			printf("Enter %s: ", fieldNames[fieldNamesCounter]);
			fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
			removeNewLine(fieldValue);
			fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
		}
		printf("\nDo You Want Add One More Record? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpData);
}

// -----------------------------------------
/*int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	fieldNamesCounter = 1;
	int isFileEmpty = 1;
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
		fieldNamesCounter++;
		if (fieldNamesCounter > fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 1;
		}
		isFileEmpty = 0;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpData);
}*/

// -----------------------------------------------
/*int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	int isFileEmpty = 1;
	for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
	{
		if (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
		{
			printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
			if (fieldNamesCounter == fieldNamesCount)
			{
				printf("\n");
				fieldNamesCounter = 0;
			}
			isFileEmpty = 0;
		}
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpData);
}*/

// -----------------------------------------------

int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	int isFileEmpty = 1;
	fieldNamesCounter = 1;
	while (fieldNamesCounter <= fieldNamesCount)
	{
		if (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
		{
			printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
			if (fieldNamesCounter == fieldNamesCount)
			{
				printf("\n");
				fieldNamesCounter = 0;
			}
			isFileEmpty = 0;
		}
		fieldNamesCounter++;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpData);
}
// -----------------------------------------------
int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	printf("Enter %s: ", fieldNames[1]);
	scanf("%s", fieldValueToBeSearched);
	fflush(stdin);
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		compareValue = strcmp(fieldValueToBeSearched, fieldValue);
		if (compareValue == 0)
		{
			printf("\n");
			for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
			{
				printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
				fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
			}
			matchFound =1;
			break;
		}
	}
	if (matchFound == 0)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpData);
}

/*int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	int isFileEmpty = 1;
	for (fieldNamesCounter = 1; fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0'; fieldNamesCounter++)
	{
		printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
		if (fieldNamesCounter == fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 0;
		}
		isFileEmpty = 0;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpData);
}
*/















































/*// CRUDS Frame work

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define DATA_FILE "dataa.dat"
#define FIELD_NAMES_FILE "fieldNames.cfg"
#define MENU_FILE "menu.cfg"
#define LINE_LENGTH 100
#define FIELD_VALUE_LENGTH 30
char **fieldNames;
int fieldNamesCount, fieldNamesCounter;


char **countAndLoadLines(char *fileName)
{
	char line[LINE_LENGTH], **lines;
	int linesCounter, linesCount = 0;
	FILE *fpLines = fopen(fileName, "r");
	while (fgets(line, LINE_LENGTH,fpLines) != '\0')
	{
		linesCount++;
	}
	lines = malloc((linesCount + 1) * sizeof(char*));
	lines[0] = malloc(LINE_LENGTH);
	sprintf(lines[0], "%d", linesCount);
	rewind(fpLines);
	for (linesCounter = 1; linesCounter <= linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(LINE_LENGTH);
		fgets(lines[linesCounter], LINE_LENGTH, fpLines);
		removeNewLine(lines[linesCounter]);
	}
	fclose(fpLines);
	return lines;
}

int main()
{
	fieldNames = countAndLoadLines(FIELD_NAMES_FILE);
	fieldNamesCount = atoi(fieldNames[0]);
	// for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
	// {
	// 	removeNewLine(fieldNames[fieldNamesCounter]);
	// }
	showMenu();
}

// -----------------------------
int showMenu()
{
	int choice, menuLinesCounter, menuLinesCount;
	char **menuLines;
	menuLines = countAndLoadLines(MENU_FILE);
	menuLinesCount = atoi(menuLines[0]);
	do
	{
		for (menuLinesCounter = 1; menuLinesCounter <= menuLinesCount; menuLinesCounter++)
		{
			printf("%s\n\b\b", menuLines[menuLinesCounter]);
		}
		// printf("Hello\b\b\b");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				saveRecord();
				break;
			case 2:
				showAllRecords();
				break;
			// case 3:
			// 	updateRecord();
			// 	break;
			// case 4:
			// 	closeRecord();
			// 	break;
			case 5:
				searchRecord();
				break;
			case 6:
				exit(0);
			default:
				printf("\nChoose An Correct Option\n");
		}
	} while (choice != 6);
}

// ----------------------------------
int saveRecord()
{
	FILE *fpData = fopen(DATA_FILE, "a");
	char fieldValue[FIELD_VALUE_LENGTH];
	int option;
	do
	{
		for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
		{
			printf("Enter %s: ", fieldNames[fieldNamesCounter]);
			fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
			removeNewLine(fieldValue);
			fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
		}
		printf("\nDo You Want Add One More Record? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpData);
}

// -----------------------------------------
int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	fieldNamesCounter = 1;
	int isFileEmpty = 1;
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
		fieldNamesCounter++;
		if (fieldNamesCounter > fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 1;
		}
		isFileEmpty = 0;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpData);
}

// -----------------------------------------------
int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	printf("Enter %s: ", fieldNames[1]);
	scanf("%s", fieldValueToBeSearched);
	fflush(stdin);
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		compareValue = strcmp(fieldValueToBeSearched, fieldValue);
		if (compareValue == 0)
		{
			printf("\n");
			for (fieldNamesCounter = 1; fieldNamesCounter <= fieldNamesCount; fieldNamesCounter++)
			{
				printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
				fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
			}
			matchFound =1;
			break;
		}
	}
	if (matchFound == 0)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpData);
}

*/































/*// Frame Work

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define LINE_LENGTH 1000
#define FIELD_NAME_LENGTH 50
#define FIELD_VALUE_LENGTH 30
#define DATA_FILE "data.dat"
#define FIELD_NAMES_FILE "fieldNames.cfg"
#define MENU_FILE "menu.cfg"
int fieldNamesCount, fieldNamesCounter;
int menuLinesCount, menuLinesCounter;
char **fieldNames, **menuLines;

char **countAndLoadLines(char *fileName)
{
	int linesCounter, linesCount = 0;
	char **lines, line[LINE_LENGTH];
	FILE *fpLines = fopen(fileName, "r");
	while (fgets(line, LINE_LENGTH, fpLines) != '\0')
	{
		linesCount++;
	}
	linesCount++;
	lines = malloc(linesCount * sizeof(char*));
	lines[0] = malloc(LINE_LENGTH);
	sprintf(lines[0], "%d", linesCount);
	rewind(fpLines);
	for (linesCounter = 1; linesCounter < linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(LINE_LENGTH);
		fgets(lines[linesCounter], LINE_LENGTH, fpLines);
	}
	fclose(fpLines);
	return (lines);
}

// ------------------------------------
int main()
{
	// countAndLoadMenuLines();
	// countAndLoadFieldNames();
	menuLines = countAndLoadLines(MENU_FILE);
	menuLinesCount = atoi(menuLines[0]);
	fieldNames = countAndLoadLines(FIELD_NAMES_FILE);
	fieldNamesCount = atoi(fieldNames[0]);
	showMenu();
}

// -------------------------
int showMenu()
{

	int choice;
	do
	{
		for ( menuLinesCounter = 1; menuLinesCounter < menuLinesCount; menuLinesCounter++)
		{
			printf("%s", menuLines[menuLinesCounter]);
		}
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				saveRecord();
				break;
			case 2:
				showAllRecords();
				break;
			case 3:
				updateRecord();
				break;
			case 4:
				closeRecord();
				break;
			case 5:
				searchRecord();
				break;
			case 6:
			// fclose(fpFieldName);
			// fclose(fpMenu);
			exit(0);
	 	}
	} while (choice != 6); 	
 }

// ---------------------------------
int saveRecord()
{
	FILE *fpData = fopen(DATA_FILE, "a");
	char fieldValue[FIELD_VALUE_LENGTH];
	printf("%d\n", fieldNamesCount);
	for (fieldNamesCounter = 1; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		removeNewLine(fieldNames[fieldNamesCounter]);
		printf("Enter %s: ", fieldNames[fieldNamesCounter]);
		fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
		// removeNewLine(fieldValue);
		fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
	}
	fclose(fpData);
}

// -----------------------------------------------
int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	int isFileEmpty = 1, fieldNamesCounter = 1;
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		removeNewLine(fieldNames[fieldNamesCounter]);
		removeNewLine(fieldValue);
		printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
		fieldNamesCounter++;
		if (fieldNamesCounter == fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 1;
		}
		isFileEmpty = 0;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found\n");
	}
	fclose(fpData);
}

// -------------------------------------------
int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH];
	char fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	strcpy(fieldName, fieldNames[1]);
	removeNewLine(fieldName);
	printf("Enter %s: ", fieldName);
	scanf("%s", fieldValueToBeSearched);
	fflush(stdin);
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		removeNewLine(fieldValue);
		compareValue = strcmp(fieldValue, fieldValueToBeSearched);
	 	if (compareValue == 0)
		{
			printf("\n\n");
			for (fieldNamesCounter = 1; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
			{
				removeNewLine(fieldNames[fieldNamesCounter]);
				printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
				fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
				removeNewLine(fieldValue);
			}
			matchFound = 1;
			break;
		}
	}
	if (matchFound == 0)
	{
		printf("\nRecord Not Found\n");
	}
	fclose(fpData);
}

// -----------------------------------------
int countAndLoadFieldNames()
{
	char fieldName[FIELD_NAME_LENGTH];
	fieldNamesCount = 0;
	FILE *fpFieldNames = fopen(FIELD_NAMES_FILE, "r");
	while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldNames) != '\0')
	{
		fieldNamesCount++;
	}
	fieldNames = malloc(fieldNamesCount * sizeof(char*));
	rewind(fpFieldNames);
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		fieldNames[fieldNamesCounter] = malloc(FIELD_NAME_LENGTH);
		fgets(fieldNames[fieldNamesCounter], FIELD_NAME_LENGTH, fpFieldNames);
		removeNewLine(fieldNames[fieldNamesCounter]);
	}
	fclose(fpFieldNames);
}

// -------------------------------------------
int countAndLoadMenuLines()
{
	char menuLine[LINE_LENGTH];
	menuLinesCount = 0;
	FILE *fpMenuLines = fopen(MENU_FILE, "r");
	while (fgets(menuLine, LINE_LENGTH, fpMenuLines) != '\0')
	{
		menuLinesCount++;
	}
	menuLines = malloc(menuLinesCount * sizeof(char*));
	rewind(fpMenuLines);
	for (menuLinesCounter = 0; menuLinesCounter < menuLinesCount; menuLinesCounter++)
	{
		menuLines[menuLinesCounter] = malloc(LINE_LENGTH);
		fgets(menuLines[menuLinesCounter], LINE_LENGTH, fpMenuLines);
	}
	fclose(fpMenuLines);
}*/