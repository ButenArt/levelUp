#ifndef CLEARPROIZV_H
#define CLEARPROIZV_H

#include<string>
#include <filesystem>
#include <vector>

class Tab_Clear_Proizv
{
public:
    //Tab_Clear(int kol_hostov, int kol_vhojden_hosta);
    bool clear(const std::string& path, std::vector<std::vector<uint64_t>>& mass);
    void proiz(std::vector<std::vector<uint64_t>>& mass, std::vector<std::vector<double>>& p, int& kol_hostov, int& kol_vhojden_hosta);
    void itog_cumm(std::vector<std::vector<double>>& p, std::vector<std::vector<double>>& itog, int kol_hostov, int& kol_vhojden_hosta);
private:
    int _kol_hostov;
    int _kol_vhojden_hostal;
};

#endif // CLEARPROIZV_H
