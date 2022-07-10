#include "StreamTable.h"
#include "TestStreamTable.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>

Tab_Generator::Tab_Generator(int kol_host, int host_kol)
    : _kol_host(kol_host)
    , _host_kol(host_kol)
{
    /*if (kol_host < 1)
    {
        return;
    }*/
}

void Tab_Generator::TestStreamTable(const std::string& path)
{
    std::ofstream out;       // объект для записи
    out.open(path); // любой текстовый файл в твоём проекте
    StreamTable st(out);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    //разкомментировать, если столбцы имеют одинаковую толщину
    st.Clear();
    st.SetCols(4, 20);

    //st.SetVisible(1, false);//столбцы можно скрывать

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк

    //заголовок и значения выводятся одинаково
    st << "Name" << "Time" << "Bait" << "Operation";
    //enum { nr = 1001 };
    //std::time_t result = std::time(nullptr) + 295 + rand() % 10;   //*********************************
    std::vector<std::vector<uint64_t>> oper ;
    oper.resize(_host_kol * _kol_host);
    for (int i = 1; i < _kol_host; ++i)
    {
            oper[i].resize(_host_kol);                                               //Tab_Generator one(1000, 120);
    }                                            //Tab_Generator(int&& kol_host, int&& host_kol);
    /******************
    uint64_t oper_10 = 0;
    uint64_t bait = 0;
    for (int i = 1; i < _host_kol; i++)
    {
        oper_10 += 1;
        result += (static_cast<long long>(295) + rand() % 10);
        for (int j = 1; j < _kol_host; j++)
        {
            if (i > 1)
            {
                oper[i][j] = oper[i - 1][j] + oper_10 + (rand() % 10 + 0);
                bait = oper[i][j] * 2;
                st << "host_" + std::to_string(j) << result << bait << oper[i][j];
            }
            else
            {
                oper[i][j] = oper_10 + (rand() % 10 + 0);
                bait = oper[i][j] * 2;
                st << "host_" + std::to_string(j) << result << bait << oper[i][j];
            }
    *****************/
    for (int i = 1; i < _kol_host; i++)
    {
        uint64_t oper_10 = 0;
        uint64_t bait = 0;
        std::time_t result = std::time(nullptr) + 295 + rand() % 10;
        for (int j = 1; j < _host_kol; j++)
        {
            oper_10 += 1;
            result += (static_cast<long long>(295) + rand() % 10);
            //if (i > 1)
            //{
                oper[i][j] = oper[i][j-1] + oper_10 + (static_cast<uint64_t>(rand() % 10) + 0);
                bait = oper[i][j] * 2;
                st << "host_" + std::to_string(i) << result << bait << oper[i][j];
            //}
            //else
            //{
            //    oper[i][j] = oper_10 + (static_cast<uint64_t>(rand() % 10) + 0);
            //    bait = oper[i][j] * 2;
            //    st << "host_" + std::to_string(i) << result << bait << oper[i][j];
            //}*/
        }

    }
    std::cout << "Table_save" << std::endl;
}
