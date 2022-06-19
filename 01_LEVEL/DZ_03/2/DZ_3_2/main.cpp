/*
Найти наименьший общий делитель трех натуральных чисел
(1 будет считаться наименьшим общим делителем только в том случае,
когда других общих делителей у заданных чисел нет)
*/
// = s %

#include <stdio.h>


unsigned long long int N1;
unsigned long long int N2;
unsigned long long int N3;
unsigned long long int min;
unsigned long long int minDel = 1;

int main()
{
    printf("Enter three natural number\n");
    printf("N1 = ");
    scanf("%llu\n", &N1);
    printf("N2 = ");
    scanf("%llu\n", &N2);
    printf("N3 = ");
    scanf("%llu\n", &N3);
        min = N1;
    if (N2 < min)
        min = N2;
    if (N3 < min)
        min = N3;
    for (unsigned long long int delitel = 2; delitel <= min; ++delitel)
    {
        if ((N1 % delitel) == 0)
        {
            if ((N2 % delitel) == 0)
            {
                if ((N3 % delitel) == 0)
                {
                minDel = delitel;
                break;
                }
            }
        }
    }
    printf("minDel = %llu\n", minDel);
    return 0;
}
