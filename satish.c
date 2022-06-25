// nNames with linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define NAME_LENGTH 50
#define NAMES_FILE "nNamesss.dat"
typedef struct name
{
	char name[NAME_LENGTH];
	struct name *next;
}name;

name *start;

int main()
{
	start = '\0';
	showMenu();
}

/*int main()
{
	start = '\0';
	loadNamesInToLinkedList();
	displayAllNames();

}*/
// -------------------------
int showMenu()
{
	int choice;
	loadNamesInToLinkedList();
	do
	{
		printf("\n1. Add New Name\n2. Display All Names\n3. Save Names\n4. Delete Name\n5. Update Name\n6. Sort Names\n7. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				// addNewName();
				break;
			case 2:
				displayAllNames();
				break;
			// case 3:
			// 	saveNames();
			// 	break;
			case 4:
				deleteName();
				break;
			// case 5:
			// 	updateName();
			// 	break;
			case 6:
				sortNames();
				break;
		}
	} while (choice != 7);
}
// -----------------------------------------
int loadNamesInToLinkedList()
{
	name *ptrName = start;
	char tempName[NAME_LENGTH];
	FILE *fpNames = fopen(NAMES_FILE, "r");
	while (fgets(tempName, NAME_LENGTH, fpNames) != '\0')
	{
		if (ptrName == '\0')
		{
			ptrName = malloc(sizeof(name));
			strcpy(ptrName->name, tempName);
			ptrName->next = '\0';
			start = ptrName;
		}
		else
		{
			while (ptrName->next != '\0')
			{
				ptrName = ptrName->next;
			}
			ptrName->next = malloc(sizeof(name));
			strcpy(ptrName->next->name, tempName);
			ptrName->next->next = '\0';
		}
	}
}


// ----------------------------------------------
int displayAllNames()
{
	name *ptrName = start;
	while (ptrName != '\0')
	{
		printf("%s", ptrName->name);
		ptrName = ptrName->next;
	}
}

// ---------------------------------------
/*int sortNames()
{
	name *ptrName = start, *ptrName2;
	int count = 0;
	int i,j;
	char tempName[NAME_LENGTH];
	while(ptrName != '\0')
	{
		count++;
		ptrName = ptrName->next;
	}
	printf("%d\n", count);
	ptrName = start;
	for (i = 0; i < count-1; i++)
	{
		ptrName2 = ptrName->next;
		for (j = i+1; j < count; j++)
		{
			if (strcmp(ptrName->name,ptrName2->name) > 0)
			{
				strcpy(tempName,ptrName->name);
				strcpy(ptrName->name, ptrName2->name);
				strcpy(ptrName2->name, tempName);

			}
			ptrName2 = ptrName2->next;
		}
		ptrName = ptrName->next;
	}
}
*/
// --------------------------------------------------------
int sortNames()
{
// 	name *ptrName = start, *ptrName2;
// 	char tempName[NAME_LENGTH];
// /*	int count = 0;
// 	int i,j;
// 	while(ptrName != '\0')
// 	{
// 		count++;
// 		ptrName = ptrName->next;
// 	}
// 	printf("%d\n", count);
// 	ptrName = start;*/
// 	while (ptrName->next != '\0')
// 	{
// 		ptrName2 = ptrName->next;
// 		while (ptrName2 != '\0')
// 		{
// 			if (strcmp(ptrName->name,ptrName2->name) > 0)
// 			{
// 				strcpy(tempName,ptrName->name);
// 				strcpy(ptrName->name, ptrName2->name);
// 				strcpy(ptrName2->name, tempName);

// 			}
// 			ptrName2 = ptrName2->next;
// 		}
// 		ptrName = ptrName->next;
// 	}
}





int deleteName()
{
	char nameToBeDeleted[NAME_LENGTH];
	printf("Enter The To Delete: ");
	fgets(nameToBeDeleted, NAME_LENGTH, stdin);
	removeNewLine(nameToBeDeleted);
	name *prevName = '\0', *tempName =start;
	while (strcmp(tempName->name, nameToBeDeleted) != 0)
	{
		prevName = tempName;
		tempName = tempName->next;
	}
	if (prevName == '\0')
	{
		start = tempName->next;
	}
	else
	{
		prevName->next = tempName->next;
	}
}










/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define NAME_LENGTH 50
#define NAMES_FILE "nNamesss.dat"
typedef struct node
{
	char name[50];
	struct node *next;
}node;
node *start;
int main()
{
	showMenu();
}

// -------------------------
int showMenu()
{
	int choice;
	// loadNamesInToLinkedList();
	loadList();
	do
	{
		printf("\ncreate\ndisplay");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice)
		{
			case 1:
				saveName();
				break;
			case 2:
				display();
				break;
			case 3:
				saveInToFile();
				break;
			case 4:
				sortNames();
				break;
		}
	} while (choice != 5);
}
// -----------------------------------------
/*int loadNamesInToLinkedList()
{
	node *ptr = start;
	char temp[NAME_LENGTH];
	FILE *fpNames = fopen(NAMES_FILE, "r");
	while (fread(temp, NAME_LENGTH, 1, fpNames) != '\0')
	{
		if (ptr == '\0')
		{
			ptr = malloc(sizeof(node));
			strcpy(ptr->name, temp);
			ptr->next = '\0';
			start = ptr;
			
		}
		else
		{
			while (ptr->next != '\0')
			{
				ptr = ptr->next;
			}
			ptr->next = malloc(sizeof(node));
			strcpy(ptr->next->name, temp);
			ptr->next->next = '\0';
		}

	}
}
*/

// ----------------------------------------------
/*int saveName()
{
	node *h;
	h = start;
	char name[NAME_LENGTH];
	printf("\nEnter Name: ");
	fgets(name, NAME_LENGTH, stdin);
	removeNewLine(name);
	if (h == '\0')
	{
		start = malloc(sizeof(node));
		strcpy(start->name, name);
		start->next = '\0';
	}
	else
	{
		while (h->next != '\0')
		{
			h = h->next;
		}
		h->next = malloc(sizeof(node));
		strcpy(h->next->name, name);
		h->next->next = '\0';
	}
}
*/
/*
int saveName()
{
	char name[NAME_LENGTH];
	FILE *fpNames = fopen(NAMES_FILE, "a");
	printf("\nEnter Name:");
	fgets(name, NAME_LENGTH, stdin);
	removeNewLine(name);
	fwrite(name, NAME_LENGTH, 1, fpNames);
	fclose(fpNames);
}
// ----------------------------------------------
int display()
{
	node *h = start;
	while (h != '\0')
	{
		printf("%s\n", h->name);
		h = h->next;
	}
}


//-----------------------------------------
int saveInToFile() 
{
	node *ptr = start;
	FILE *fpNames = fopen(NAMES_FILE, "w");
	while (ptr != '\0')
	{
		fwrite(ptr->name, NAME_LENGTH, 1, fpNames);
		ptr = ptr->next;
	}
	fclose(fpNames);
}

int sortNames()
{
	node *ptrName = start;
	int count = 1;
	int i,j;
	char tempName[NAME_LENGTH];
	while(ptrName != '\0')
	{
		count++;
		ptrName = ptrName->next;
	}
	printf("%d\n", count);
	ptrName = start;
	for(i = 2; i<count; i++)
	{
		while (ptrName != '\0')
		{

		j=strcmp(ptrName->name, ptrName->next->name);
		printf("%d\n", j);
		if(j == 1)
		{
			strcpy(tempName, ptrName->name);
			strcpy(ptrName->name, ptrName->next->name);
			strcpy(ptrName->next->name, tempName);

		}
		ptrName = ptrName->next;
		}
	}
	// saveName();
}
*/

/*// -----------------------------------------
int create()
{
	FILE *fpNames = fopen("nNames.dat", "r");
	while(fgets(temp->name, 50, fpNames);)
	struct node *temp, *ptr;
	temp = malloc(sizeof(struct node));
	printf("\nEnter Name: ");
	fgets(temp->name, 50, fpNames);
	temp->next = '\0';
	if (start == '\0')
	{
		start = temp;
	}
	else
	{
		ptr = start;
		while(ptr->next != '\0')
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	// fwrite(temp, sizeof(struct node), 1, fpNames);
	fclose(fpNames);
}

// ----------------------------------------
int display()
{
	struct node *ptr;
	ptr = start;
	while(ptr != '\0')
	{
		printf("%s\n", ptr->name);
		ptr = ptr->next;
	}
}

// -----------------------------
int saveName()
{
	// printf("22222222222222222222222222222222\n");
	FILE *fpName = fopen("nNames.dat", "a");
	char name[NAME_LENGTH];
	int option;
	do
	{
		printf("\nEnter The Name: ");
		fgets(name, NAME_LENGTH, stdin);
		removeNewLine(name);
		fwrite(name, NAME_LENGTH, 1, fpName);
		printf("\nDo You Want to Add Another Name? \n1. Yes\n2. No\n");
		printf("Enter You Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpName);
}





*/













































































/*// Definition Of Given Word

#include <stdio.h>
#include <string.h>
#include "myTools.c"
#define WORD_LENGTH 50
#define COMMAND_LENGTH 150
#define WORD_MEANING_LENGTH 5000

int main()
{
	char wordToBeSearched[WORD_LENGTH], *pieceOfMeaning;
	char commandForPronunciation[COMMAND_LENGTH];
	char command[COMMAND_LENGTH];
	printf("\nEnter the word to be searched: ");
	fgets(wordToBeSearched, WORD_LENGTH, stdin);
	removeNewLine(wordToBeSearched);
	sprintf(command, "curl -k https://api.dictionaryapi.dev/api/v2/entries/en/%s>wordDefinition.txt", wordToBeSearched);
	system(command);
	FILE *fpWordDefinition = fopen("wordDefinition.txt", "r");
	char wordMeaning[WORD_MEANING_LENGTH];
	fgets(wordMeaning, WORD_MEANING_LENGTH, fpWordDefinition);
	fclose(fpWordDefinition);
	pieceOfMeaning = strtok(wordMeaning, ":");
	while (pieceOfMeaning != '\0')
	{
		if (strcmp(pieceOfMeaning, "\"https") == 0)
		{
			pieceOfMeaning = strtok('\0', "\"");
			sprintf(commandForPronunciation ,"vlc \"http:%s\"", pieceOfMeaning);
			system(commandForPronunciation);
			break;
		}
		pieceOfMeaning = strtok('\0', ",:");
	}
	while (pieceOfMeaning != '\0')
	{
		if (strcmp(pieceOfMeaning, "[{\"definition\"") == 0)
		{
			pieceOfMeaning = strtok('\0', ",");
			printf("Meaning of %s: %s", wordToBeSearched, pieceOfMeaning);
			break;
		}
		pieceOfMeaning = strtok('\0', ":");
	}
}

*/












/*#include <stdio.h>
int main()
{
	char c = 'A';
	printf("%d\n", c);
}

*/
/*#include <stdio.h>
int main()
{
	char string[] = "ABC";
	char *ptrString = string;
	printf("%d\n", ptrString);
}


*/
/* #include <stdio.h>
main()
{
	int i = 65;
	printf("%s\n", i);
}
*/








/*// Program using strtok()

#include <stdio.h>
#include <string.h>
int main()
{
	char string[50] = "This-Is Satish";
	char *token;
	token = strtok(string, " -");
	while (token != '\0')
	{
		printf("%s\n", token);
		token = strtok('\0', " -");
	}
}
*/




/*#include <stdio.h>
int main()
{
	FILE *fp = fopen("myExperments.dat", "r");
	char name[10];
	int returnValue;
	returnValue = fread(name, 10, 1, fp);
	if (returnValue == 1)
	{
		printf("True\n");
	}	
	else
	{
		printf("False\n");
	}
	fread(name, 10, 1, fp);
	if (returnValue == 1)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	fread(name, 10, 1, fp);
	if (returnValue == 1)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	fclose(fp);
}

*/
/*
#include <stdio.h>
#include "myTools.c"
int main()
{
	int i = 16961;
	char *ptrC;
	ptrC = (char*)&i;
	printf("%s\n", ptrC);
}*/



/*#include <stdio.h>
int main()
{
	char string[5] = "ABCD";
	int *ptrString;
	ptrString = (int*)string;
	printf("%d\n", *ptrString);
}

*/

/*#include <stdio.h>
int main()
{
	system("cls");
	char s[10];
	char m[50];
	printf("---");
	scanf("%s",s);
	sprintf(m,"This is %s", s);
	printf("%s\n", m);
}

*/

/*
#include <stdio.h>
#include "myTools.c"
int main()
{

	int i = 4407873;
	char *ptrC;
	ptrC = (char*)&i;
	printf("%s\n", ptrC);
	char string[] = "ABC";
	int *ptrString;
	ptrString = string;
	printf("%d\n", prtString);
}
*/
// #include <stdio.h>
// #include "myTools.c"
// int main()
// {
// 	int i = 4407873;
// 	char *ptrC,**PtrN;
// 	ptrC = &i;
// 	printf("%s\n", ptrC);
// 	PtrN = malloc(26 * sizeof(char*));
// 	int j = 0;
// 	for (i = 65; i < 91; i++)
// 	{
// 		PtrN[j] = malloc(sizeof(char));
// 		PtrN[j] = &i;
// 		printf("%c", PtrN[j]);
// 		j++;
// 	}
// /*	for (j = 0; j < 26; j++)
// 	{
// 	}
// */
// }




/*#include <stdio.h>

int main()
{
	FILE *fp = fopen("myData.dat", "w");
	int i, j = 1145258561;
	// for (i = 0; i < 26; i++)
	{
		fwrite(&j, sizeof(j), 1, fp);
		// j = j +257;
	}
	// for (i = 0; i < 26; i++)
	// {
	// 	fread(&j, sizeof(j), 1, fp);
	// 	printf("%d\n", j);
	// }
	// fread(&j, sizeof(j), 1, fp);
	fclose(fp);

}*/





/*// Patients Records

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define PATIENT_ID_LENGTH 7
#define PATIENT_NAME_LENGTH 25
#define PATIENT_COMPLAINTS_LENGTH 20
#define FILE_NAME "patientsDetails.dat"
struct patientDetails
{
	char patientId[PATIENT_ID_LENGTH];
	char patientName[PATIENT_NAME_LENGTH];
	char patientComplaints[PATIENT_COMPLAINTS_LENGTH];
	float patientBillAmount;
	char patientStatus;
};
int main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 6);
}

int showMenu()
{
	int choice;
	printf("\n1. Save New Patient Record\n2. Show All Patients Records\n3. Update Patient Record\n");
	printf("4. Close patient Record\n5. Search Patient Record\n6. Exit\n");
	printf("Enter you Choice: ");	
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveNewPatientRecord();
			break;
		case 2:
			showAllPatientsRecords();
			break;
		case 3:
			updatePatientRecord();
			break;
		case 4:
			closePatientRecord();
			break;
		case 5:
			searchPatientRecord();
			break;
		case 6:
			exit(0);
		default:
			printf("\nChoose The Correct Option.\n");
			break;
	}
	return choice;
}

int saveNewPatientRecord()
{
	int option;
	FILE *fpPatientDetails;
	fpPatientDetails = fopen(FILE_NAME, "a");
	struct patientDetails patient;
	do
	{
		printf("\nEnter Patient Details:\n");
		printf("Enter Patient Id: ");
		scanf("%s", patient.patientId);
		fflush(stdin);
		printf("Enter Patient Name: ");
		fgets(patient.patientName, PATIENT_NAME_LENGTH, stdin);
		removeNewLine(patient.patientName);
		printf("Enter Patient Complaints: ");
		fgets(patient.patientComplaints, PATIENT_COMPLAINTS_LENGTH, stdin);
		removeNewLine(patient.patientComplaints);
		printf("Enter Bill Amount: ");
		scanf("%f", &patient.patientBillAmount);
		fflush(stdin);
		patient.patientStatus = 'A';
		fwrite(&patient, sizeof(patient), 1, fpPatientDetails);
		printf("\nDo You Want To Save Another Record? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpPatientDetails);
}

int showAllPatientsRecords()
{
	FILE *fpPatientDetails;
	fpPatientDetails = fopen(FILE_NAME, "r");
	struct patientDetails patient;
	if (fread(&patient, sizeof(patient), 1, fpPatientDetails) == '\0')
	{
		printf("\nNo Records Found.\n");
	}
	else
	{
		do
		{
			printf("\nPatient Details: \n");
			printf("Patient Id: %s\nPatient Name: %s\n", patient.patientId, patient.patientName);
			printf("Patient Complaints: %s\nPatient Bill Amount: %.2f\n", patient.patientComplaints, patient.patientBillAmount);
			if (patient.patientStatus == 'A')
			{
				printf("Patient Status: Admitted\n");
			}
			else if (patient.patientStatus == 'D')
			{
				printf("Patient Status: Discharged\n");
			}
		} while (fread(&patient, sizeof(patient), 1, fpPatientDetails) != '\0');
	}
	fclose(fpPatientDetails);
}

int updatePatientRecord()
{
	FILE *fpPatientDetails;
	fpPatientDetails = fopen(FILE_NAME, "r+");
	struct patientDetails patient;
	int compareValue, recordUpdated = 0;
	char givenPatientId[PATIENT_ID_LENGTH];
	printf("\nEnter Patient Id:");
	scanf("%s", givenPatientId);
	fflush(stdin);
	while(fread(&patient, sizeof(patient), 1, fpPatientDetails) != '\0')
	{
		compareValue = strcmp(givenPatientId, patient.patientId);
		if (compareValue == 0)
		{	
			int option;
			printf("\nPatient Details: \n");
			printf("Patient Name: %s\nPatient Complaints: %s\n", patient.patientName, patient.patientComplaints);
			printf("Patient Bill Amount: %.2f\n", patient.patientBillAmount);
			
			do
			{
				printf("\nWhat Do You Want To Update?\n");
				printf("1. Patient Name\n2. patient Complaints\n3. Patient Bill Amount\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
				switch (option)
				{
					case 1:
						printf("\nEnter Patient Name: ");
						fgets(patient.patientName, PATIENT_NAME_LENGTH, stdin);
						removeNewLine(patient.patientName);
						break;
					case 2:
						printf("\nEnter Patient Complaints: ");
						fgets(patient.patientComplaints, PATIENT_COMPLAINTS_LENGTH, stdin);
						removeNewLine(patient.patientComplaints);
						break;
					case 3:
						printf("\nEnter Bill Amount: ");
						scanf("%f", &patient.patientBillAmount);
						fflush(stdin);
				}
				printf("\nDo You Want To Update Any More?\n1. Yes\n2. No\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
			} while (option == 1);
			fseek(fpPatientDetails, -sizeof(patient), SEEK_CUR);
			fwrite(&patient, sizeof(patient), 1, fpPatientDetails);
			printf("\nRecord Updated.\n");
			recordUpdated = 1;
			break;
		}
	};
	if (recordUpdated != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpPatientDetails);
}

int closePatientRecord()
{
	FILE *fpPatientDetails;
	fpPatientDetails = fopen(FILE_NAME, "r+");
	struct patientDetails patient;
	int compareValue, recordClosed = 0;
	char givenPatientId[PATIENT_ID_LENGTH];
	printf("Enter Patient Id:");
	scanf("%s", givenPatientId);
	fflush(stdin);
	while(fread(&patient, sizeof(patient), 1, fpPatientDetails) != '\0')
	{
		compareValue = strcmp(givenPatientId, patient.patientId);
		if (compareValue == 0)
		{	
			patient.patientStatus = 'D';
			fseek(fpPatientDetails, -sizeof(patient), SEEK_CUR);
			fwrite(&patient, sizeof(patient), 1, fpPatientDetails);
			printf("\nRecord Closed.\n");
			recordClosed = 1;
			break;
		}
	};
	if (recordClosed != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpPatientDetails);
}

int searchPatientRecord()
{
	FILE *fpPatientDetails;
	fpPatientDetails = fopen(FILE_NAME, "r");
	struct patientDetails patient;
	int compareValue, matchFound = 1;
	char givenPatientId[PATIENT_ID_LENGTH];
	printf("Enter Patient Id:");
	scanf("%s", givenPatientId);
	fflush(stdin);
	while(fread(&patient, sizeof(patient), 1, fpPatientDetails) != '\0')
	{
		compareValue = strcmp(givenPatientId, patient.patientId);
		if (compareValue == 0)
		{
			printf("\nPatient Details: \n");
			printf("Patient Id: %s\nPatient Name: %s\n", patient.patientId, patient.patientName);
			printf("Patient Complaints: %s\nPatient Bill Amount: %.2f\n", patient.patientComplaints, patient.patientBillAmount);
			if (patient.patientStatus == 'A')
			{
				printf("Patient Status: Admitted\n");
			}
			else if (patient.patientStatus == 'D')
			{
				printf("Patient Status: Discharged\n");
			}
			matchFound = 1;
			break;
		}
	};
	if (matchFound != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpPatientDetails);
}*/








// _______________________________________________________________________________________________________________________

/*
// Students Records

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define STUDENT_ADMISSION_NUMBER_LENGTH 7
#define STUDENT_NAME_LENGTH 25
#define STUDENT_FATHER_NAME_LENGTH 25
#define STUDENT_CLASS_LENGTH 3
#define FILE_NAME "studentsDetails.dat"
struct studentDetails
{
	char studentAdmissionNumber[STUDENT_ADMISSION_NUMBER_LENGTH];
	char studentName[STUDENT_NAME_LENGTH];
	char studentFatherName[STUDENT_FATHER_NAME_LENGTH];
	char studentClass[STUDENT_CLASS_LENGTH];
	char studentStatus;
};
int main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 6);
}

// ------------------------------------
int showMenu()
{
	int choice;
	printf("\n1. Save New Student Record\n2. Show All Students Records\n3. Update Student Record\n");
	printf("4. Close Student Record\n5. Search Student Record\n6. Exit\n");
	printf("Enter you Choice: ");	
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveNewStudentRecord();
			break;
		case 2:
			showAllStudentsRecords();
			break;
		case 3:
			updateStudentRecord();
			break;
		case 4:
			closeStudentRecord();
			break;
		case 5:
			searchStudentRecord();
			break;
		case 6:
			exit(0);
		default:
			printf("\nChoose The Correct Option.\n");
			break;
	}
	return choice;
}

// --------------------------------------------
int saveNewStudentRecord()
{
	int option;
	FILE *fpStudentDetails;
	fpStudentDetails = fopen(FILE_NAME, "a");
	struct studentDetails student;
	do
	{
		printf("\nEnter Student Details:\n");
		printf("Enter Student Admission Number: ");
		scanf("%s", student.studentAdmissionNumber);
		fflush(stdin);
		printf("Enter Student Name: ");
		fgets(student.studentName, STUDENT_NAME_LENGTH, stdin);
		removeNewLine(student.studentName);
		printf("Enter Student's Father Name: ");
		fgets(student.studentFatherName, STUDENT_FATHER_NAME_LENGTH, stdin);
		removeNewLine(student.studentFatherName);
		printf("Enter Student's Class: ");
		scanf("%s", student.studentClass);
		fflush(stdin);
		student.studentStatus = 'A';
		fwrite(&student, sizeof(student), 1, fpStudentDetails);
		printf("\nDo You Want To Save Another Record? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpStudentDetails);
}

// -----------------------------------------------------
int showAllStudentsRecords()
{
	FILE *fpStudentDetails;
	fpStudentDetails = fopen(FILE_NAME, "r");
	struct studentDetails student;
	int recordsPrinted = 0;

	while (fread(&student, sizeof(student), 1, fpStudentDetails) != '\0')
	{
		printf("\nStudent Details: \n");
		printf("Student Admission Number: %s\nStudent Name: %s\n", student.studentAdmissionNumber, student.studentName);
		printf("Father Name: %s\nClass: %s\n", student.studentFatherName, student.studentClass);
		if (student.studentStatus == 'A')
		{
			printf("Student Status: Admitted\n");
		}
		else if (student.studentStatus == 'R')
		{
			printf("Student Status: Relieved\n");
		}
		recordsPrinted = 1;
	};
	if (recordsPrinted != 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpStudentDetails);
}
// --------------------------------------------------------
int updateStudentRecord()
{
	FILE *fpStudentDetails;
	fpStudentDetails = fopen(FILE_NAME, "r+");
	struct studentDetails student;
	int compareValue, recordUpdated = 0;
	char givenStudentAdmissionNumber[STUDENT_ADMISSION_NUMBER_LENGTH];
	printf("\nEnter Student Admission Number:");
	scanf("%s", givenStudentAdmissionNumber);
	fflush(stdin);
	while(fread(&student, sizeof(student), 1, fpStudentDetails) != '\0')
	{
		compareValue = strcmp(givenStudentAdmissionNumber, student.studentAdmissionNumber);
		if (compareValue == 0)
		{	
			int option;
			printf("\nStudent Details: \n");
			printf("Student Name: %s\nFather Name: %s\n", student.studentName, student.studentFatherName);
			printf("Class: %s\n", student.studentClass);
			
			do
			{
				printf("\nWhat Do You Want To Update?\n");
				printf("1. Student Name\n2. Father Name\n3. Student Class\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
				switch (option)
				{
					case 1:
						printf("\nEnter Student Name: ");
						fgets(student.studentName, STUDENT_NAME_LENGTH, stdin);
						removeNewLine(student.studentName);
						break;
					case 2:
						printf("\nEnter Father Name: ");
						fgets(student.studentFatherName, STUDENT_FATHER_NAME_LENGTH, stdin);
						removeNewLine(student.studentFatherName);
						break;
					case 3:
						printf("\nEnter Class ");
						scanf("%s", student.studentClass);
						fflush(stdin);
				}
				printf("\nDo You Want To Update Any More?\n1. Yes\n2. No\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
			} while (option == 1);
			fseek(fpStudentDetails, -sizeof(student), SEEK_CUR);
			fwrite(&student, sizeof(student), 1, fpStudentDetails);
			printf("\nRecord Updated.\n");
			recordUpdated = 1;
			break;
		}
	};
	if (recordUpdated != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpStudentDetails);
}

// ---------------------------------------------------
int closeStudentRecord()
{
	FILE *fpStudentDetails;
	fpStudentDetails = fopen(FILE_NAME, "r+");
	struct studentDetails student;
	int compareValue, recordClosed = 0;
	char givenStudentAdmissionNumber[STUDENT_ADMISSION_NUMBER_LENGTH];
	printf("\nEnter Student Admission Number:");
	scanf("%s", givenStudentAdmissionNumber);
	fflush(stdin);
	while(fread(&student, sizeof(student), 1, fpStudentDetails) != '\0')
	{
		compareValue = strcmp(givenStudentAdmissionNumber, student.studentAdmissionNumber);
		if (compareValue == 0)
		{	
			student.studentStatus = 'R';
			fseek(fpStudentDetails, -sizeof(student), SEEK_CUR);
			fwrite(&student, sizeof(student), 1, fpStudentDetails);
			printf("\nRecord Closed.\n");
			recordClosed = 1;
			break;
		}
	};
	if (recordClosed != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpStudentDetails);
}

// -------------------------------------------------
int searchStudentRecord()
{
	FILE *fpStudentDetails;
	fpStudentDetails = fopen(FILE_NAME, "r+");
	struct studentDetails student;
	int compareValue, matchFound = 0;
	char givenStudentAdmissionNumber[STUDENT_ADMISSION_NUMBER_LENGTH];
	printf("\nEnter Student Admission Number:");
	scanf("%s", givenStudentAdmissionNumber);
	fflush(stdin);
	while(fread(&student, sizeof(student), 1, fpStudentDetails) != '\0')
	{
		compareValue = strcmp(givenStudentAdmissionNumber, student.studentAdmissionNumber);
		if (compareValue == 0)
		{	
			printf("\nStudent Details: \n");
			printf("Student Admission Number: %s\nStudent Name: %s\n", student.studentAdmissionNumber, student.studentName);
			printf("Father Name: %s\nClass: %s\n", student.studentFatherName, student.studentClass);
			if (student.studentStatus == 'A')
			{
				printf("Student Status: Admitted\n");
			}
			else if (student.studentStatus == 'R')
			{
				printf("Student Status: Relieved\n");
			}
			matchFound = 1;
			break;
		}
	};
	if (matchFound != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpStudentDetails);
}
*/
// _________________________________________________________________________________________________________________________


/*// Employes Records

#include <stdio.h>
#include <stdlib.h>
#include "myTools.c"
#define EMPLOYEE_ID_LENGTH 7
#define EMPLOYEE_NAME_LENGTH 25
#define EMPLOYEE_POST_LENGTH 20
#define FILE_NAME "employesDetails.dat"
struct employeeDetails
{
	char employeeId[EMPLOYEE_ID_LENGTH];
	char employeeName[EMPLOYEE_NAME_LENGTH];
	char employeePost[EMPLOYEE_POST_LENGTH];
	float employeeSalary;
	char employeeStatus;
};
int main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 6);
}

// ----------------------------------------------------------
int showMenu()
{
	int choice;
	printf("\n1. Save Employee Record\n2. Show All Employes Records\n3. Update Employee Record\n");
	printf("4. Close Employee Record\n5. Search Employee Record\n6. Exit\n");
	printf("Enter you Choice: ");	
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveNewEmployeeRecord();
			break;
		case 2:
			showAllEmployesRecords();
			break;
		case 3:
			updateEmployeeRecord();
			break;
		case 4:
			closeEmployeeRecord();
			break;
		case 5:
			searchEmployeeRecord();
			break;
		case 6:
			exit(0);
		default:
			printf("\nChoose The Correct Option.\n");
			break;
	}
	return choice;
}

// ------------------------------------------------------------------
int saveNewEmployeeRecord()
{
	int option;
	struct employeeDetails employee;
	FILE *fpEmployeeDetails;
	fpEmployeeDetails = fopen(FILE_NAME, "a");
	do
	{
		printf("\nEnter Employee Details:\n");
		printf("Enter Employee Id: ");
		scanf("%s", employee.employeeId);
		fflush(stdin);
		printf("Enter Employee Name: ");
		fgets(employee.employeeName, EMPLOYEE_NAME_LENGTH, stdin);
		removeNewLine(employee.employeeName);
		printf("Enter Employee Post: ");
		fgets(employee.employeePost, EMPLOYEE_POST_LENGTH, stdin);
		removeNewLine(employee.employeePost);
		printf("Enter Employee Salary: ");
		scanf("%f", &employee.employeeSalary);
		fflush(stdin);
		employee.employeeStatus = 'W';
		fwrite(&employee, sizeof(employee), 1, fpEmployeeDetails);
		printf("\nDo You Want To Save Another Record? \n1. Yes\n2. No\n");
		printf("Enter Your Choice: ");
		scanf("%d", &option);
		fflush(stdin);
	} while (option == 1);
	fclose(fpEmployeeDetails);
}

// ----------------------------------------------------------
int showAllEmployesRecords()
{
	int recordsPrinted = 0;
	struct employeeDetails employee;
	FILE *fpEmployeeDetails;
	fpEmployeeDetails = fopen(FILE_NAME, "r");
	while (fread(&employee, sizeof(employee), 1, fpEmployeeDetails) != '\0')
	{
		printf("\nEmployee Details: \n");
		printf("Employee Id: %s\nPatient Name: %s\n", employee.employeeId, employee.employeeName);
		printf("Employee Post: %s\nEmployee Salary: %.2f\n", employee.employeePost, employee.employeeSalary);
		if (employee.employeeStatus == 'W')
		{
			printf("Employee Status: Working\n");
		}
		else if (employee.employeeStatus == 'N')
		{
			printf("Employee Status: Not Working\n");
		}
		recordsPrinted = 1;
	};
	if (recordsPrinted != 1)
	{
		printf("\nNo Records Found.\n");
	}
	fclose(fpEmployeeDetails);
}

// -----------------------------------------
int updateEmployeeRecord()
{
	struct employeeDetails employee;
	int compareValue, recordUpdated = 0;
	char givenEmployeeId[EMPLOYEE_ID_LENGTH];
	printf("\nEnter Employee Id:");
	scanf("%s", givenEmployeeId);
	fflush(stdin);
	FILE *fpEmployeeDetails;
	fpEmployeeDetails = fopen(FILE_NAME, "r+");
	while(fread(&employee, sizeof(employee), 1, fpEmployeeDetails) != '\0')
	{
		compareValue = strcmp(givenEmployeeId, employee.employeeId);
		if (compareValue == 0)
		{	
			int option;
			printf("\nEmployee Details: \n");
			printf("Employee Name: %s\nEmployee Post: %s\n", employee.employeeName, employee.employeePost);
			printf("Salary: %.2f\n", employee.employeeSalary);
			do
			{
				printf("\nWhat Do You Want To Update?\n");
				printf("1. Employee Name\n2. Employee Post\n3. Employee Salary\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
				switch (option)
				{
					case 1:
						printf("\nEnter Employee Name: ");
						fgets(employee.employeeName, EMPLOYEE_NAME_LENGTH, stdin);
						removeNewLine(employee.employeeName);
						break;
					case 2:
						printf("\nEnter Employee Post: ");
						fgets(employee.employeePost, EMPLOYEE_POST_LENGTH, stdin);
						removeNewLine(employee.employeePost);
						break;
					case 3:
						printf("\nEnter Salary: ");
						scanf("%f", &employee.employeeSalary);
						fflush(stdin);
						break;
				}
				printf("\nDo You Want To Update Any More?\n1. Yes\n2. No\n");
				printf("Choose An Option: ");
				scanf("%d", &option);
				fflush(stdin);
			} while (option == 1);
			fseek(fpEmployeeDetails, -sizeof(employee), SEEK_CUR);
			fwrite(&employee, sizeof(employee), 1, fpEmployeeDetails);
			printf("\nRecord Updated.\n");
			recordUpdated = 1;
			break;
		}
	};
	if (recordUpdated != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpEmployeeDetails);
}

// -------------------------------------------
int closeEmployeeRecord()
{
	struct employeeDetails employee;
	int compareValue, recordClosed = 0;
	char givenEmployeeId[EMPLOYEE_ID_LENGTH];
	printf("Enter Employee Id:");
	scanf("%s", givenEmployeeId);
	fflush(stdin);
	FILE *fpEmployeeDetails;
	fpEmployeeDetails = fopen(FILE_NAME, "r+");
	while(fread(&employee, sizeof(employee), 1, fpEmployeeDetails) != '\0')
	{
		compareValue = strcmp(givenEmployeeId, employee.employeeId);
		if (compareValue == 0)
		{	
			employee.employeeStatus = 'N';
			fseek(fpEmployeeDetails, -sizeof(employee), SEEK_CUR);
			fwrite(&employee, sizeof(employee), 1, fpEmployeeDetails);
			printf("\nRecord Closed.\n");
			recordClosed = 1;
			break;
		}
	};
	if (recordClosed != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpEmployeeDetails);
}
// ---------------------------------------
int searchEmployeeRecord()
{
	struct employeeDetails employee;
	int compareValue, matchFound = 0;
	char givenEmployeeId[EMPLOYEE_ID_LENGTH];
	printf("Enter Employee Id:");
	scanf("%s", givenEmployeeId);
	fflush(stdin);
	FILE *fpEmployeeDetails;
	fpEmployeeDetails = fopen(FILE_NAME, "r");
	while(fread(&employee, sizeof(employee), 1, fpEmployeeDetails) != '\0')
	{
		compareValue = strcmp(givenEmployeeId, employee.employeeId);
		if (compareValue == 0)
		{
			printf("\nEmployee Details: \n");
			printf("Employee Id: %s\nEmployee Name: %s\n", employee.employeeId, employee.employeeName);
			printf("Employee Post: %s\nEmployee Salary: %.2f\n", employee.employeePost, employee.employeeSalary);
			if (employee.employeeStatus == 'W')
			{
				printf("Employee Status: Working\n");
			}
			else if (employee.employeeStatus == 'N')
			{
				printf("Employee Status: Not Working\n");
			}
			matchFound = 1;
			break;
		}
	};
	if (matchFound != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpEmployeeDetails);
}
*/





