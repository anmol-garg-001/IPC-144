//==============================================
// Name:           Anmol Garg
// Student Number: 1499161999
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Date:           28, July 2020     
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"


// getName:
void getName(struct Name* name)
{
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	clearKeyboard();//Clears the input buffer

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		clearKeyboard();//Clears the input buffer
	}
	else
	{
		strcpy(name->middleInitial,"");
	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	clearKeyboard();//Clears the input buffer
}

// getAddress:
void getAddress(struct Address* address)
{
	printf("Please enter the contact's street number: ");
	do
	{
		address->streetNumber = getInt();
		if (address->streetNumber < 1)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
	} while (address->streetNumber < 1);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]", address->street);
	clearKeyboard();//Clears the input buffer

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes())
	{
		printf("Please enter the contact's apartment number: ");
		do
		{
			address->apartmentNumber = getInt();
			if (address->apartmentNumber < 1)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
		} while (address->apartmentNumber < 1);
	}
	else
	{
		address->apartmentNumber = 0;
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]", address->postalCode);
	clearKeyboard();//Clears the input buffer

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]", address->city);
	clearKeyboard();//Clears the input buffer
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes())
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}
	else
	{
		strcpy(numbers->home, "");
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes())
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
	{
		strcpy(numbers->business, "");
	}
}

// getContact:
// Define Function definition below:
void getContact(struct Contact* contact)
{
	getName(&(contact->name));
	getAddress(&(contact->address));
	getNumbers(&(contact->numbers));
}