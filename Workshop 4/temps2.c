//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
int main()
{
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	int n, high[10], low[10], i;
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &n);
	while (n < 3 || n > 10)
	{
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n);
	}

	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}
	printf("\nDay  Hi  Low");

	for (i = 0; i < n; i++)
	{
		printf("\n%-5d%-3d%4d", i + 1, high[i], low[i]);
	}
        return 0;
}
