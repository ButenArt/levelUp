#include "ClearProizv.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <functional>

/**********************************************************************************************************/
struct data
{
    //std::string host = {};
    uint64_t time = 0;
    uint64_t bait = 0;
    //uint64_t oper = 0;
};
/**********************************************************************************************************/
bool Tab_Clear_Proizv::clear(const std::string& path, std::vector<std::vector<uint64_t>>& mass)
{
    std::unordered_map<std::string, std::vector<data>> Hosts;
    std::ifstream is;       // объект для записи
    is.open(path);
    int index = 0;
    std::string tempHost;
    data tempData;
    std::string temp;
    int str = 0;
    if (is.is_open())
    {
        while ((index < 4))
        {
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ++index;
        }
        for(int i = 0; is; ++i)
            {
                std::getline(is, temp);
                if (i & 0b1) {
                    continue;
                }
                std::istringstream stremStr(temp);
                stremStr.ignore(std::numeric_limits<std::streamsize>::max(), '|');
                stremStr >> tempHost;
                stremStr >> mass[str][0];
                stremStr.ignore(std::numeric_limits<std::streamsize>::max(), '|');
                stremStr >> mass[str][1];
                stremStr.ignore(std::numeric_limits<std::streamsize>::max(), '|');
                ++str;
                Hosts[tempHost].push_back(tempData);
            }
        is.close();
    }
    return true;
}
/********************************************************************************************************************/
bool all_pr(std::vector<std::vector<uint64_t>>& mass, std::vector<std::vector<double>>& p, int kol_vhojden_hosta, int i)
{
    uint64_t str_open = static_cast<uint64_t>(kol_vhojden_hosta) * i - i;
    uint64_t str_close = str_open + kol_vhojden_hosta - 2;
    uint64_t num = 0;
        for (uint64_t j = str_open; j < str_close; ++j)
        {
            p[i][num] = (static_cast<double>(mass[j + 1][1] - mass[j][1]) / (mass[j + 1][0] - mass[j][0]));
            ++num;
        }
    return true;
}
/********************************************************************************************************************/
void Tab_Clear_Proizv::proiz(std::vector<std::vector<uint64_t>>& mass, std::vector<std::vector<double>>& p, int& kol_hostov, int& kol_vhojden_hosta)
{
    for (int i = 0; i < kol_hostov-1; )
    {
        std::thread thread_1(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_2(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_3(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_4(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_5(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_6(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_7(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_8(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_9(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        std::thread thread_10(all_pr, std::ref(mass), std::ref(p), std::ref(kol_vhojden_hosta), i);
        ++i;
        thread_1.join();
        thread_2.join();
        thread_3.join();
        thread_4.join();
        thread_5.join();
        thread_6.join();
        thread_7.join();
        thread_8.join();
        thread_9.join();
        thread_10.join();
    }
}
/***************************************************************************************************************************/
bool itog_pr(std::vector<std::vector<double>>& p, std::vector<std::vector<double>>& itog, int& kol_hostov, int k)
{
    double cumma = 0;
        for (int u = 0; u < kol_hostov-1; ++u)
        {
            cumma += p[u][k];
        }
        itog[0][k] = cumma / kol_hostov;
    return true;
}

void Tab_Clear_Proizv::itog_cumm(std::vector<std::vector<double>>& p, std::vector<std::vector<double>>& itog, int kol_hostov, int& kol_vhojden_hosta)
{
    for (int k = 0; k < kol_vhojden_hosta-1; )
    {
        std::thread it_1(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_2(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_3(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_4(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_5(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_6(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_7(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_8(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_9(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        std::thread it_10(itog_pr, std::ref(p), std::ref(itog), std::ref(kol_hostov), k);
        ++k;
        it_1.join();
        it_2.join();
        it_3.join();
        it_4.join();
        it_5.join();
        it_6.join();
        it_7.join();
        it_8.join();
        it_9.join();
        it_10.join();
    }
}
