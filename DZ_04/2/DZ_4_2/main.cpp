/*
Определить местоположение элементов массива А (30), не встречающихся в массиве В (15)
 */
// = s %

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    constexpr int sizeA = 30;
    constexpr int sizeB = 15;
        int A[sizeA];
        int B[sizeB];
        srand(time(0));
        printf("Macciv A\n");
        for(int i = 0; i < sizeA; ++i)
        {
            A[i] = rand() % 20 + (-9);
            printf("%d ", A[i]);
        }
        printf("\nMacciv B\n");
        for(int j = 0; j < sizeB; ++j)
        {
            B[j] = rand() % 20 + (-9);
            printf("%d ", B[j]);
        }
        printf("\n");
        int proverka = 0;
        for(int i = 0; i < sizeA; ++i)
        {
            proverka = 0;
            for(int j = 0; j < sizeB; ++j)
            {
                if (A[i] != B[j])
                {
                    proverka += 0;
                }
                else
                {
                    proverka += 1;
                }
            }
            if (proverka == 0)
                printf("A[%d] = %d\n", i, A[i]);
        }
        printf("\n");
    return 0;
}
