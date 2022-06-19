/*
 Найти сумму ряда
f(x) = x^1 + x^3/2*3 + 1*3*x^5/2*4*5 ....
с точностью сточностью 10^-5, где 0.05<x<1
 */
// = s %

#include <math.h>
#include <stdio.h>

int main()
{
    const double eps = 1e-5;
    double sum = 0;
    double step = 0;
    double x = 0;
    double chislitel = 1;
    double znamenatel = 1;

    printf("Please enter x (0.05 < x < 1): ");
    scanf("%lf", &x);

    if ((0.05 < x) && (x < 1))
    {
        sum = x;
        for(int i = 1; true; ++i)
        {
            chislitel *= (2*i-1);
            znamenatel *= 2 * i;
            step = (chislitel * pow(x, (double)(2 * i + 1))) / (znamenatel * (2 * i + 1));
            if (step < eps)
                break;
            sum += step;
        }
    }

    printf("Result summ is: %f\n", sum);

    return 0;
}
