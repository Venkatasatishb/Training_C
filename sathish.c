// Frame Work

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define LINE_LENGTH 1000
#define FIELD_NAME_LENGTH 50
#define FIELD_VALUE_LENGTH 30
#define DATA_FILE "records.dat"
#define FIELD_NAMES_FILE "fieldNames.cfg"
#define MENU_FILE "menu.cfg"
// #define CURRENT_FIELD_NAME_ADDRESS fieldNames + (fieldNamesCounter * FIELD_NAME_LENGTH)
#define CURRENT_FIELD_NAME_ADDRESS fieldNames[fieldNamesCounter]
// char *fieldNames;
int fieldNamesCount, fieldNamesCounter;
int menuLinesCount, menuLinesCounter;
char **fieldNames;
char **menuLines;

int main()
{
	// countAndLoadMenuLines();
	countAndLoadFieldNames();
	countAndLoadLines(MENU_FILE);
	showMenu();
}

// -------------------------
int showMenu()
{
	int choice;
	do
	{
		for ( menuLinesCounter = 0; menuLinesCounter < menuLinesCount; menuLinesCounter++)
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
		/*	case 4:
				closeRecord();
				break;*/
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

// --------------------------------


// Save Record

/*#include <stdio.h>
#include "myTools.c"
#define FIELD_NAME_LENGTH 50
#define FIELD_VALUE_LENGTH 30
#define DATA_FILE "records.dat"
#define FIELD_NAMES_FILE "fieldNames.cfg"*/
/*int saveRecord()
{
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	FILE *fpData = fopen(DATA_FILE, "a");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH];
	while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName) != '\0')
	{
		removeNewLine(fieldName);
		printf("Enter %s: ", fieldName);
		fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
		fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
	}
	fclose(fpFieldName);
	fclose(fpData);
}
*/



int saveRecord()
{
	FILE *fpData = fopen(DATA_FILE, "a");
	char fieldValue[FIELD_VALUE_LENGTH];
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		printf("Enter %s: ", fieldNames[fieldNamesCounter]);
		fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
		// removeNewLine(fieldValue);
		fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
	}
	fclose(fpData);
}


/*int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH];
	int recordsPrinted = 0;
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
	 	if (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName) != '\0')
		{
			removeNewLine(fieldValue);
			removeNewLine(fieldName);
			printf("%s: %s\n", fieldName, fieldValue);
		}
		else
		{
			printf("\n\n");
			rewind(fpFieldName);
			fseek(fpData, -(sizeof(fieldValue) + 1), SEEK_CUR);
		}
		recordsPrinted = 1;
	};
	if (recordsPrinted == 0)
	{
		printf("\nNo Records Found\n");
	}
	fclose(fpFieldName);
	fclose(fpData);
}*/


/*int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH];
	int recordsPrinted = 0;
	fieldNamesCounter = 0;
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		removeNewLine(fieldValue);
		printf("%s: %s\n", CURRENT_FIELD_NAME_ADDRESS, fieldValue);
		fieldNamesCounter++;
		if (fieldNamesCounter == fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 0;
		}
		recordsPrinted = 1;
	}
	if (recordsPrinted == 0)
	{
		printf("\nNo Records Found\n");
	}
	fclose(fpFieldName);
	fclose(fpData);
}*/

int showAllRecords()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH];
	int isFileEmpty = 1, fieldNamesCounter = 0;
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		removeNewLine(fieldValue);
		printf("%s: %s\n", fieldNames[fieldNamesCounter], fieldValue);
		fieldNamesCounter++;
		if (fieldNamesCounter == fieldNamesCount)
		{
			printf("\n");
			fieldNamesCounter = 0;
		}
		isFileEmpty = 0;
	}
	if (isFileEmpty == 1)
	{
		printf("\nNo Records Found\n");
	}
	fclose(fpData);
}

/*int updateRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r+");
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName);
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
			printf("\n");
			// fseek(fpData, -(sizeof(fieldValue) + 1), SEEK_CUR);
			while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName) != '\0')
			{
				removeNewLine(fieldName);
				printf("Enter %s: ", fieldName);
				fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
				removeNewLine(fieldValue);
				fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
			};
			printf("\nupdated\n");
			matchFound = 1;
			break;
		}
	};
	if (matchFound == 0)
	{
		printf("\nRecord Not Found\n");
	}
	fclose(fpFieldName);
	fclose(fpData);
}*/
int updateRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r+");
	char fieldValue[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
			printf("\n");

			fseek(fpData, (sizeof(fieldValue) + 1), SEEK_END);
			fseek(fpData, -(sizeof(fieldValue)), SEEK_CUR);
				printf("Enter %s: ", fieldNames[0]);
				fgets(fieldValue, FIELD_VALUE_LENGTH, stdin);
				fwrite(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
	fclose(fpData);
}
/*int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH], searchTerm[FIELD_VALUE_LENGTH];
	int compareValue;
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	if (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName) != '\0')
	{
		removeNewLine(fieldName);
		printf("Enter %s:", fieldName);
		scanf("%s", searchTerm);
		while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
		{
			removeNewLine(fieldValue);
			compareValue = strcmp(fieldValue, searchTerm);
		 	if (compareValue == 0)
			{
				printf("%s: %s\n", fieldName, fieldValue);
			};
			break;
		}
	};
	fclose(fpFieldName);
	fclose(fpData);
}*/

// Search Record

/*int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	FILE *fpFieldName = fopen(FIELD_NAMES_FILE, "r");
	char fieldName[FIELD_NAME_LENGTH], fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName);
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
			rewind(fpFieldName);
			while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldName) != '\0')
			{
				removeNewLine(fieldName);
				printf("%s: %s\n", fieldName, fieldValue);
				fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData);
				removeNewLine(fieldValue);
			};
			matchFound = 1;
			break;
		}
	};
	if (matchFound == 0)
	{
		printf("\nRecord Not Found\n");
	}
	fclose(fpFieldName);
	fclose(fpData);
}*/



int searchRecord()
{
	FILE *fpData = fopen(DATA_FILE, "r");
	char fieldValue[FIELD_VALUE_LENGTH], fieldValueToBeSearched[FIELD_VALUE_LENGTH];
	int compareValue, matchFound = 0;
	printf("Enter %s: ", fieldNames[0]);
	scanf("%s", fieldValueToBeSearched);
	fflush(stdin);
	while (fread(fieldValue, FIELD_VALUE_LENGTH, 1, fpData) != '\0')
	{
		removeNewLine(fieldValue);
		compareValue = strcmp(fieldValue, fieldValueToBeSearched);
	 	if (compareValue == 0)
		{
			printf("\n\n");
			for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
			{
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


// Count And Load Field Names

/*int countAndLoadFiledNames()
{
	char fieldName[FIELD_NAME_LENGTH];
	fieldNamesCount = 0;
	FILE *fpFieldNames = fopen(FIELD_NAMES_FILE, "r");
	while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldNames) != '\0')
	{
		fieldNamesCount++;
	};
	printf("%d\n", fieldNamesCount);
	fieldNames = malloc(fieldNamesCount * FIELD_NAME_LENGTH);
	rewind(fpFieldNames);
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		fgets(fieldName, FIELD_NAME_LENGTH, fpFieldNames);
		removeNewLine(fieldName);
		strcpy(CURRENT_FIELD_NAME_ADDRESS, fieldName);
	}
}
/*
/
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		printf("%s\n", CURRENT_FIELD_NAME_ADDRESS);
	}
	fclose(fpFieldNames);
}*/






/*int countAndLoadFiledNames()
{
	char fieldName[FIELD_NAME_LENGTH];
	fieldNamesCount = 0;
	FILE *fpFieldNames = fopen(FIELD_NAMES_FILE, "r");
	while (fgets(fieldName, FIELD_NAME_LENGTH, fpFieldNames) != '\0')
	{
		fieldNamesCount++;
	};
	char fieldNames[fieldNamesCount][FIELD_NAME_LENGTH];
	ptrFieldNames = fieldNames;
	rewind(fpFieldNames);
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		fgets(fieldName, FIELD_NAME_LENGTH, fpFieldNames);
		removeNewLine(fieldName);
		strcpy(CURRENT_FIELD_NAME_ADDRESS, fieldName);
	}
	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		printf("%s\n", fieldNames[fieldNamesCounter]);
	}
}*/

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
/*	for (fieldNamesCounter = 0; fieldNamesCounter < fieldNamesCount; fieldNamesCounter++)
	{
		printf("%s\n", fieldNames[fieldNamesCounter]);
	}
}
*/
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
}

/*int countAndLoadLines()
{
	int linesCounter;
	char line[LINE_LENGTH], **lines;
	int linesCount = 0;
	printf("%d\n", linesCount);
	FILE *fplines = fopen(MENU_FILE, "r");
	while (fgets(line, LINE_LENGTH, fplines) != '\0')
	{
		linesCount = linesCount + 1;
	}
	printf("%d\n", linesCount);
	lines = malloc(linesCount * sizeof(char*));
	rewind(fplines);
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(LINE_LENGTH);
		fgets(lines[linesCounter], LINE_LENGTH, fplines);
	}
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		printf("%s", lines[linesCounter]);
	}
	// return **lines;
}*/

int countAndLoadLines(char *file)
{
	int linesCounter;
	char **lines;
	char line[LINE_LENGTH];
	int linesCount = 0;
	printf("%d\n", linesCount);
	FILE *fpLines = fopen(file, "r");
	while (fgets(line, LINE_LENGTH, fpLines) != '\0')
	{
		linesCount = linesCount + 1;
	}
	printf("%d\n", linesCount);
	lines = malloc(linesCount * sizeof(char*));
	rewind(fpLines);
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		lines[linesCounter] = malloc(LINE_LENGTH);
		fgets(lines[linesCounter], LINE_LENGTH, fpLines);
	}
	for (linesCounter = 0; linesCounter < linesCount; linesCounter++)
	{
		printf("%s", lines[linesCounter]);
	}
	fclose(fpLines);
	// return (lines);
}