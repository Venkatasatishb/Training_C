// Print n terms of the series: 1, 4, 27, 256 …

#include<stdio.h>
int main()
{	int limit, counter, termCounter, product;
	printf("1, 4, 27, 256...\n");
	printf("How many terms do you want in the above series? ");
	scanf("%d", &limit);
	for(termCounter = 1; termCounter <= limit; termCounter++)
	{
		product = 1;
		for(counter = 1; counter <= termCounter; counter++)
		{
			product = product * termCounter;
		}
		printf("%d", product);
		if(termCounter < limit)
			printf(", ");
		else if(termCounter = limit)
			printf(".");
		
	}
	
}