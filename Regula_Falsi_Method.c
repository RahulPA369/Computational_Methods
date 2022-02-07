#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x * x * x - 2.0 * x - 5.0;
}
float regulaFalsi(float xl, float xu)
{
    return xl - (f(xl) * (xu - xl)) / (f(xu) - f(xl));
}
float xAccuracy(float x, float acc)
{
    return (float)((int)(x / acc) * acc);
}
void root(float a, float b, float acc, int noit)
{

    float x, xl, xu, del;
    int i = 0;

    if (f(a) * f(b) > 0)
    {
        printf("Root is not bracketed");
        return;
    }

    xl = a;
    xu = b;

    while (i < noit)
    {
        x = regulaFalsi(xl, xu);

        if (f(x) == 0)
        {
            printf("Root is %f", x);
            return;
        }

        if (f(x) * f(xl) < 0)
        {
            xu = x;
        }
        else
        {
            xl = x;
        }

        if (fabs(xu - xl) < acc)
        {
            x = xAccuracy(x, acc);
            printf("Root = %f\n ", x);
            return;
        }
        i++;
    }

    x = xAccuracy(x, acc);
    printf("Root is %f\n", x);
}
void main()
{
    float a, b, acc = 0.001;
    int noit = 30;
    printf("Enter the upper and lower limits\n");
    scanf("%f%f", &a, &b);
    root(a, b, acc, noit);
}