/*Есть несколько детей, у каждого ребенка есть некоторое число конфет. Число конфет у детей задается массивом.
Так же есть некоторое число дополнительных конфет.
Требуется определить, если указанному ребенку отдать все дополнительные конфеты, то будет ли у него их максимальное количество.

bool find( int* mass, int size, int child, int count );

Примеры:
[ 1, 2, 5, 2, 1], дополнительные конфеты 3.
Результаты по детям: false, true, true, true, false*/

// = s %

#include <stdio.h>

bool find( int* mass, int size, int child, int count )
{
    mass[child] += count;
    for(int j = 0; j < size; ++j)
    {
        if (mass[j] > mass[child])
        {
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}

int main()
{
    constexpr int dop = 3;
    constexpr int b = 5;
    int a[b] =  {1,2,5,2,1};
    find(a, b, 0, dop);
    return 0;
}
