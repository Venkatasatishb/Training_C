// swap two numbers

int swap(int *firstNumber, int *secondNumber)
{
	*firstNumber = *firstNumber + *secondNumber;
	*secondNumber = *firstNumber - *secondNumber;
	*firstNumber = *firstNumber - *secondNumber;
}
