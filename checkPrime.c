// check prime

#include<math.h>
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