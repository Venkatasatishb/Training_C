// Multiplication of Table

#include<stdio.h>
void main()
{	int tableNumber, rowLimit, multiple;
	printf("Enter which table you want: ");
	scanf("%d", &tableNumber);
	printf("How many rows do you want? ");
	scanf("%d", &rowLimit);
	for(multiple = 1; multiple <= rowLimit; multiple++)
	{
		printf("%2d X %2d = %4d\n", tableNumber, multiple, tableNumber*multiple);
	}
}