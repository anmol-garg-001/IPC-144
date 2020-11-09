//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>
int main(void)
{
	double cash;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &cash);

	double gst = cash * 0.13 + 0.005;
	double total = cash + gst;
	printf("GST: %.2lf\n", gst);
	printf("Balance owing: $%.2f\n", total);

	int cents = (int)(total * 100);

	int loonies = cents / 100;
	int intBalance = cents % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)intBalance / 100);

	int quarters = intBalance / 25;
	intBalance = intBalance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)intBalance / 100);

	int dims = intBalance / 10;
	intBalance = intBalance % 10;
	printf("Dimes required: %d, balance owing $%1.2lf\n", dims, (float)intBalance / 100);

	int nickels = intBalance / 5;
	intBalance = intBalance % 5;
	printf("Nickels required: %d, balance owing $%1.2lf\n", nickels, (float)intBalance / 100);

	int pennies = intBalance / 1;
	intBalance = intBalance % 1;
	printf("Pennies required: %d, balance owing $%1.2lf\n", pennies, (float)intBalance / 100);

	return 0;
}
