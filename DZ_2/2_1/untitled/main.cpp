#include <stdio.h>
#include <math.h>

void Z1()
{
    double x;
    double Y;
    printf(" Pervoe zadanie\n");
    //printf(" x = ");
    scanf("%lf", &x);
    //x = M_PI / 3;
    Y = ( (2 * cos(x - M_PI/6) + sqrt(2) ) / ((1 / (2*log(x)))+pow( sin(pow(x,2)),2)))*(exp (3*x));
    printf(" Y = %f\n", Y);
}

void Z2()
{
    float krR, trA, kvD, ITOG;
    printf("\n\n Vtoroe zadanie\n");
    printf("krR = ");
    scanf("%f", &krR);
    printf("trA = ");
    scanf("%f", &trA);
    printf("kvD = ");
    scanf("%f", &kvD);
    krR = M_PI * pow(krR, 2);
    trA = pow(trA, 2) * sqrt(3) / 4;
    kvD = pow(kvD, 2);
    printf(" krR = %.2f\n trA = %.2f\n kvD = %.2f\n", krR, trA, kvD);
    ITOG = krR > trA ? krR : trA;
    ITOG = ITOG > kvD ? ITOG : kvD;
    printf(" ITOG = %.2f\n", ITOG);
}

int main()
{
    Z1();
    Z2();
    return 0;
}


