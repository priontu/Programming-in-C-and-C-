/*
    CH-230-A
    a5_p2.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>

void divby5(float arr[], int size)
{
    float *arrPtr = &arr[0]; //Reference to location.
    for (int i = 0; i < size; i++)
    {
        *(arrPtr + i) = (*(arrPtr + i)) / 5; //Divides every number by 5.
    }
}

int main()
{
    float floatArray[] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};

    int size = (int)sizeof(floatArray) / sizeof(float);

    printf("Before:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ", floatArray[i]); //prints all numbers before function execution.
    }

    divby5(floatArray, size);

    printf("\nAfter:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%.3f ", floatArray[i]); //prints all numbers after function execution.
    }
    printf("\n");

    return 0;
}