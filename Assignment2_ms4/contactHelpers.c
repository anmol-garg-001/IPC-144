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
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <ctype.h>
#include <string.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"
#include "contacts.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: Function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Function definition goes here:
int getInt(void)
{
	int inputValue;
	char newLine = 'x';

	// The do-while loop will not let the user exit the loop until a valid input is entered
	do
	{
		scanf("%d%c", &inputValue, &newLine);

		if (newLine != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (newLine != '\n');

	return inputValue;
}

// getIntInRange: Function definition goes here:
int getIntInRange(int min, int max)
{
	int inputValue;

	// The do-while loop will not let the user exit the loop until a valid input is entered b/w min & max
	do
	{
		inputValue = getInt();// It will return a valid integer value

		if (inputValue < min || inputValue > max)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}

	} while (inputValue < min || inputValue > max);

	return inputValue;
}

// yes: Function definition goes here:
int yes(void)
{
	int isYes;
	char inputValue, newLine = 'x';

	// The do-while loop will not let the user exit the loop until a valid input is entered
	do
	{
		scanf("%c%c", &inputValue, &newLine);

		if (newLine != '\n' || (inputValue != 'Y' && inputValue != 'y' && inputValue != 'N' && inputValue != 'n'))
		{
			if (newLine != '\n')
				clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}

	} while (newLine != '\n' || (inputValue != 'Y' && inputValue != 'y' && inputValue != 'N' && inputValue != 'n'));

	if (inputValue == 'Y' || inputValue == 'y')
		isYes = 1;
	else
		isYes = 0;

	return isYes;
}

// menu: Function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);// It will return a valid integer value b/w 0 and 6
}

// contactManagerSystem: Function definition goes here:
void contactManagerSystem(void)
{
	int choice, exit = 0;

	struct Contact contact[MAXCONTACTS] = {
								{
								   {"Rick", {'\0'}, "Grimes"},
								   {11, "Trailer Park", 0, "A7A 2J2", "King City"},
								   {"4161112222", "4162223333", "4163334444"}
								},
								{
								   {"Maggie", "R.", "Greene"},
								   {55, "Hightop House", 0, "A9A 3K3", "Bolton"},
								   {"9051112222", "9052223333", "9053334444"}
								},
								{
									{"Morgan", "A.", "Jones"},
									{77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"},
									{"7051112222", "7052223333", "7053334444"}
								},
								{
									{"Sasha", {'\0'}, "Williams"},
									{55, "Hightop House", 0, "A9A 3K3", "Bolton"},
									{"9052223333", "9052223333", "9054445555"}
								},
	};

	do
	{
		choice = menu();// It will return the valid choice entered by the user

		switch (choice)
		{
		case 1:  //<---Display Contacts 
			displayContacts(contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:  //<---Add a contact
			addContact(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 3:  //<---Update a contact
			updateContact(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 4: //<---Delete a contact
			deleteContact(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 5:  //<--Search contacts by cell phone number
			searchContacts(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 6:  //<--Sort Contacts
			sortContacts(contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 0:  //<--Exit the application
			printf("\nExit the program? (Y)es/(N)o: ");

			if (yes())
			{
				exit = 1;
				printf("\nContact Management System: terminated");
			}

			printf("\n");
			break;

		default:
			break;
		}
	} while (!exit);
}

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int i, needInput = 1, phoneLength = 0;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		phoneLength = strlen(phoneNum);

		// (String Length Function: validate entry of 10 characters)
		if (phoneLength == 10)
		{
			for (i = 0; i < phoneLength; i++)
			{
				if (!isdigit(phoneNum[i]))
				{
					needInput = 1;
					i = phoneLength; // To stop iterating the loop further if there is any character other than a digit
				}
				else
				{
					needInput = 0;
				}
			}
		}

		if (needInput == 1)
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, contactIndex = -1;

	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			contactIndex = i;
			i = size;
		}
	}

	return contactIndex;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
	char fullName[75] = { '\0' };

	// Full name
	if (strlen(contact->name.firstName) != 0)
	{
		strcat(fullName, contact->name.firstName);

		if (strlen(contact->name.middleInitial) != 0)
		{
			strcat(fullName, " ");
			strcat(fullName, contact->name.middleInitial);
		}

		strcat(fullName, " ");
		strcat(fullName, contact->name.lastName);

		printf(" %s\n", fullName);
		printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
		printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

		if (contact->address.apartmentNumber > 0)
		{
			printf("Apt# %d, ", contact->address.apartmentNumber);
		}

		printf("%s, %s\n", contact->address.city, contact->address.postalCode);
	}
}

// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
	printf("\n");
	displayContactHeader();

	int i;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}

	displayContactFooter(count);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	char numSearch[11] = { '\0' };
	int contactIndex = -1;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(numSearch);

	contactIndex = findContactIndex(contacts, size, numSearch);

	if (contactIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\n");
		displayContact(&contacts[contactIndex]);
	}
}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
	int contactIndex = -1;

	contactIndex = findContactIndex(contacts, size, ""); //Find index of the empty slot

	if (contactIndex == -1)
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		printf("\n");
		getContact(&contacts[contactIndex]);
		printf("--- New contact added! ---\n");
	}
}

// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
	char numSearch[11] = { '\0' };
	int contactIndex = -1;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(numSearch);
	contactIndex = findContactIndex(contacts, size, numSearch);

	if (contactIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[contactIndex]);

		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[contactIndex].name);
		}

		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[contactIndex].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[contactIndex].numbers);
		}

		printf("--- Contact Updated! ---\n");
	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
	char numSearch[11] = { '\0' };
	int contactIndex = -1;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(numSearch);
	contactIndex = findContactIndex(contacts, size, numSearch);

	if (contactIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[contactIndex]);

		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes())
		{
			strcpy(contacts[contactIndex].numbers.cell, ""); //Set contact cell phone number to a empty slot
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j, swapIndex;
	struct Contact tempContact = { { { 0 } } };

	for (i = 0; i < size - 1; i++) // Used i < size - 1 because it will end the loop after comparing the 2nd last contact with the last contact
	{
		swapIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0)
			{
				swapIndex = j;
			}
		}
		if (swapIndex != i)
		{
			//swapping the contacts
			tempContact = contacts[i];
			contacts[i] = contacts[swapIndex];
			contacts[swapIndex] = tempContact;
		}
	}

	printf("\n--- Contacts sorted! ---\n");
}
