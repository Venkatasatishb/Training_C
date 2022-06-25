// Save and show Bank customers details

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define CUSTOMER_ACCOUNT_NUMBER_LENGTH 13
#define CUSTOER_NAME_LENGTH 25
#define CUSTOMER_AADHAAR_LENGTH 13
#define CUSTOMER_PHONE_NUMBER_LENGTH 11
#define FILE_NAME "customersDetails.dat"
struct customerDetails
{
	char customerAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	char customerName[CUSTOER_NAME_LENGTH];
	char customerGender;
	char customerAadhaarNumber[CUSTOMER_AADHAAR_LENGTH];
	char customerPhoneNumber[CUSTOMER_PHONE_NUMBER_LENGTH];
	float customerBalance;

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
	printf("\n1. Save Customer Record\n2. Show All Customers Records\n3. Clear All Customers Records\n4. Search Customer Record\n5. Delete Customer Record\n6. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveCustomerRecord();
			break;
		case 2:
			showAllCustomersRecords();
			break;
		case 3:
			clearAllCustomersRecords();
			break;
		case 4:
			searchCustomerRecord();
			break;
		case 5:
			updateCustomerRecord();
			break;
		case 6:
			exit(0);
		default:
			printf("\nChoice the correct option");
	}
	return choice;
}

int saveCustomerRecord()
{
	int choice;
	struct customerDetails customer;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "a");
	do
	{
		printf("\nEnter the customer details:\n");
		printf("Enter Customer's Account Number: ");
		scanf("%s", customer.customerAccountNumber);
		fflush(stdin);
		printf("Enter Customer's Name: ");
		fgets(customer.customerName, CUSTOER_NAME_LENGTH, stdin);
		removeNewLine(customer.customerName);
		printf("Enter Customer's Gender (M/F): ");
		scanf("%c",&customer.customerGender);
		fflush(stdin);
		printf("Enter Customer's Aadhaar Number: ");
		scanf("%s", customer.customerAadhaarNumber);
		fflush(stdin);
		printf("Enter Customer's Phone Number: ");
		scanf("%s", customer.customerPhoneNumber);
		fflush(stdin);
		printf("Enter Customer's Balance: ");
		scanf("%f", &customer.customerBalance);
		fflush(stdin);
		fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		printf("\nDo you want to add another record? ");
		printf("\n1. Yes\n2. No\nEnter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
	fclose(fpCustomerDetails);
}

int showAllCustomersRecords()
{
	struct customerDetails customer;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	if (fread(&customer, sizeof(customer), 1, fpCustomerDetails) == '\0')
	{
		printf("\nNo Customer Records Found.\n");
	}
	else 
	{
		do
		{
			printf("\nCustomer Details: \n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf(customer.customerGender == 'M'? "Gender: Male\n" : "Gender: Female\n");
			printf("Aadhaar Number: %s\nPhone Number:%s\n", customer.customerAadhaarNumber, customer.customerPhoneNumber);
			printf("Current Balance: %.2f\n", customer.customerBalance);
		} while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0');
	}
	fclose(fpCustomerDetails);
}


int clearAllCustomersRecords()
{
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "w");
	fclose(fpCustomerDetails);
	printf("\nAll The Records Are Cleared\n");
}

/*int searchCustomerRecord()
{
	int compareValue;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	struct customerDetails customer;
	char searchAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	printf("Enter a account number: ");
	scanf("%s", searchAccountNumber);
	fflush(stdin);
	if (fread(&customer, sizeof(customer), 1, fpCustomerDetails) == '\0')
	{
		printf("\nNo Customer Records Found\n");
		return 0;
	}
	else
	{
		do
		{
			compareValue = strcmp(searchAccountNumber, customer.customerAccountNumber);
			if (compareValue == 0)
			 {
			 	printf("\nRecord Found\n");
			 	printf("\nCustomer Details: \n");
				printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
				printf("Current Balance: %.2f\n", customer.customerBalance);
				return 0;
			 } 
		} while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0');
	}
	if (fread(&customer, sizeof(customer), 1, fpCustomerDetails) == '\0')
	{
		printf("\nRecord Not Found\n");
	}
	fclose(fpCustomerDetails);
}*/

/*int searchCustomerRecord()
{
	int compareValue;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	struct customerDetails customer;
	char searchAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	printf("Enter a account number: ");
	scanf("%s", searchAccountNumber);
	fflush(stdin);
	while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0')
	{
		compareValue = strcmp(searchAccountNumber, customer.customerAccountNumber);
		if (compareValue == 0)
		 {
		 	printf("\nRecord Found\n");
		 	printf("\nCustomer Details: \n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf("Current Balance: %.2f\n", customer.customerBalance);
			fclose(fpCustomerDetails);
			return 0;
		 } 
	};
	printf("\nRecord Not Found\n");
	fclose(fpCustomerDetails);
}*/

int searchCustomerRecord()
{
	int compareValue,searchValue;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	struct customerDetails customer;
	char searchAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	printf("Enter a account number: ");
	scanf("%s", searchAccountNumber);
	fflush(stdin);
	while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0')
	{
		compareValue = strcmp(searchAccountNumber, customer.customerAccountNumber);
		if (compareValue == 0)
		 {
		 	printf("\nRecord Found\n");
		 	printf("\nCustomer Details: \n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf("Current Balance: %.2f\n", customer.customerBalance);
			searchValue = 0;
			break;
		 } 
	};
	if (searchValue != 0)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpCustomerDetails);
}

int updateCustomerRecord()
{
	int compareValue, recordUpdated = 0;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r+");
	struct customerDetails customer;
	char givenAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	printf("Enter a account number: ");
	scanf("%s", givenAccountNumber);
	fflush(stdin);
	while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0')
	{
		compareValue = strcmp(givenAccountNumber, customer.customerAccountNumber);
		if (compareValue == 0)
		 {
		 	printf("\nEnter the customer details:\n");
			printf("Enter Customer's Name: ");
			fgets(customer.customerName, CUSTOER_NAME_LENGTH, stdin);
			removeNewLine(customer.customerName);
			printf("Enter Customer's Gender (M/F): ");
			scanf("%c", &customer.customerGender);
			fflush(stdin);
			printf("Enter Customer's Aadhaar Number: ");
			scanf("%s", customer.customerAadhaarNumber);
			fflush(stdin);
			printf("Enter Customer's Phone Number: ");
			scanf("%s", customer.customerPhoneNumber);
			fflush(stdin);
			printf("Enter Customer's Balance: ");
			scanf("%f", &customer.customerBalance);
			fflush(stdin);
		 	fseek(fpCustomerDetails, -sizeof(customer), SEEK_CUR);
		 	fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		 	recordUpdated = 1;
		 	break;
		 }
	};
	if (recordUpdated == 0)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpCustomerDetails);
}

/*compareStrings(char *string1, char *string2)
{
	int i = 0, k = 0;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] != string2[i])
		{
			k = 1;
			return k;
		}
			i++;
	}
	return k;
}
*/

/*//Save and Show Bank customer details 

#include <stdio.h>
#include <stdlib.h>
#include "removeNewLine.c"
#define CUSTOMER_ACCOUNT_NUMBER_LENGTH 13
#define CUSTOMER_NAME_LENGTH 25
#define CUSTOMER_AADHAAR_LENGTH 13
#define CUSTOMER_PHONE_NUMBER_LENGTH 11
#define FILE_NAME "customerDetails.dat"

struct customerDetails
{
	char customerAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	char customerName[CUSTOMER_NAME_LENGTH];
	char customerAadhaarNumber[CUSTOMER_AADHAAR_LENGTH];
	char customerPhoneNumber[CUSTOMER_PHONE_NUMBER_LENGTH];
	float customerBalance;
};
int main()
{
	int choice;
	do
	{
		choice = showMenu();
	} while (choice != 4);
}

int showMenu()
{
	int choice;
	printf("\n1. Save Record\n2. Show Records\n3. Clear Records\n4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	fflush(stdin);
	switch (choice)
	{
		case 1:
			saveRecord();
			break;
		case 2:
			showRecords();
			break;
		case 3:
			clearRecords();
			break;
		case 4:
			exit(0);
	}
	return choice;
}
int saveRecord()
{
	int choice;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "a");
	do
	{
		struct customerDetails customer;
		printf("\nEnter customer details: \n");
		printf("Enter customer account number: ");
		scanf("%s", customer.customerAccountNumber);
		fflush(stdin);
		printf("Enter customer name: ");
		fgets(customer.customerName, CUSTOMER_NAME_LENGTH, stdin);
		removeNewLine(customer.customerName);
		printf("Enter customer aadhaar number: ");
		scanf("%s", customer.customerAadhaarNumber);
		fflush(stdin);
		printf("Enter customer phone number: ");
		scanf("%s", customer.customerPhoneNumber);
		fflush(stdin);
		printf("Enter customer balance:");
		scanf("%f", &customer.customerBalance);
		fflush(stdin);
		fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		printf("\nDo you want to add another record? \n1. Yes\n2. No\n");
		printf("Enter you choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
	fclose(fpCustomerDetails);
}

int showRecords()
{
	struct customerDetails customer;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	if (fread(&customer, sizeof(customer), 1, fpCustomerDetails) == '\0')
	{
		printf("\nFile is empty\n");
	}
	else
	{
		do 
		{
			printf("\nCustomer Details:\n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf("Aadhaar Number: %s\nPhone Number: %s\n", customer.customerAadhaarNumber, customer.customerPhoneNumber);
			printf("Current Balance: %.2f\n", customer.customerBalance);
		}while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0');
	}
	fclose(fpCustomerDetails);
}

int clearRecords()
{
	FILE *fpCustomerDetails = fopen(FILE_NAME, "w");
	fclose(fpCustomerDetails);
}*/