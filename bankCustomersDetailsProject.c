// Bank customer details

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTools.c"
#define CUSTOMER_ACCOUNT_NUMBER_LENGTH 13
#define CUSTOMER_NAME_LENGTH 25
#define FILE_NAME "customersDetails.dat"
struct customerDetails
{
	char customerAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	char customerName[CUSTOMER_NAME_LENGTH];
	float customerBalance;
	char customerAccountStatus;
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
	printf("\n1. Save Customer Record\n2. Show All Customers Records\n3. Update Customer Record\n");
	printf("4. Close Customer Record\n5. Search Customer Record\n6. Exit\n");
	printf("Enter Your Choice: ");
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
			updateCustomerRecord();
			break;
		case 4:
			closeCustomerRecord();
			break;
		case 5:
			searchCustomerRecord();
			break;
		case 6:
			exit(0);
		default:
			printf("\nChoose The Correct Option.\n");
	}
	return choice;
}

int saveCustomerRecord()
{
	int choice;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "a");
	struct customerDetails customer;
	do
	{
		printf("\nEnter Customer Details: \n");
		printf("Enter Customer's Account Number: ");
		scanf("%s", customer.customerAccountNumber);
		fflush(stdin);
		printf("Enter Customer's Name: ");
		fgets(customer.customerName, CUSTOMER_NAME_LENGTH, stdin);
		removeNewLine(customer.customerName);
		printf("Enter Customer's Balance: ");
		scanf("%f", &customer.customerBalance);
		fflush(stdin);
		customer.customerAccountStatus = 'A';
		fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		printf("\nDo you want to save another record? \n");
		printf("1. Yes\n2. No\nEnter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);
	} while (choice == 1);
	fclose(fpCustomerDetails);
}

int showAllCustomersRecords()
{
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
	struct customerDetails customer;
	if (fread(&customer, sizeof(customer), 1, fpCustomerDetails) == '\0')
	{
		printf("\nNo Customer Records Found\n");
	}
	else
	{
		do
		{
			printf("\nCustomer Details: \n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf("Current Balance: %.2f\n", customer.customerBalance);
			if (customer.customerAccountStatus == 'A')
			{
				printf("Account Status: Active\n");
			}
			else if (customer.customerAccountStatus == 'C')
			{
				printf("Account Status: Closed\n");
			}
		} while (fread(&customer, sizeof(customer), 1, fpCustomerDetails) != '\0');
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
	 		int option;
			printf("Customer's Name: %s\n", customer.customerName);
			printf("Current Balance: %.2f\n", customer.customerBalance);
		 	do
		 	{
			 	printf("\nWhat Do You Want To Update?\n");
			 	printf("1. Customer's Name\n2. Customer's Balance\n");
			 	printf("Enter Your Choice: ");
			 	scanf("%d", &option);
			 	fflush(stdin);
			 	switch (option)
			 	{
			 		case 1:
						printf("Enter Customer's Name: ");
						fgets(customer.customerName, CUSTOMER_NAME_LENGTH, stdin);
						removeNewLine(customer.customerName);
						break;
					case 2:
						printf("Enter Customer's Balance: ");
						scanf("%f", &customer.customerBalance);
						fflush(stdin);
						break;
			 	}
			 	printf("\nDo You Want To Change Any More? \n1. Yes\n2. No\n");
			 	printf("Enter your Choice: ");
			 	scanf("%d", &option);
			 	fflush(stdin);
		 	} while (option == 1);
		 	fseek(fpCustomerDetails, -sizeof(customer), SEEK_CUR);
		 	fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		 	printf("\nRecord Updated.\n");
		 	recordUpdated = 1;
		 	break;
		 }
	};
	if (recordUpdated != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpCustomerDetails);
}

int closeCustomerRecord()
{
	int compareValue, recordClosed = 0;
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
		 	customer.customerAccountStatus = 'C';
		 	fseek(fpCustomerDetails, -sizeof(customer), SEEK_CUR);
		 	fwrite(&customer, sizeof(customer), 1, fpCustomerDetails);
		 	printf("\nRecord Closed.\n");		
		 	recordClosed = 1;
		 	break;
		 }
	};
	if (recordClosed != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpCustomerDetails);
}

int searchCustomerRecord()
{
	int compareValue, matchFound = 0;
	FILE *fpCustomerDetails;
	fpCustomerDetails = fopen(FILE_NAME, "r");
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
		 	printf("\nRecord Found\n");
		 	printf("\nCustomer Details: \n");
			printf("Account Number: %s\nCustomer Name: %s\n", customer.customerAccountNumber, customer.customerName);
			printf("Current Balance: %.2f\n", customer.customerBalance);
			if (customer.customerAccountStatus == 'A')
			{
				printf("Account Status: Active");
			}
			else if (customer.customerAccountStatus == 'C')
			{
				printf("Account Status: Closed");
			}
			matchFound = 1;
			break;
		 } 
	};
	if (matchFound != 1)
	{
		printf("\nRecord Not Found.\n");
	}
	fclose(fpCustomerDetails);
}
