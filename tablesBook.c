// Tables Book

#include<stdio.h>
int main()
{	
	int tableLimit, tableCounter, rowLimit, multiple;
	printf("How many tables do you want? ");
	scanf("%d", &tableLimit);
	printf("How many rows do you want in each table? ");
	scanf("%d", &rowLimit);
	for(tableCounter = 1; tableCounter <= tableLimit; tableCounter++)
	{
		printf("Table %d\n", tableCounter);
		for(multiple = 1; multiple <= rowLimit; multiple++)
		{
			printf("%2d X %2d = %4d\n", tableCounter, multiple, tableCounter * multiple);
		}
	}
}