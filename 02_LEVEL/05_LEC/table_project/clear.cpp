#include <iostream>
#include <fstream>
#include <string.h>
#include <limits>

void clear()
{
    std::ifstream is("X:\\Butenko\\LevelUp\\02_LEVEL\\05_LEC\\Table\\spisok.txt");
    std::ofstream clear("clear.txt", std::ios::app & std::ios::out & std::ios::in);
    std::string host = {};
    std::string time = {};
    std::string bait = {};
    std::string oper = {};
    int index = 0;
    is.open("spisok.txt");
    if (is.is_open())
    {
        if (clear.is_open())
        {
            while ((index < 4))
            {
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ++index;
            }
                    while (is.ignore(std::numeric_limits<std::streamsize>::max(), '|') >> host >> time >> bait >> oper)
                    {
                        host.pop_back();
                        time.pop_back();
                        bait.pop_back();
                        oper.pop_back();
                        clear << host << " " << time << " " << bait << " " << oper << std::endl;
                        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }

            clear.close();
        }
        std::cout << "The file of a clear" << std::endl;
        is.close();
    }
}
