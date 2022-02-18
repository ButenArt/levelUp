/*
Дана строка символов. Определить, является ли она правильным скобочным выражением.
 */
// = s %

#include <stdio.h>


int main()
{
    char str[255];
    fgets(str, 254, stdin);

    char* ch = str;
    char* crav = str;
    int n = 0;

    while(*ch != '\n')
    {
        ++n;
        ++ch;
    }
        if (((crav[0] == '(') & (str[n-1] == ')')) |
                ((crav[0] == '{') & (str[n-1] == '}')) |
                    ((crav[0] == '[') & (str[n-1] == ']')) |
                        ((crav[0] == '<') & (str[n-1] == '>')))
        {
            printf("Good\n");
        }
        else
        {
            printf("No good\n");
        }

    return 0;
}
