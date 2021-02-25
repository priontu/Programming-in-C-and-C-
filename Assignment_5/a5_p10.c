/*
    CH-230-A
    a5_p10.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) //Calculating factorial.
{
    if (n == 1)
        return n;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n); //Taking inputs.
    printf("%d", factorial(n));

    return 0;
}