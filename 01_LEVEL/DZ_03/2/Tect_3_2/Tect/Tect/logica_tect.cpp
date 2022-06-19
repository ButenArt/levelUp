#include <gtest/gtest.h>
#include "../../zagolov.h"

TEST(tect3_2, logica_tect_1)
{
    unsigned long long int N1 = 15;
    unsigned long long int N2 = 3;
    unsigned long long int N3 = 45;
    unsigned long long int minDel = 3;
    unsigned long long int i = 0;
    min_del(N1, N2, N3, i);
    EXPECT_EQ(minDel, i);
}

TEST(tect3_2, logica_tect_2)
{
    unsigned long long int N1 = 0;
    unsigned long long int N2 = 1;
    unsigned long long int N3 = 1;
    unsigned long long int minDel = 0;
    unsigned long long int i = 0;
    min_del(N1, N2, N3, i);
    EXPECT_EQ(minDel, i);
}

TEST(tect3_2, logica_tect_3)
{
    unsigned long long int N1 = 8;
    unsigned long long int N2 = 1;
    unsigned long long int N3 = 1;
    unsigned long long int minDel = 1;
    unsigned long long int i = 0;
    min_del(N1, N2, N3, i);
    EXPECT_EQ(minDel, i);
}

TEST(tect3_2, logica_tect_4)
{
    unsigned long long int N1 = 545545545211212868;
    unsigned long long int N2 = 425468542254855548;
    unsigned long long int N3 = 458898989821148485;
    unsigned long long int minDel = 2;
    unsigned long long int i = 0;
    min_del(N1, N2, N3, i);
    EXPECT_EQ(minDel, i);
}
