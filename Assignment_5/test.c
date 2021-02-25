#include <stdio.h>

// declaring the recursive function
int isPrime(int, int);

int main()
{

    int num, prime;
    scanf("%d", &num);
    prime = isPrime(num, num / 2);
    if (prime == 1)
    {
        printf("%d is prime\n", num);
    }
    else
    {
        printf("%d is not prime\n", num);
    }

    return 0;
}

// function definition
int isPrime(int n, int i)
{
    if (i == 1)
        return 1; // return statement terminates the recursive funtion
    else
    {
        if (n == 1 || n % i == 0)
            return 0;
        else
            isPrime(n, i - 1); // recursive call not using return statement
    }
}