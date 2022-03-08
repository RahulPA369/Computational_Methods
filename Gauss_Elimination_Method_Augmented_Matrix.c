#include <stdio.h>
#include <stdlib.h>
void gaussElimination(float a[10][10], float x[10], int n, int *status)
{

    float factor, sum = 0, pivot;
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        pivot = a[i][i];
        if (pivot == 0)
        {
            *status = 0;
        }
        *status = 1;
        for (j = i + 1; j <= n; j++)
        {
            factor = a[j][i] / pivot;
            for (k = i; k <= n; k++)
            {
                a[j][k] = a[j][k] - factor * a[i][k];
            }
            a[j][n + 1] = a[j][n + 1] - factor * a[i][n + 1];
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("%f  ", a[i][j]);
        }
        printf("\n");
    }

    x[n] = a[n][n + 1] / a[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n + 1] - sum) / a[i][i];
    }
}

void main()
{
    float a[10][10], b[10], x[10];
    int i, j, n, status;
    FILE *p;
    p = fopen("data_files/gea.dat", "r");
    printf("Enter the size\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            fscanf(p, "%f", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            printf("%f  ", a[i][j]);
        }
        printf("\n");
    }

    gaussElimination(a, x, n, &status);

    if (status == 1)
    {
        printf("The solution vector is\n");
        for (i = 1; i <= n; i++)
        {
            printf("%f\t", x[i]);
        }
    }
    else
    {
        printf("The matrix is singular");
    }
}
