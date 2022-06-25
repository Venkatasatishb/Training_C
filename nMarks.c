// Read and print n marks

#include <stdio.h>
int main()
{
	int count, readCounter, printCounter;
	printf("How many number of subject marks do you want to enter: ");
	scanf("%d", &count);
	int marks[count];
	printf("Enter the marks:\n");
	for (readCounter = 0; readCounter < count; readCounter++)
	{
		printf("Marks for subject %d: ", readCounter + 1);
		scanf("%d", &marks[readCounter]);
	}
	printf("\n\n");
	for (printCounter = 0; printCounter < count; printCounter++)
	{
		printf("Marks in subject %d = %d\n", printCounter + 1, marks[printCounter]);
	}
}