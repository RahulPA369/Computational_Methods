#include <stdio.h>
#include <stdlib.h>
void gaussElimination(float a[10][10], float b[10], float x[10], int n, int *status)
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
            b[j] = b[j] - factor * b[i];
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%f  ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 1; i <= n; i++)
    {
        printf("%f\n", b[i]);
    }

    x[n] = b[n] / a[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void main()
{
    float a[10][10], b[10], x[10];
    int i, j, n, status;
    FILE *p;
    FILE *pp;
    p = fopen("data_files/ge1.dat", "r");
    pp = fopen("data_files/ge2.dat", "r");
    printf("Enter the size\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            fscanf(p, "%f", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        fscanf(pp, "%f", &b[i]);
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%f  ", a[i][j]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        printf("%f\n", b[i]);
    }

    gaussElimination(a, b, x, n, &status);

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

/*
void gauss(float a[10][10],int n){

    int i,j,k;
    float pivot,factor,det=1;
    for(k=1;k<=n;k++)
    {
    pivot = a[k][k];
    for(i=k+1;i<=n;i++)
        {
        factor=a[i][k]/pivot;
        for(j=k;j<=n;j++)
          {
          a[i][j]=a[i][j]-factor*a[k][j];
          }

        }
    }

    printf("\nThe Reduced Matrix is\n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",a[i][j]);
        }
        printf("\n");
    }


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                det=det*a[i][j];
            }
        }

    }

    printf("\nThe Determinant is %f\n",det);



}
void main(){
    float a[10][10];
    int i,j,n;
    FILE *f;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    f=fopen("matA.dat","r");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            fscanf(f,"%f",&a[i][j]);
        }
    }
    printf("\nThe Matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f  ",a[i][j]);
        }
        printf("\n");
    }

    gauss(a,n);

}*/