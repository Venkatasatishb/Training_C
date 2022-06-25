// print Bigger one

int checkBiggerOne(int *number1, int *number2)
{	int checkValue;
	if(*number1 == *number2)
	checkValue = 0;
	
	else if(*number1 > *number2)
	{
	*number1 = *number1 + *number2;
	*number2 = *number1 - *number2;
	*number1 = *number1 - *number2;
	
	checkValue = 1;
	} 
	return checkValue;
}
