#include <iostream>
#include <fstream>
#include <string.h>

void proiz()
{
    std::ifstream rez("X:\\Butenko\\LevelUp\\02_LEVEL\\05_LEC\\Table\\result.txt");
    std::ofstream proiz("proiz.txt", std::ios::app & std::ios::out & std::ios::in);
    uint64_t mass[120][2] = {};
    double p[120][2] = {};
    int i = 0;
    rez.open("result.txt");
    if (rez.is_open())
    {
        while (rez >> mass[i][0] >> mass[i][1])
        {
            ++i;
        }
        rez.close();
    }
        for (int j = 1; j < 119; ++j)
        {
            p[j][0] = j;
            p[j][1] = static_cast<double>((mass[j][0]) - mass[j - 1][0]) / (mass[j][1] - mass[j - 1][1]);
            if (proiz.is_open())
            {
                proiz << static_cast<int>(p[j][0]) << " " << p[j][1] << std::endl;
            }
        }
        proiz.close();
}
