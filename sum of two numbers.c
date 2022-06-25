// Sum of two numbers

#include<stdio.h>
void main()
{
	int number1,number2,sum;
	printf("Enter two numbers to add: ");
	scanf("%d,%d",&number1,number2);
	sum = number1 + number2;
	printf("The sum of %d and %d is %d.",number1,number2,sum);
}