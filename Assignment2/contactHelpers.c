//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Date:           18th March, 2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

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
	int choice;

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

	choice = getIntInRange(0, 6);// It will return a valid integer value b/w 0 and 6

	return choice;
}

// contactManagerSystem: Function definition goes here:
void contactManagerSystem(void)
{
	int choice, exit = 0, isYes;

	do
	{
		choice = menu();// It will return the valid choice entered by the user

		switch (choice)
		{
		case 1:
			printf("\n<<< Feature 1 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 2:
			printf("\n<<< Feature 2 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("\n<<< Feature 3 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("\n<<< Feature 4 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("\n<<< Feature 5 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 6:
			printf("\n<<< Feature 6 is unavailable >>>\n\n");
			pause();
			printf("\n");
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			isYes = yes();// It will return the choice of the user( 1 for yes and 0 for no )

			if (isYes)
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
