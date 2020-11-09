//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
int main(void)
{
	double cash;
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &cash);
	int cents = (int)(cash * 100);

	int loonies = cents / 100;
	int intBalance = cents % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, (double)intBalance/100);

	int quarters = intBalance / 25;
	intBalance = intBalance % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, (double)intBalance/100);

	return 0;
}