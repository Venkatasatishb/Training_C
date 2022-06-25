// Print whether the given number is Prime or not.

#include <stdio.h>
#include <math.h>
int main()
{
	int number;
	printf("Enter a number to check whether it is Prime or Not: ");
	scanf("%d", &number);
	
	if(checkPrime(number) == 0)
		printf("%d is not a prime number.", number);
	else
		printf("%d is a prime number.", number);
}
int checkPrime(int number)
{
	int primeValue, divisor, squareRoot;
	if(number < 2)
		primeValue = 0;
	else if(number == 2)
		primeValue = 1;
	else if(number % 2 == 0)
		primeValue = 0;
	else
	{
		squareRoot = sqrt(number);
		for(divisor = 3; divisor <= squareRoot; divisor += 2)
		{
			if(number % divisor == 0)
			{
				primeValue = 0;
				break;
			}
		}
		if(divisor > squareRoot)
			primeValue = 1;
	}
	return primeValue;
}