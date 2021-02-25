/*
    CH-230-A
    a5_p11.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>

int findPrime(int n, int i) //Finding the prime.
{
    if (i == 1)
    {
        return 1;
    }
    else
    {
        if (n == 1 || n % i == 0)
        {
            return 0;
        }
        else
        {
            return findPrime(n, i - 1);
        }
    }
}

int main()
{
    int x;
    scanf("%d", &x); //Taking input.

    int checker;
    checker = findPrime(x, x / 2);

    if (checker == 1) //Conditional output.
    {
        printf("%d is prime\n", x);
    }
    else
    {
        printf("%d is not prime\n", x);
    }

    return 0;
}