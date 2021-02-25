/*
    CH-230-A
    a5_p5.c
    Priontu Chowdhury
    p.chowdhury@jacobs-university.de
*/

#include <stdio.h>
#include <math.h>

double scalarProduct(double *v, double *u, int n) //Calculating scalar product.
{
    double product = 0;
    for (int i = 0; i < n; i++)
    {
        product += v[i] * u[i];
    }
    return product;
}

void smallest(double *v, int n) //Finding the smallest value.
{
    double min = v[0];
    int position = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
            position = i;
        }
    }
    printf("The smallest = %lf\n", min);
    printf("Position of smallest = %d\n", position);
}

void greatest(double *v, int n) //Finding the largest value.
{
    double max = v[0];
    int position;
    for (int i = 1; i < n; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
            position = i;
        }
    }
    printf("The largest = %lf\n", max);
    printf("Position of largest = %d\n", position);
}

int main()
{
    int n; //Obtaining length of vector.
    scanf("%d", &n);
    double v[n], w[n]; //Values of vector.
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &w[i]);
    }

    double scalarProd = scalarProduct(v, w, n);

    printf("Scalar product=%lf\n", scalarProd);
    smallest(v, n);
    greatest(v, n);
    smallest(w, n);
    greatest(w, n);

    return 0;
}