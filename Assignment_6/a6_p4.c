/*
    CH-230-A
    a6_p4.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>

int main()
{
    int n;
    int sum = 0;
    scanf("%d", &n);

    int x[n], y[n], inter[n];
    //Taking inputs:
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (int k = 0; k < n; k++)
        scanf("%d", &y[k]);
    //Preprocessing conditions:
    #ifdef INTERMEDIATE
        printf("The intermediate product values are:\n");
    #endif
    //Products are outputted only if INTERMEDIATE is defined:
    for (int j = 0; j < n; j++)
    {
        inter[j] = x[j] * y[j];
        sum += inter[j];
        #ifdef INTERMEDIATE
            printf("%d\n", inter[j]);
        #endif
    }
    //Scalar product is outputted:
    printf("The scalar product is: %d\n", sum);
    return 0;
}