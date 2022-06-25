// Print n terms of the series: 1, 4, 27, 256 …

#include<stdio.h>
int printSeries(int limit)
{
	int counter, termCounter, product;
	for(termCounter = 1; termCounter <= limit; termCounter++)
	{
		product = 1;
		for(counter = 1; counter <= termCounter; counter++)
		{
			product = product * termCounter;
		}
		printf("%d", product);
		printf(termCounter < limit ? ", " : ".");
	}
}