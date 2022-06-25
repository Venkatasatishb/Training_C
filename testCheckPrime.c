// test check prime

#include <stdio.h>
#include "checkPrime.c"
int main()
{
	printf(checkPrime(-68) == 0 ? "Passed\n" : "Failed\n");
	printf(checkPrime(2) == 1 ? "Passed\n" : "Failed\n");	
	printf(checkPrime(6) == 0 ? "Passed\n" : "Failed\n");
	(checkPrime(27) == 0 ? printf("Passed\n") : printf("Failed\n"));
	(checkPrime(67) == 1 ? printf("Passed\n") : printf("Failed\n"));
}