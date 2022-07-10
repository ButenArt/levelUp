#ifndef TESTSTREAMTABLE_H
#define TESTSTREAMTABLE_H

#include<string>
#include <filesystem>

class Tab_Generator
{
public:
    Tab_Generator(int kol_host, int host_kol);
    void TestStreamTable(const std::string& path);
    //bool clear(const std::string& path, std::vector<std::vector<uint64_t>>& mass);
    //std::string tab_cleaner(const std::string& path);

private:
    int _kol_host;
    int _host_kol;
};

#endif // TESTSTREAMTABLE_H
