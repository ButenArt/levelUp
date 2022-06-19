/*
Дана строка символов. Удалить из нее все слова нечетной длины. Слова отделяются друг от друга одним пробелом.
 */
// = s %

#include <stdio.h>

int main()
{
    char str[255];
    fgets(str, 254, stdin);

    char result_str[255];

    char* ch = str;
    char* ch2 = str;
    char* result_ch = result_str;
    int n = 0;

    while(*ch != '\n')
    {
        while((*ch != ' ') && (*ch != '\n'))
        {
            ++n;
            ++ch;
        }
        if ((n % 2) == 0)
        {
            while(n > 0)
            {
                *result_ch = *ch2;
                ++ch2;
                ++result_ch;
                --n;
            }
        }
        else
        {
            while(n > 0)
            {
                ++ch2;
                --n;
            }
        }
        n = 0;
        if (*ch != '\n')
        {
            *result_ch = *ch2;
            ++result_ch;
            ++ch2;
            ++ch;
        }
        else
        {
            goto final;
        }
    }
    final:
    *result_ch = '\0';

    puts(result_str);

    return 0;
}
