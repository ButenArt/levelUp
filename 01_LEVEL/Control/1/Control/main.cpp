/*Дан массив чисел. Каждое число в массиве встречается по 2 раза, кроме одного.
Найти это одинокое число.
int find( int* mass, int size );
Примеры:
[ 2, 1, 1, 2, 3] → 3*/
// = s %

#include <stdio.h>

void odin_chiclo(int* mass, int size)
{
    int chiclo;
    for(int j = 0; j < size; ++j)
    {
        for(int i = ++j; i < size; ++i)
        {
            if (mass[j] != mass[i])
                chiclo = mass[j];
        }
    }
    printf("%d\n", chiclo);
}

int main()
{
    constexpr int b = 7;
    int a[b] =  {4,5,4,8,5,1,8};
    odin_chiclo(a, b);
    return 0;
}
