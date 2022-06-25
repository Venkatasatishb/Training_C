/*#include <stdio.h>
#include <string.h>
#define WORD_LENGTH 50
#define COMMAND_LENGTH 150
int main()
{
	int resultFound = 0;
	char wordToBSearched[WORD_LENGTH], command[COMMAND_LENGTH], *pieceOfSourceCode;
	char sourceCodeLine[2000];
	printf("\nEnter The word To Search: ");
	scanf("%s", wordToBSearched);
	fflush(stdin);
	sprintf(command, "curl -k \"https://dsal.uchicago.edu/cgi-bin/app/brown_query.py?qs=%s&matchtype=default\">sourceCode.txt", wordToBSearched);
	system(command);
	FILE *fpSourceCode = fopen("sourceCode.txt", "r");
	while (fgets(sourceCodeLine, 2000, fpSourceCode) != '\0')
	{
		pieceOfSourceCode = strtok(sourceCodeLine, "><");
		while (pieceOfSourceCode != '\0')
		{
			pieceOfSourceCode = strtok('\0', "><");
			if (pieceOfSourceCode != '\0')
			{
				if(strcmp(pieceOfSourceCode, "&nbsp;&nbsp;\n") == 0)
				{
					fgets(sourceCodeLine, 2000, fpSourceCode);
					pieceOfSourceCode = strtok(sourceCodeLine, "><");
					pieceOfSourceCode = strtok('\0', "><");
					pieceOfSourceCode = strtok('\0', "<");
					printf("%s\n", pieceOfSourceCode);
					resultFound = 1;
					break;
				}
			}
		}
		if (resultFound == 1)
		{
			break;
		}
	}
	fclose(fpSourceCode);
}
*/





/*
#include <stdio.h>
#include <string.h>
#include "myTools.c"
#define WORD_LENGTH 50
#define COMMAND_LENGTH 150
int main()
{
	int resultFound = 0;
	char wordToBSearched[WORD_LENGTH], command[COMMAND_LENGTH], *pieceOfSourceCode;
	char sourceCodeLine[2000];
	printf("\nEnter The word To Search: ");
	scanf("%s", wordToBSearched);
	fflush(stdin);
	sprintf(command, "curl -k \"https://www.shabdkosh.com/search-dictionary?lc=te&sl=en&tl=te&e=%s\">sourceCode.txt", wordToBSearched);
	// sprintf(command, "curl \"https://dsal.uchicago.edu/cgi-bin/app/brown_query.py?qs=%s&matchtype=default\">sourceCode.txt", wordToBSearched);
	system(command);
	FILE *fpSourceCode = fopen("sourceCode.txt", "r");
	while (fgets(sourceCodeLine, 2000, fpSourceCode) != '\0')
	{
		pieceOfSourceCode = strtok(sourceCodeLine, "><");
		while (pieceOfSourceCode != '\0')
		{
			pieceOfSourceCode = strtok('\0', "><");
			if (pieceOfSourceCode != '\0')
			{
				if(strcmp(pieceOfSourceCode, "/b") == 0)
				{
				// 	fgets(sourceCodeLine, 2000, fpSourceCode);
				// 	pieceOfSourceCode = strtok(sourceCodeLine, "><");
					pieceOfSourceCode = strtok('\0', ".");
					printf("Meaning of %s: %s%s\n",wordToBSearched, wordToBSearched, pieceOfSourceCode);
					while (pieceOfSourceCode != '\0')
					{
						if(strcmp(pieceOfSourceCode, "b") == 0)
						{
							pieceOfSourceCode = strtok('\0', "<");
							printf("%s in Telugu: %s\n", wordToBSearched, pieceOfSourceCode);
							resultFound = 1;
						}
						pieceOfSourceCode = strtok('\0', "><");
						if (resultFound == 1)
						{
							break;
						}
					}
					break;
				}
			}
		}
		if (resultFound == 1)
		{
			break;
		}
	}
	fclose(fpSourceCode);
}
*/

// Given Word In Hindi

#include <stdio.h>
#include <string.h>
#define WORD_LENGTH 50
#define COMMAND_LENGTH 150
#define LINE_LENGTH 2000
int main()
{
	int resultFound = 0;
	char wordToBeSearched[WORD_LENGTH], command[COMMAND_LENGTH], *pieceOfSourceCode;
	char sourceCodeLine[LINE_LENGTH];
	printf("\nEnter The word To Search: ");
	scanf("%s", wordToBeSearched);
	fflush(stdin);
	sprintf(command, "curl -k \"https://dict.hinkhoj.com/shabdkhoj.php?word=%s&ie=UTF-8\">sourceCode.txt", wordToBeSearched);
	system(command);
	FILE *fpSourceCode = fopen("sourceCode.txt", "r");
	while (fgets(sourceCodeLine, LINE_LENGTH, fpSourceCode) != '\0')
	{
		pieceOfSourceCode = strtok(sourceCodeLine, "</");
		while (pieceOfSourceCode != '\0')
		{
			pieceOfSourceCode = strtok('\0', "</");
			if (pieceOfSourceCode != '\0')
			{
				if(strcmp(pieceOfSourceCode, "a class='hin_dict_span' href='https:") == 0)
				{
					pieceOfSourceCode = strtok('\0', "/");
					pieceOfSourceCode = strtok('\0', "-");
					printf("%s in Hindi: %s\n", wordToBeSearched, pieceOfSourceCode);
					resultFound = 1;
					break;
				}
			}
		}
		if (resultFound == 1)
		{
			break;
		}
	}
	fclose(fpSourceCode);
}