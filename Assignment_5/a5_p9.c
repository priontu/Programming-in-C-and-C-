/*
    CH-230-A
    a5_p9.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void readMatrix(int ***mat, int x, int y, int z) //Reading matrix elements from standard input.
{
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            for (int k = 0; k < z; k++)
                scanf("%d", &mat[i][j][k]);
}

void printMatrix(int ***matrix, int x, int y, int z) //Printing the matrix section by section.
{
    for (int k = 0; k < z; k++)
    {
        printf("Section %d:\n", k + 1);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int lenx, leny, lenz;

    scanf("%d", &lenx);
    scanf("%d", &leny);
    scanf("%d", &lenz);
    //Dynamic Memory Allocation:
    int ***matrix = (int ***)malloc(lenx * sizeof(int **));
    if (matrix == NULL)
        exit(1);
    for (int i = 0; i < lenx; i++)
    {
        matrix[i] = (int **)malloc(leny * sizeof(int *));
        if (matrix[i] == NULL)
            exit(1);
        for (int j = 0; j < leny; j++)
        {
            matrix[i][j] = (int *)malloc(lenz * sizeof(int *));
            if (matrix[i][j] == NULL)
                exit(1);
        }
    }
    //Reading values and printing them in sections:
    readMatrix(matrix, lenx, leny, lenz);
    printMatrix(matrix, lenx, leny, lenz);

    //De-allocating memory:
    for (int i = 0; i < lenx; i++)
    {
        for (int j = 0; j < leny; j++)
            free(matrix[i][j]);
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}