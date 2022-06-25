// user check prime

#include <stdio.h>
#include "checkPrime.c"
int main()
{
	int number;
	printf("Enter a number to check whether it is Prime or Not: ");
	scanf("%d", &number);
	
	(checkPrime(number) == 0 ? printf("%d is not a prime number.", number) :printf("%d is a prime number.", number));
}