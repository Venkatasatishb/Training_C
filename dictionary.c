// Definition Of Given Word

#include <stdio.h>
#include <string.h>
#include "myTools.c"
#define WORD_LENGTH 50
#define COMMAND_LENGTH 150
#define WORD_MEANING_LENGTH 5000

int main()
{
	char wordToBeSearched[WORD_LENGTH], *pieceOfMeaning;
	char commandForPronunciation[COMMAND_LENGTH];
	char command[COMMAND_LENGTH];
	printf("\nEnter the word to be search: ");
	fgets(wordToBeSearched, WORD_LENGTH, stdin);
	removeNewLine(wordToBeSearched);
	sprintf(command, "curl -k https://api.dictionaryapi.dev/api/v2/entries/en/%s>wordDefinition.txt", wordToBeSearched);
	system(command);
	FILE *fpWordDefinition = fopen("wordDefinition.txt", "r");
	char wordMeaning[WORD_MEANING_LENGTH];
	fgets(wordMeaning, WORD_MEANING_LENGTH, fpWordDefinition);
	fclose(fpWordDefinition);
	pieceOfMeaning = strtok(wordMeaning, ":");
	while (pieceOfMeaning != '\0')
	{
		if (strcmp(pieceOfMeaning, "\"https") == 0)
		{
			pieceOfMeaning = strtok('\0', "\"");
			sprintf(commandForPronunciation ,"vlc \"http:%s\"", pieceOfMeaning);
			break;
		}
		pieceOfMeaning = strtok('\0', ",:");
	}
	while (pieceOfMeaning != '\0')
	{
		if (strcmp(pieceOfMeaning, "[{\"definition\"") == 0)
		{
			int Option;
			pieceOfMeaning = strtok('\0', ",");
			printf("Meaning of %s: %s", wordToBeSearched, pieceOfMeaning);
			printf("\nDo You Want to Listen The Pronunciation Of %s \n1. Yes \n2. No\nEnter Your Option: ", wordToBeSearched);
			scanf("%d", &Option);
			fflush(stdin);
			if (Option == 1)
			{
				system(commandForPronunciation);
			}
			break;
		}
		pieceOfMeaning = strtok('\0', ":");
	}
}