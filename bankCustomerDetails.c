/*// Read and print bank customer details with structure

#include <stdio.h>
#include "removeNewLine.c"
#define CUSTOMER_ACCOUNT_NUMBER_LENGTH 14
#define CUSTOMER_NAME_LENGTH 25
#define CUSTOMER_AADHAAR_NUMBER_LENGTH 14
#define CUSTOMER_PHONE_NUMBER_LENGTH 12
#define CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRES customers[customerCounter].customerAccountNumber
#define CURRENT_CUSTOMER_NAME_ADDRESS customers[customerCounter].customerName
#define CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS customers[customerCounter].customerAadhaarNumber
#define CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS customers[customerCounter].customerPhoneNumber
#define CURRENT_CUSTOMER_BALANCE_ADDRESS customers[customerCounter].customerBalance
struct customerDetails
{
	char customerAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	char customerName[CUSTOMER_NAME_LENGTH];
	char customerPhoneNumber[CUSTOMER_PHONE_NUMBER_LENGTH];
	char customerAadhaarNumber[CUSTOMER_AADHAAR_NUMBER_LENGTH];
	float customerBalance;
};
int main()
{
	int customerCounter, customersCount;
	printf("How many customers details do you want to enter? ");
	scanf("%d", &customersCount);
	fflush(stdin);
	struct customerDetails customers[customersCount];
	for (customerCounter = 0; customerCounter < customersCount; customerCounter++)
	{
		printf("\nEnter the details of customer %d of %d: \n", customerCounter + 1, customersCount);
		printf("Enter customer Account Number: ");
		fgets(CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRES, CUSTOMER_ACCOUNT_NUMBER_LENGTH, stdin);
		removeNewLine(CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRES);
		printf("Enter customer name: ");
		fgets(CURRENT_CUSTOMER_NAME_ADDRESS, CUSTOMER_NAME_LENGTH, stdin);
		removeNewLine(CURRENT_CUSTOMER_NAME_ADDRESS);
		printf("Enter customer aadhaar number: ");
		fgets(CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS, CUSTOMER_ADHAR_NUMBER_LENGTH, stdin);
		removeNewLine(CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS);
		printf("Enter customer phone number: ");
		fgets(CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS, CUSTOMER_PHONE_NUMBER_LENGTH, stdin);
		removeNewLine(CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS);
		printf("Enter customer balance: ");
		scanf("%f", &CURRENT_CUSTOMER_BALANCE_ADDRESS);
		fflush(stdin);
	}
	printf("\n\nEntered customer details: ");
	for (customerCounter = 0; customerCounter < customersCount; customerCounter++)
	{
		printf("\nDetails of customer %d:\n", customerCounter + 1);
		printf("Account number: %s\nCustomer name: %s\n", CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRES, CURRENT_CUSTOMER_NAME_ADDRESS);
		printf("Aadhaar number: %s\nPhone number: %s\n", CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS, CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS);
		printf("Current balance: %.2f\n", CURRENT_CUSTOMER_BALANCE_ADDRESS);
	}
}
*/



// Read and print bank customer details

#include <stdio.h>
#include "removeNewLine.c"
#define CUSTOMER_ACCOUNT_NUMBER_LENGTH 13
#define CUSTOMER_NAME_LENGTH 25
#define CUSTOMER_AADHAAR_NUMBER_LENGTH 13
#define CUSTOMER_PHONE_NUMBER_LENGTH 11
#define CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRESS customers[customerCounter].customerAccountNumber
#define CURRENT_CUSTOMER_NAME_ADDRESS customers[customerCounter].customerName
#define CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS customers[customerCounter].customerAadhaarNumber
#define CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS customers[customerCounter].customerPhoneNumber
#define CURRENT_CUSTOMER_BALANCE_ADDRESS customers[customerCounter].customerBalance
struct customerDetails
{
	char customerAccountNumber[CUSTOMER_ACCOUNT_NUMBER_LENGTH];
	char customerName[CUSTOMER_NAME_LENGTH];
	char customerAadhaarNumber[CUSTOMER_AADHAAR_NUMBER_LENGTH];
	char customerPhoneNumber[CUSTOMER_PHONE_NUMBER_LENGTH];
	float customerBalance;
};
int main()
{
	int customerCounter, customersCount;
	printf("How many customers details do you want to enter? ");
	scanf("%d", &customersCount);
	fflush(stdin);
	struct customerDetails customers[customersCount];
	for (customerCounter = 0; customerCounter < customersCount; customerCounter++)
	{
		printf("\nEnter the details of customer %d of %d: \n", customerCounter + 1, customersCount);
		printf("Enter customer Account Number: ");
		scanf("%s", CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRESS);
		fflush(stdin);
		printf("Enter customer name: ");
		fgets(CURRENT_CUSTOMER_NAME_ADDRESS, CUSTOMER_NAME_LENGTH, stdin);
		removeNewLine(CURRENT_CUSTOMER_NAME_ADDRESS);
		printf("Enter customer aadhaar number: ");
		scanf("%s", CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS);
		fflush(stdin);
		printf("Enter customer phone number: ");
		scanf("%s", CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS);
		fflush(stdin);
		printf("Enter customer balance: ");
		scanf("%f", &CURRENT_CUSTOMER_BALANCE_ADDRESS);
		fflush(stdin);
	}
	printf("\n\nEntered customer details: ");
	for (customerCounter = 0; customerCounter < customersCount; customerCounter++)
	{
		printf("\nDetails of customer %d:\n", customerCounter + 1);
		printf("Account number: %s\nCustomer name: %s\n", CURRENT_CUSTOMER_ACCOUNT_NUMBER_ADDRESS, CURRENT_CUSTOMER_NAME_ADDRESS);
		printf("Aadhaar number: %s\nPhone number: %s\n", CURRENT_CUSTOMER_AADHAAR_NUMBER_ADDRESS, CURRENT_CUSTOMER_PHONE_NUMBER_ADDRESS);
		printf("Current balance: %.2f\n", CURRENT_CUSTOMER_BALANCE_ADDRESS);
	}
}