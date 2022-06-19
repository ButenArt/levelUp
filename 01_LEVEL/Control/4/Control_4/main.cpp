/*Дан массив длиной size. Массив состоит из целых чисел. Дано целое число K.
Найти в этом массиве такой интервал, что бы сумма элементов в нем равнялась K.

struct Pair
{
 int first;
 int second;
};

Pair find( int* mass, int size, int k );*/

#include <stdio.h>

struct Pair
{
 int first;
 int second;
};

Pair find( int* mass, int size, int k )
{
    for(int i = 0; i < size; ++i)
    {
        int Cum = 0;
        for(int j = i; j < size; ++j)
        {
            Cum += mass[j];
            if (Cum == k)
            {
                printf("%d  %d\n", i, j);
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main()
{
    constexpr int b = 7;
    constexpr int K = 12;
    int a[b] =  {4,5,4,3,5,1,8};
    find(a, b, K);
    return 0;
}

