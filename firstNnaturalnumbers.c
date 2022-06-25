// first n natural numbers

#include<stdio.h>
int main()
{
	int limit, counter;
	printf("How many natural numbers do you want? ");
	scanf("%d", &limit);
	for(counter = 1; counter <= limit; counter++)
	{
		printf("%d\n", counter);
		
	}
}