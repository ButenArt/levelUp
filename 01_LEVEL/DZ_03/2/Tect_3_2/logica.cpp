#include "zagolov.h"


void min_del(unsigned long long int &N1, unsigned long long int &N2, unsigned long long int &N3, unsigned long long int &minDel)
{
    unsigned long long int min;
    min = N1;
    if (N2 < min)
    min = N2;
    if (N3 < min)
    min = N3;
    if ((N1 < 1) || (N2 < 1) || (N3 < 1))
    {
        minDel = 0;
    }
    else
    {
        minDel = 1;
        for (unsigned long long int delitel = 2; delitel <= min; ++delitel)
        {
            if ((N1 % delitel) == 0)
            {
                if ((N2 % delitel) == 0)
                {
                    if ((N3 % delitel) == 0)
                    {
                    minDel = delitel;
                    break;
                    }
                }
            }
        }
    }
}
