/*
 Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой.
 */
// = s %

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    constexpr int sizeA = 7;
    constexpr int k = 1;
        int A[sizeA][sizeA];
        srand(time(0));
        printf("Macciv one\n");
        for(int i = 0; i < sizeA; ++i)
        {
            for(int j = 0; j < sizeA; ++j)
            {
            A[i][j] = rand() % 10 + (0);
            printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\nMacciv result\n");
        int zamena;
        for(int i = 0; i < sizeA; ++i)
        {
            for(int j = 0; j < sizeA; ++j)
            {
            if (i == k)
            {
                zamena = A[j][k];
                A[j][k] = A[k][j];
                A[k][j] = zamena;
            }
            }
        }
        for(int i = 0; i < sizeA; ++i)
        {
            for(int j = 0; j < sizeA; ++j)
            {
            printf("%d ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    return 0;
}
