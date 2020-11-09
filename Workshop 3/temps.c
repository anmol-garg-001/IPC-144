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
#define NUMS 3
int main(void)
{
    printf("---=== IPC Temperature Analyzer ===---\n");
    int i,high,low;
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

        }while(high>40||low<-40||high<low);
        
    }
    
    return 0;
}