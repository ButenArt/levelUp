#include <ctime>
#include "StreamTable.h"
#include <fstream>
#include <string.h>


void TestStreamTable1()
{
    setlocale(0, "rus");
    std::ofstream out;       // объект для записи
    out.open("spisok.txt"); // любой текстовый файл в твоём проекте
    StreamTable st(out);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    //если столбцы имеют одинаковую толщину
    st.Clear();
    st.SetCols(4, 20);

    //st.SetVisible(1, false);//столбцы можно скрывать

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    //заголовок и значения выводятся одинаково
    st << "Name" << "Time" << "Bait" << "Operation";
    enum { nr = 1001 };
    std::time_t result = std::time(nullptr) + 295 + rand() % 10;
    uint64_t oper[120][nr] = {};
    uint64_t oper_10 = 0;
    uint64_t bait = 0;
    for (int i = 1; i < 120; i++)
    {
        oper_10 += 1;
        result += (static_cast<long long>(295) + rand() % 10);
        for (int j = 1; j < nr; j++)
        {
            if (i > 1)
            {
            oper[i][j] = oper[i-1][j] + oper_10 + (rand() % 10 + 0);
            bait = oper[i][j] * 1024;
            st << "host_" + std::to_string(j)<< result << bait << oper[i][j];
            }
            else
            {
            oper[i][j] = oper_10 + (rand() % 10 + 0);
            bait = oper[i][j] * 1024;
            st << "host_" + std::to_string(j)<< result << bait << oper[i][j];
            }
        }

    }
    std::cout << "The table has been created" << std::endl;
}
