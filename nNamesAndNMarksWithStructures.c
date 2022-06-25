// n names and n marks with structures

#include <stdio.h>
#include "removeNewLine.c"
#define STUDENT_NAME_LENGTH 20
#define CURRENT_STUDENT_ROLL_NUMBER_ADDRESS student[studentCounter].studentRollNumber
#define CURRENT_STUDENT_NAME_ADDRESS student[studentCounter].studentName
#define CURRENT_STUDENT_TOTAL_MARKS_ADDRESS student[studentCounter].studentTotalMarks
struct studentsDetails
{
	int studentRollNumber;
	char studentName[STUDENT_NAME_LENGTH];
	int studentTotalMarks;
};
int main()
{
	int studentsCount, studentCounter;
	printf("How many students details do you want to enter? ");
	scanf("%d", &studentsCount);
	fflush(stdin);
	struct studentsDetails student[studentsCount];
	for (studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("Enter the roll number of student %d of %d: ", studentCounter + 1, studentsCount);
		scanf("%d", &CURRENT_STUDENT_ROLL_NUMBER_ADDRESS);
		fflush(stdin);
		printf("Enter the name of the student: ", studentCounter + 1, studentsCount);
		fgets(CURRENT_STUDENT_NAME_ADDRESS, STUDENT_NAME_LENGTH, stdin);
		removeNewLine(CURRENT_STUDENT_NAME_ADDRESS);
		printf("Enter the total marks: ");
		scanf("%d", &CURRENT_STUDENT_TOTAL_MARKS_ADDRESS);
		fflush(stdin);
	}
	printf("\n\nEntered students details: \n");
	for (studentCounter = 0; studentCounter < studentsCount; studentCounter++)
	{
		printf("Roll.No: %d, Name of the student: %s and total marks: %d.\n", CURRENT_STUDENT_ROLL_NUMBER_ADDRESS, CURRENT_STUDENT_NAME_ADDRESS, CURRENT_STUDENT_TOTAL_MARKS_ADDRESS);
	}
}