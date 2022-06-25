//  user print Bigger one

#include <stdio.h>
#include "printBiggerOne.c"
int main()
{
	int number1, number2, checkValue;
	printf("Enter two numbers to check which is bigger one: ");
	scanf("%d%d", &number1, &number2);
	checkValue = checkBiggerOne(&number1, &number2);
	(checkValue == 0 ? printf("%d and %d are equal.", number1, number2) : printf("%d is bigger than %d.", number2, number1));
}