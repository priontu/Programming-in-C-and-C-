/*
    CH-230-A
    a5_p7.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *first = (char *)malloc(100 * sizeof(char)); //Dynamic memory allocation for input values.
    if (first == NULL)
        exit(1);
    fgets(first, 100 * sizeof(char), stdin); //Inputting first line.

    char *second = (char *)malloc(100 * sizeof(char));
    if (second == NULL)
        exit(1);
    fgets(second, 100 * sizeof(char), stdin);

    char *result = (char *)malloc(200 * sizeof(char)); //Dynamic memory allocation for result.
    if (result == NULL)
        exit(1);

    for (int i = 0; *(first + i) != '\n'; i++)
    {
        *(result + i) = *(first + i); //Copying all characters before newline.
    }
    strcat(result, second); //Copying the rest.

    printf("Result of concatenation: %s", result);

    free(first);
    free(second);
    free(result);
    return 0;
}