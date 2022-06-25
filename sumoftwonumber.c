#include <stdio.h>
int main()
{
	int number1, number2, sum;
	printf("Enter two numbers to add: ");
	scanf("%d%d", &number1, &number2);
	sum = add(number1, number2);
	printf("The sum of %d and %d is %d.", number1, number2, sum);
}
int add(int firstNumber, int secondNumber)
{
	int sum;
	sum = firstNumber + secondNumber;
	return sum;
}