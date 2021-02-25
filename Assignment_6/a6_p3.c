/*
    CH-230-A
    a6_p3.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/
#include <stdio.h>
//Defining parameters:
#define A
#define B
#define C
//Defining logic with macro:
#define MAX(A, B, C) ((A > B) ? ((A > C) ? A : C) : ((B > C) ? B : C))
#define MIN(A, B, C) ((A < B) ? ((A < C) ? A : C) : ((B < C) ? B : C))
#define MID_RANGE(A, B, C) ((MAX(A, B, C) + MIN(A, B, C)) / 2)

int main()
{
    //Taking input:
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    //Executing logic:
    float result;
    result = MID_RANGE((float)a, (float)b, (float)c);
    //Printing the result:
    printf("The mid-range is: %.6f\n", result);

    return 0;
}
