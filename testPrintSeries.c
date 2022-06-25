// test  print n to the power of n series

#include <stdio.h>
#include "printSeries.c"
int main()
{	printf("The n terms of the series: 1, 4, 27, 256...\n\n");

	printSeries(4);
	printf("\n");

	printSeries(5);
	printf("\n");

	printSeries(7);
	printf("\n");

	printSeries(1);
	printf("\n");
}