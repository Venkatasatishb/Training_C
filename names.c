// Read and print names
#include <stdio.h>
#define COUNT 6
int main()
{
	int readCounter, printCounter;
	char names[COUNT][10];
	printf("Enter the names of your team: \n");
	for (readCounter = 0; readCounter < COUNT; readCounter++)
	{
		scanf("%s", names[readCounter]);
	}
	printf("\n\nThe members in your team: \n");
	for (printCounter = 0; printCounter < COUNT; printCounter++)
	{
		printf("%s\n", names[printCounter]);
	}
}