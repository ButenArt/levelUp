/*
  Вычислить сумму элементов матрицыб лежащих сслева от побочной диагонали.
 */
// = s %

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    constexpr int sizeA = 5;
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
        int cum = 0;
        int n = 0;
        n =  sizeA - 1;
        for(int i = 0; i < sizeA; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                    cum += A[i][j];
            }
            n -= 1;
        }
        printf("summa = %d\n", cum);
    return 0;
}
