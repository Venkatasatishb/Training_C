int main()
{
	if (checkPrime(-68) == 0)
		printf("Passed\n");
	else
		printf("Failed\n");
	
	if (checkPrime(2) == 1)
		printf("Passed\n");
	else
		printf("Failed\n");

	if (checkPrime(6) == 0)
		printf("Passed\n");
	else
		printf("Failed\n");

	if (checkPrime(27) == 0)
		printf("Passed\n");
	else
		printf("Failed\n");
	
	if (checkPrime(67) == 1)
		printf("Passed\n");
	else
		printf("Failed\n");
	
}