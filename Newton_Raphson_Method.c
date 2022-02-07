#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 3 * x - cos(x) - 1;
}
float df(float x)
{
    return 3 + sin(x);
}
float newtonRaphson(float x)
{
    return x - f(x) / df(x);
}
void root(float a, float acc, int itno)
{
    float x, x1;
    int i = 0;
    x1 = a;
    while (i < itno)
    {
        x = newtonRaphson(x1);
        if (fabs(x - x1) < acc)
        {
            printf("Root = %f", x);
            return;
        }
        x1 = x;
        i++;
    }
    printf("\n No of Iterations are not sufficient/ Root is not converging");
}
void main()
{
    float a, acc = 0.001;
    int itno = 30;
    printf("Enter the approximated root\n");
    scanf("%f", &a);
    root(a, acc, itno);
}