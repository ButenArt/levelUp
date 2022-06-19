/*
Найти наименьший общий делитель трех натуральных чисел
(1 будет считаться наименьшим общим делителем только в том случае,
когда других общих делителей у заданных чисел нет)
*/
// = s %
#include "zagolov.h"
#include <stdio.h>


unsigned long long int N1;
unsigned long long int N2;
unsigned long long int N3;
unsigned long long int minDel = 0;

int main()
{
    printf("Enter three natural number\n");
    printf("N1 = ");
    scanf("%llu\n", &N1);
    printf("N2 = ");
    scanf("%llu\n", &N2);
    printf("N3 = ");
    scanf("%llu\n", &N3);
    min_del(N1, N2, N3, minDel);
    if (minDel == 0)
    {
        printf("No natural number\n");
        return 0;
    }
    else
    {
        printf("minDel = %llu\n", minDel);
    }
    return 0;
}
