#include <stdio.h>
#define X(y, z) ((17 - 20 * (y) + 2 * (z)) / 20)
#define Y(x, z) ((-18 - 3 * (x) + (z)) / 20)
#define Z(x, y) ((25 - 2 * (x) + 3 * (y)) / 20)
void main()
{

    float x = 0, y = 0, z = 0;
    int i = 0;
    do
    {

        x = X(y, z);
        y = Y(x, z);
        z = Z(x, y);
        i++;

    } while (i < 20);

    printf("\n\nx = %0.3lf", x);
    printf("\n\ny = %0.3lf", y);
    printf("\n\nz = %0.3lf", z);
}