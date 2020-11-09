//==============================================
// Name:           Anmol Garg
// Student Number: 149916199
// Email:          agarg15@myseneca.ca
// Section:        NFF
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4
int main(void)
{
    printf("---=== IPC Temperature Analyzer ===---\n");
    int i,high,low,topHigh=-50,topLow=50,dayTopHigh,dayTopLow;
    double totalHigh=0,totalLow=0;
    for ( i = 0; i < NUMS; i++)
    {
        do
        {
            printf("Enter the high value for day %d: ",i+1);
            scanf("%d",&high);
            printf("\n");
            printf("Enter the low value for day %d: ",i+1);
            scanf("%d",&low);
            printf("\n");

            if (high>40||low<-40||high<low)
            {
                printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
            }

        }
        while(high>40||low<-40||high<low);

        if (high>topHigh)
        {
            topHigh=high;
            dayTopHigh=i+1;
        }
        if (low<topLow)
        {
            topLow=low;
            dayTopLow=i+1;
        }

        totalHigh+=high;
        totalLow+=low;

    }

    double avgLowTemp=totalLow/NUMS;
    double avgHighTemp=totalHigh/NUMS;
    double avgTemp=(avgHighTemp+avgLowTemp)/2;

    printf("The average (mean) LOW temperature was: %.2lf\n",avgLowTemp);
    printf("The average (mean) HIGH temperature was: %.2lf\n",avgHighTemp);
    printf("The average (mean) temperature was: %.2lf\n",avgTemp);

    printf("The highest temperature was %d, on day %d\n",topHigh,dayTopHigh);
    printf("The lowest temperature was %d, on day %d\n",topLow,dayTopLow);
    
    return 0;
}
