// print Bigger one

#include <stdio.h>
#include "swap.c"
int main()
{
	int number1, number2;
	printf("Enter two numbers to check which is bigger one: ");
	scanf("%d%d", &number1, &number2);
	if(number1 == number2)
	{	printf("%d and %d are equal.", number1, number2);
		return;
	}
	if(number1 > number2)
		swap(&number1, &number2);
	
	printf("%d is bigger than %d.", number2, number1);
}
