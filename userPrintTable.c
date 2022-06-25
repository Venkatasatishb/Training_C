// print multiplication table

#include<stdio.h>
#include "printTable.c"
int main()
{	
	int tableNumber, rowLimit;
	printf("Enter which table you want: ");
	scanf("%d", &tableNumber);
	printf("How many rows do you want? ");
	scanf("%d", &rowLimit);
	printTable(tableNumber, rowLimit);
}