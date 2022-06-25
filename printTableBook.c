//print tables book

#include<stdio.h>
#include "printTable.c"
int printTableBook(int tableLimit, int rowLimit)
{
	int tableCounter;
	for(tableCounter = 1; tableCounter <= tableLimit; tableCounter++)
	{
		printf("Table %d\n", tableCounter);
		printTable(tableCounter, rowLimit);

	}
}