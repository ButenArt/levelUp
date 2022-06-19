#include "zagolov.h"


void kol_cifr(unsigned long long int chiclo, unsigned long long int &kol)
{
    while (chiclo >= 1)
    {
    kol += 1;
    chiclo /= 10;
    }
}
