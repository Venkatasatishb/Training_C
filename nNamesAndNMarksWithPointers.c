// n names and n marks with pointers

#include <stdio.h>
#include <stdlib.h>
#include "removeNewLine.c"
#define STUDENT_NAME_LENGTH 20
#define CURRENT_STUDENT_NAME_ADDRESS studentNames + (studentCounter * STUDENT_NAME_LENGTH)
int main()
{
	int studentsCount, studentCounter, *totalMarks;
	char *studentNames;
	printf("How many student marks do you want to enter? ");
	scanf("%d", &studentsCount);
	fflush(stdin);
	studentNames = malloc(studentsCount * STUDENT_NAME_LENGTH);
	totalMarks = malloc(studentsCount * sizeof(int));
	for (studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("Enter the name of the student %d of %d: ", studentCounter +1, studentsCount);
		fgets(CURRENT_STUDENT_NAME_ADDRESS, STUDENT_NAME_LENGTH, stdin);
		removeNewLine(CURRENT_STUDENT_NAME_ADDRESS);
		printf("Enter total marks: ");
		scanf("%d", &totalMarks[studentCounter]);
		fflush(stdin);
	}
	printf("\n\nEntered student names and total marks:\n");
	for (studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("Name of student %d: %s and total marks: %d.\n", studentCounter + 1, CURRENT_STUDENT_NAME_ADDRESS, totalMarks[studentCounter]);
	}
}