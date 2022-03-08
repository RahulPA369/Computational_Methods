#include <stdio.h>
void gaussJordan(float arr[10][10], int n)
{
    float pivot, factor;
    for (int i = 0; i < n; i++)
    {
        pivot = arr[i][i];
        if (pivot == 0)
        {
            printf("\n\nMatrix is singular,Rearrange the order\n");
            return;
        }
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = arr[i][j] / pivot;
        }
        arr[i][n] = arr[i][n] / pivot;

        for (int k = 0; k < n; k++)
        {
            factor = arr[k][i];
            if (i != k)
            {
                for (int j = 0; j < n; j++)
                {
                    arr[k][j] = arr[k][j] - factor * arr[i][j];
                }
                arr[k][n] = arr[k][n] - factor * arr[i][n];
            }
        }
    }

    printf("\n\nThe solution vector is\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", arr[i][n]);
    }
}
int main()
{

    float augMatrix[10][10];
    int size;
    printf("Enter the size of the matrix");
    scanf("%d", &size);
    printf("\n\nEnter the Augmented Matrix in the form a,b,c,d\n\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            scanf("%f", &augMatrix[i][j]);
        }
    }

    printf("\n\nThe Entered Augmented Matrix is\n\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size + 1; j++)
        {
            printf("%f\t", augMatrix[i][j]);
        }
        printf("\n");
    }

    gaussJordan(augMatrix, size);

    return 0;
}