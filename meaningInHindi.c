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
