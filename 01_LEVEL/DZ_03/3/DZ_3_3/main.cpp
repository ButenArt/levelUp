/*
 Поменять местами цифры старшего и младшего разрядов данного натурального числа
 (например, из числа 3879 получится 9873)
*/
// = s %


#include <stdio.h>
#include <math.h>

unsigned long long int N;
unsigned long long int Chiclo;
unsigned long long int i = 0;
unsigned long long int j = 0;
unsigned long long int zamena;
char c[256];

int main()
{
    printf("Enter three natural number\n");
    printf("N = ");
    scanf("%llu\n", &N);
    Chiclo = N;
    while (N > 0)
       {
        i++;
        N /= 10;
       }
    j = i;
    while (i != 0)
    {
        c[i] = Chiclo % 10;
        i--;
        Chiclo /= 10;
    }
    zamena = c[1];
    c[1] = c[j];
    c[j] = zamena;
    zamena = j -1;
    for (i = 1; i <= j; ++i )
       {
        N += c[i] * pow(10,zamena);
        zamena--;
       }
    printf("N = %llu\n", N);
    return 0;
}
