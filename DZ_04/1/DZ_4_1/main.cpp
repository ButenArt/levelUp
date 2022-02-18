/*
Поменять местами максимальный и последний отрицательный элементы массива M(40)
 */
// = s %

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    constexpr int size = 40;
        int M[size];
        int minIND;
        int maxIND;
        int max;
        int zamena;

        srand(time(0));

        for(int i = 0; i < size; ++i)
        {
            M[i] = rand() % 20 + (-9);
            printf("%d ", M[i]);
        }
        max = M[0];
        for(int i = 0; i < size; ++i)
        {
            if (max <= M[i])
            {
                maxIND = i;
                max = M[i];
            }
            if (M[i] < 0)
            {
                minIND = i;
            }

        }
        printf("\n");
        zamena = M[maxIND];
        M[maxIND] = M[minIND];
        M[minIND] = zamena;
        for(int i = 0; i < size; ++i)
        {
            printf("%d ", M[i]);
        }
        printf("\n");
    return 0;
}
