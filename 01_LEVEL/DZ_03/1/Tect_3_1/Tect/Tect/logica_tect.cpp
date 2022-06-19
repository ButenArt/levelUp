#include <gtest/gtest.h>
#include "../../Tect_3_1/zagolov.h"

TEST(tect3_1, logica_tect_1)
{
    const unsigned long long int N = 4562;
    const unsigned long long int kol = 4;
    unsigned long long int i = 0;
    kol_cifr(N, i);
    EXPECT_EQ(kol, i);
}

TEST(tect3_1, logica_tect_2)
{
    const unsigned long long int N = 48;
    const unsigned long long int kol = 2;
    unsigned long long int i = 0;
    kol_cifr(N, i);
    EXPECT_EQ(kol, i);
}

TEST(tect3_1, logica_tect_3)
{
    const unsigned long long int N = 4;
    const unsigned long long int kol = 1;
    unsigned long long int i = 0;
    kol_cifr(N, i);
    EXPECT_EQ(kol, i);
}

TEST(tect3_1, logica_tect_4)
{
    const unsigned long long int N = 0;
    const unsigned long long int kol = 0;
    unsigned long long int i = 0;
    kol_cifr(N, i);
    EXPECT_EQ(kol, i);
}


