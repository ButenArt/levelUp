#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

    double x = 5.00;

int isoper(char ch)
{
    if (ch == '+' ||
        ch == '-' ||
        ch == '*' ||
        ch == '/' ||
        ch == '^' ||
        ch == 's' ||
        ch == 'x')
        return 1;

    return 0;
}

double calculate(char *rpn, int *dbz)
{
    double stack[64];
    int top = -1;

    char temp[16];

    int k, l;
    int i;
    for (k = 0, top = -1; k < strlen(rpn); k++)
    {
        if (((isdigit(rpn[k]) != 0) || (rpn[k] == '-' && isdigit(rpn[k + 1]) != 0)))
        {
            l = k;

            while (isdigit(rpn[l + 1]) != 0 || rpn[l + 1] == '.')
                l++;

            for (i = 0; i < l - k + 1; i++)
                temp[i] = rpn[k + i];

            temp[i] = '\0';
            stack[++top] = atof(temp);

            k = l;
        }
        else
        {
            if (isoper(rpn[k]) != 0)
            {
                switch (rpn[k])
                {
                    case '+':
                    {
                        stack[top - 1] += stack[top];
                        top--;
                        break;
                    }
                    case '-':
                    {
                        stack[top - 1] -= stack[top];
                        top--;
                        break;
                    }
                    case '*':
                    {
                        stack[top - 1] *= stack[top];
                        top--;
                        break;
                    }
                    case '/':
                    {
                        if (stack[top] == 0.0)
                            *dbz = 1;
                        else
                        {
                            stack[top - 1] /= stack[top];
                            top--;
                            break;
                        }
                    }
                    case 's':
                    {
                        stack[top - 1] = sin(stack[top - 1]);
                        --top;
                        break;
                    }
                    case '^':
                    {
                        stack[top - 1] = pow(stack[top - 1], stack[top]);
                        top--;
                        break;
                    }
                    case 'x':
                    {
                        stack[top] = x;

                        break;
                    }
                }
            }
        }
    }

    return stack[0];
}

//------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    char rpn[128];

    double result;
    int dbz = 0;

    while (1)
    {
        printf("Enter an arithmetic expression: ");
        fgets(rpn, 128, stdin);

        if (rpn[0] == '\n')
            break;

        result = calculate(rpn, &dbz);

        if (dbz == 1)
        {
            printf("Division by zero!\n");
            continue;
        }
        else
            printf("\nResult: %lf\n\n", result);
    }

    return 0;
}
