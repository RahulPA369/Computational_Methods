#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x * x * x - 4.0 * x - 9.0;
}
void root(float a, float b, float acc, int noit)
{
    float xl, xu, x;

    int i = 0;

    if (f(a) * f(b) > 0)
    {
        printf("Root is not bracketed\n");
        return;
    }

    xl = a;
    xu = b;
    while (i < noit)
    {
        x = 0.5 * (xl + xu);
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
            printf("\nRoot = %f\n", (xu + xl) * 0.5);
            return;
        }
        i++;
    }
    printf("Root is %f", x);
}
int main()
{
    float a, b, acc = 0.0001;
    int noit = 30;
    printf("Enter the lower and upper limit\n");
    scanf("%f%f", &a, &b);
    root(a, b, acc, 20);
    return 0;
}