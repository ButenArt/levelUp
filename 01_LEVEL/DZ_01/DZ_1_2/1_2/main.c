#include <stdio.h>

int main()
{
    float a = 5;
    float c = 5;
    float b, d;
    printf(" a = %.2f\n c = %.2f\n", a, c);
    printf(" b = ");
    scanf("%f", &b);
    printf(" d = ");
    scanf("%f", &d);
    a = a + b - 2;
    c = c + 1;
    d = c - a + d;
    printf("\n\n a = a + b - 2 = %.2f\n c = c + 1 = %.2f\n d = c - a + d = %.2f\n", a, c, d);
    a = a * c;
    c = c - 1;
    printf("\n\n a = a * c = %.2f\n c = c - 1 =%.2f\n", a, c);
    a = a / 10;
    c = c / 2;
    b = b - 1;
    d = d * (c + b + a);
    printf("\n\n a = a / 10 =%.2f\n c = c / 2 =%.2f\n b = b - 1 =%.2f\n d = d * (c + b + a) =%.2f\n\n", a, c, b, d);
    return 0;
}
