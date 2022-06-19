/*
 Перевести число из десятичной системы счисления в двоичную
 */
// = s %


#include <stdio.h>

unsigned long long int N;
unsigned long long int i;
char N2[256];

int main()
{
    printf("Enter three natural number\n");
    printf("N10 = ");
    scanf("%llu\n", &N);
    //printf("N2 = ");
    for (i = 0; ; ++i)
    {
        if (N == 1)
        {
            N2[i] = N;
            break;
        }
        N2[i] = N % 2;
        N = N / 2;
    }
    printf("N2 = ");
    for ( ; ; --i)
    {
        N = N2[i];
        printf("%llu", N);
        if (i == 0)
            break;
    }
    printf("\n");
    return 0;
}
