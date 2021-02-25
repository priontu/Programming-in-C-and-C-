/*
    CH-230-A
    a5_p6.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int n; //Taking inputs
    scanf("%d", &n);
    float values[n];
    float *valPtr = &values[0];
    int position;

    for (int i = 0; i < n; i++)
    {
        scanf("%f", valPtr + i);
    }
    for (int i = 0; !(*(valPtr + i) < 0); i++) //Loop runs until first negative value.
    {
        position = i; //Position of last positive value.
    }
    printf("Before the first negative value: %d elements", position + 1); //Rectifying for differences in position and number of elements.

    return 0;
}