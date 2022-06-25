#include <stdio.h>
int main()
{
	int count;
	printf("\nEnter how many natural numbers do you want? ");
	scanf("%d", &count);
	fflush(stdin);
	printNumber(count);
}

int printNumber(int number)
{
 	if (number != 1)
 	{
 		printNumber(number - 1);
 	}
 	printf("%d\n", number);
}




/*
#include <stdio.h>
struct countTerms
{
	int counter;
	int count;
};
int main()
{
	struct countTerms number;
	printf("\nEnter how many natural numbers do you want? ");
	scanf("%d", &number.count);
	fflush(stdin);
	for (number.counter = 1; number.counter <= number.count; number.counter++)
	{
		printf("%d\n", number.counter);
	}
}*/