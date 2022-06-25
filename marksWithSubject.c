// Read and print marks with subjects
#include <stdio.h>
#define COUNT 7

int main()
{
	int readCounter, printCounter, marks[COUNT];
	char subject[COUNT][13] = {"Telugu", "English", "Hindi", "Mathematics", "Science", "Social", "Computer"};
	printf("Enter the marks of Bhanu for the following subjects: \n");
	for (readCounter = 0; readCounter < COUNT; readCounter++)
	{
		printf("%s: ", subject[readCounter]);
		scanf("%d", &marks[readCounter]);
	}
	printf("\n\nThe marks of Bhanu: \n");
	for (printCounter = 0; printCounter < COUNT; printCounter++)
	{
		printf("%s = %d \n", subject[printCounter], marks[printCounter]);
	}
}