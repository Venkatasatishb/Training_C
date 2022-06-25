// Read and print n marks

#include <stdio.h>
int main()
{
	int marksCount, marksCounter, *marksPointer;
	printf("How many subject marks do you want to enter? ");
	scanf("%d", &marksCount);
	int marks[marksCount];
	marksPointer = marks;
	printf("Enter the marks:\n");
	for (marksCounter = 0; marksCounter < marksCount; marksCounter++)
	{
		printf("Marks for subject %d of %d: ", marksCounter + 1, marksCount);
		scanf("%d", marksPointer);
		marksPointer++;
	}
	printf("\n\n");
	for (marksCounter = 0; marksCounter < marksCount; marksCounter++)
	{
		printf("Marks in subject %d = %d\n", marksCounter + 1, marks[marksCounter]);
	}
}