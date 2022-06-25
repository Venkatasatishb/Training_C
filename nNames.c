// Read and print n names
#include <stdio.h>
int main()
{
	int count, readCounter, printCounter;
	printf("How many members are there in your team? ");
	scanf("%d", &count);
	char names[count][10];
	printf("Enter the names of your team: \n");
	for (readCounter = 0; readCounter < count; readCounter++)
	{
		printf("%d. ", readCounter + 1 );
		scanf("%s", names[readCounter]);
	}
	printf("\n\nThe members in your team: \n");
	for (printCounter = 0; printCounter < count; printCounter++)
	{
		printf("%d. %s\n", printCounter + 1, names[printCounter]);
	}
}
