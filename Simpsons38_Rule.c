#include <stdio.h>
#define F(x) 1 / (1 + x * x)

void simpsons38(float a, float b, int n)
{
    float h, sum = 0, x, s;
    h = (b - a) / n;
    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;

        if (i % 3 == 0)
        {
            sum += 2 * F(x);
        }
        else
        {
            sum += 3 * F(x);
        }
    }

    s = (3.0 / 8.0) * h * (F(a) + F(b) + sum);

    printf("The Integral is %0.4f", s);
}
int main()
{

    float a, b;
    int nod;
    printf("Enter the limits of interval\n");
    scanf("%f%f", &a, &b);
    printf("Enter the number of sub intervals\n");
    scanf("%d", &nod);
    simpsons38(a, b, nod);
    return 0;
}