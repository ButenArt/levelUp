// Дано натуральное число N.
// Составить програрамму для определения количества цифр в этом числе.
// = s %

#include <stdio.h>

unsigned long long int i = 0;
unsigned long long int N;

int main()
{
    printf("Enter a natural number\n N = ");
    scanf("%llu", &N);
    while (N >= 1)
    {
    i += 1;
    N /= 10;
    }
    if (i == 0)
    {
        printf("No natural number\n");
    }
    else
        printf("i = %llu\n", i);
    return 0;
}
