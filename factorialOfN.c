/*// Factorial of given number using loop

#include <stdio.h>
#include <time.h>
int main()
{
	int givenNumber, numberCounter, factorial = 1;
	clock_t startingTime, endingTime;
	double totalTimeTaken;
	printf("Enter the number to find the factorial: ");
	scanf("%d", &givenNumber);
	fflush(stdin);
	startingTime = clock();
	for (numberCounter = 1; numberCounter <= givenNumber; numberCounter++)
	{
		factorial = factorial * numberCounter;
	}
	printf("Factorial of %d is %d", givenNumber, factorial);
	endingTime = clock();
	totalTimeTaken = ((double) (endingTime - startingTime)) / CLOCKS_PER_SEC;
	printf("\nTotal Time Taken To Run The Program: %f.", totalTimeTaken);
}
*/

// Factorial of given number using recursive function

#include <stdio.h>
#include <time.h>
int main()
{
	int givenNumber, factorial;
	clock_t startingTime, endingTime;
	double totalTimeTaken;
	printf("Enter the givenNumber to find the factorial: ");
	scanf("%d", &givenNumber);
	fflush(stdin);
	startingTime = clock();
	factorial = product(givenNumber);
	printf("Factorial of %d is %d.", givenNumber, factorial);
	endingTime = clock();
	totalTimeTaken = ((double) (endingTime - startingTime)) / CLOCKS_PER_SEC;
	printf("\nTotal Time Taken To Run The Program: %f.", totalTimeTaken);
}

int product(int number)
{
	int factorial = 1;
	if (number != 1)
	{
		factorial = product(number - 1);
	}
	factorial = factorial * number;
}






















/*// #include <sys/resource.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
	int number, counter, fact = 1;
	clock_t startingTime, endingTime;
	double totalTimeTaken;
	printf("Enter the number to find the factorial: ");
	scanf("%d", &number);
	fflush(stdin);
	startingTime = clock();
	for (counter = 1; counter <= number; counter++)
	{
		fact = fact * counter;
	}
	printf("Factorial of %d is %u", number, fact);
	endingTime = clock();
	totalTimeTaken = ((double) (endingTime - startingTime)) / CLOCKS_PER_SEC;
	printf("\nTotal Time Taken To Run The Program: %f.", totalTimeTaken);
   struct rusage r_usage;
   int *p = 0;
   {
      p = (int*)malloc(sizeof(int)*1000);
      int ret = getrusage(RUSAGE_SELF,&r_usage);
      if(ret == 0)
         printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
      else
         printf("Error in getrusage. errno = %d\n", errno);
      usleep(10);
   }
   return 0;
}*/