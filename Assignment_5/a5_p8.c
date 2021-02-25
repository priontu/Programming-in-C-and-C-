/*
    CH-230-A
    a5_p8.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Reading elements of the matrix:
void readMatrix(int **mat, int row, int col)
{
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            scanf("%d", &mat[r][c]);
}

//Calculating matrix product:
void matrixProduct(int **matA, int **matB, int **matAxB, int n, int m, int p)
{
    int sum = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < p; c++)
        {
            for (int k = 0; k < m; k++)
            {
                sum += matA[r][k] * matB[k][c];
            }
            matAxB[r][c] = sum;
            sum = 0;
        }
    }
}

//Outputting the data in matrix form:
void printMatrix(int **mat, int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        for (int c = 0; c < col; c++)
        {
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}

int main()
{
    /*-----Dynamic Memory Allocation-----*/
    int **matrixA, **matrixB, **matrixAxB, n, m, p;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &p);
    matrixA = (int **)malloc(n * sizeof(int *));
    matrixB = (int **)malloc(m * sizeof(int *));
    matrixAxB = (int **)malloc(n * sizeof(int *));

    if (matrixA == NULL ||
        matrixB == NULL ||
        matrixAxB == NULL)
    {
        exit(1); //Exit program if empty.
    }

    for (int r = 0; r < n; r++)
    {
        matrixA[r] = (int *)malloc(m * sizeof(int));
        if (matrixA[r] == NULL)
            exit(1);
    }
    for (int r = 0; r < m; r++)
    {
        matrixB[r] = (int *)malloc(p * sizeof(int));
        if (matrixB[r] == NULL)
            exit(1);
    }
    for (int r = 0; r < n; r++)
    {
        matrixAxB[r] = (int *)malloc(p * sizeof(int));
        if (matrixAxB[r] == NULL)
        {
            exit(1);
        }
    }
    /*-----End of Memory Allocation-----*/

    //Reading values into matrices:
    readMatrix(matrixA, n, m);
    readMatrix(matrixB, m, p);
    matrixProduct(matrixA, matrixB, matrixAxB, n, m, p);

    //Printing in matrix form:
    printf("Matrix A:\n");
    printMatrix(matrixA, n, m);

    printf("Matrix B:\n");
    printMatrix(matrixB, m, p);

    printf("The multiplication result AxB:\n");
    printMatrix(matrixAxB, n, p);

    //De-allocating memory:
    for (int r = 0; r < n; r++)
        free(matrixA[r]);
    for (int r = 0; r < m; r++)
        free(matrixB[r]);
    for (int r = 0; r < n; r++)
        free(matrixAxB);

    free(matrixA);
    free(matrixB);
    free(matrixAxB);

    return 0;
}