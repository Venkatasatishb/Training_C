// user print tables book

#include<stdio.h>
#include "printTableBook.c"
int main()
{	
	int tableLimit, tableCounter, rowLimit, multiple;
	printf("How many tables do you want? ");
	scanf("%d", &tableLimit);
	printf("How many rows do you want in each table? ");
	scanf("%d", &rowLimit);
	printTableBook(tableLimit, rowLimit);
}