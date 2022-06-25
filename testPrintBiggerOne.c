//  user print Bigger one

#include <stdio.h>
#include "printBiggerOne.c"
int main()

{
	int number1, number2;
	
	test(88, 88);
	test(69, 98);
	test(95, 32);
	test(785, 0);
	test(49, 56);

}
int test(int number1, int number2)
{
	int checkValue;
	checkValue = checkBiggerOne(&number1, &number2);
	(checkValue == 0 ? printf("%d and %d are equal.\n", number1, number2) : printf("%d is bigger than %d.\n", number2, number1));
}