#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

struct data
{
    std::string host = {};
    uint64_t time = 0;
    uint64_t bait = 0;
    uint64_t oper = 0;
};
void read()
{
    std::ifstream clear("X:\\Butenko\\LevelUp\\02_LEVEL\\05_LEC\\Table\\clear.txt");
    std::vector<data> w;
    data temp;
    std::string host_name = {};
    std::ofstream os("result.txt", std::ios::app & std::ios::out & std::ios::in);
    std::cout << "Enter name host_number(1-1000)" << std::endl;
    std::cin >> host_name;
    clear.open("clear.txt");
    if (clear.is_open())
    {
        if (os.is_open())
        {
            while (clear >> temp.host >> temp.time >> temp.bait >> temp.oper)
            {
                if (temp.host == host_name)
                {
                    os << temp.time << "  " << temp.bait << std::endl;
                    w.push_back(temp);
                }
            }
            os.close();
        }
        std::cout << "The file of a specific host is written" << std::endl;
        clear.close();
    }
}
