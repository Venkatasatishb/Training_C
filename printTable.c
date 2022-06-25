// Multiplication of Table

#include<stdio.h>
int printTable(int tableNumber, int rowLimit)
{	
	int multiple;
	for(multiple = 1; multiple <= rowLimit; multiple++)
	{
		printf("%2d X %2d = %4d\n", tableNumber, multiple, tableNumber * multiple);
	}
}