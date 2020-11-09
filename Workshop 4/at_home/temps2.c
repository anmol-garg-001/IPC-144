//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Workshop:       4 (at_home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define SIZE 10

int main()
{
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	int n, high[SIZE], low[SIZE], i, highestTemp = -99, lowestTemp = 99, dayHighestTemp = -1, dayLowestTemp = -1, search;
	double totalTemp = 0, avgTemp = 0;

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

		if (high[i] > highestTemp)
		{
			highestTemp = high[i];
			dayHighestTemp = i + 1;
		}
		if (low[i] < lowestTemp)
		{
			lowestTemp = low[i];
			dayLowestTemp = i + 1;
		}
	}
	printf("\n\nThe highest temperature was %d, on day %d\n", highestTemp, dayHighestTemp);
	printf("The lowest temperature was %d, on day %d\n", lowestTemp, dayLowestTemp);

	do
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", n);
		scanf("%d", &search);
		if (search < 0)
			break;
		else
		{
			totalTemp = 0, avgTemp = 0;
			while (search<1 || search>n)
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", n);
				scanf("%d", &search);
			}
			for (i = 0; i < search; i++)
			{
				totalTemp += (double)high[i] + low[i];
			}
			avgTemp = totalTemp / ((double)search * 2);
			printf("\nThe average temperature up to day %d is: %.2lf\n", search, avgTemp);
		}
	} while (search >= 0);

	printf("\nGoodbye!\n");
	return 0;
}