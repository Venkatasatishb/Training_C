// Read and print marks
#include <stdio.h>
#define COUNT 7
int main()
{
	int readCounter, printCounter, marks[COUNT]; 
	printf("Enter the marks of Bhanu: \n");
	for (readCounter = 0; readCounter < COUNT; readCounter++)
	{
		scanf("%d", &marks[readCounter]);
	}
	printf("\n\nThe marks of Bhanu: \n");
	for (printCounter = 0; printCounter < COUNT ; printCounter++)
	{
		printf("%d\n", marks[printCounter]);
	}
}