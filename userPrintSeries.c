// user print n terms of the series: 1, 4, 27, 256 …

#include <stdio.h>
#include "printSeries.c"
int main()
{	int limit;
	printf("1, 4, 27, 256...\n");
	printf("How many terms do you want in the above series? ");
	scanf("%d", &limit);
	printSeries(limit);
}