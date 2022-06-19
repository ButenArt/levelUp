// Дано натуральное число N.
// Составить програрамму для определения количества цифр в этом числе.
// = s %

#include <stdio.h>
#include "zagolov.h"

int main()
{
    unsigned long long int N;
    unsigned long long int i = 0;
    printf("Enter a natural number\n N = ");
    scanf("%llu", &N);
    kol_cifr(N, i);
    if (i == 0)
    {
        printf("No natural number\n");
    }
    else
        printf("i = %llu\n", i);
    return 0;
}
