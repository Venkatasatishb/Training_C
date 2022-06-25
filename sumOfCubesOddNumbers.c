// Sum of cubes of first N odd numbers

#include<stdio.h>
int main()
{	int limit, sum = 0, number = 1, termCounter;
	printf("How many cubes of first odd numbers do you want to add? ");
	scanf("%d", &limit);
	for(termCounter = 1; termCounter <= limit; termCounter++)
	{
		sum = sum + (number * number * number);
		number = number + 2;
	}
	printf("The sum of cubes of first %d odd numbers is %d.", limit, sum);
}