/*
    CH-230-A
    a5_p4.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
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
    int n;
    scanf("%d", &n);

    float *floatArray = (float *)malloc(n * sizeof(float));
    if (floatArray == NULL)
        exit(1);

    int size = n;

    for (int i = 0; i < n; i++)
    {
        scanf("%f", floatArray + i);
    }

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

    free(floatArray);

    return 0;
}