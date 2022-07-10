#include "Art_grafic.h"
#include "StreamTable.h"
#include "TestStreamTable.h"
#include "ClearProizv.h"
#include <iostream>
#include <fstream>
#include <GL/freeglut.h>
#include <Windows.h>

void Draw();

// Размер окна для графика
int width = 512;
int height = 512;
// Результирующий вектор
std::vector<std::vector<double>> itog;
// Количество хостов в файле
int kol_hostov = 1001;
// Количество каждого вхождения хоста
int kol_vhojden_hosta = 100001;

/**************************************************************************************/
int main(int argc, char** argv)
{
/***************************Создание и форматирофание таблица****************************************/
    const std::string path = "D:\\LevelUP\\levelUp\\02_LEVEL\\06_LEC\\table_project\\spisok.txt";
    //Tab_Generator one(kol_hostov, kol_vhojden_hosta);
    //one.TestStreamTable(path);
/*************************Извлечение данних из таблици*****************************************/
    uint64_t currentTime = time(nullptr); /********************************************/
    std::vector<std::vector<uint64_t>> mass;
    mass.resize(kol_hostov * kol_vhojden_hosta * 2);
    for (int i = 0; i < (kol_hostov * kol_vhojden_hosta); ++i)
    {
        mass[i].resize(2);
    }
    Tab_Clear_Proizv two{};
    two.clear(path, mass);
    std::cout << "Spend time clear:  " << time(nullptr) - currentTime << " sec" << std::endl;/**************************/
/*************************Извлечение производних*****************************************/
    uint64_t curTime = time(nullptr); /********************************************/
    std::vector<std::vector<double>> p;
    p.resize(kol_hostov * (kol_vhojden_hosta -2));
    for (int i = 0; i < kol_hostov; ++i)
    {
        p[i].resize(kol_vhojden_hosta-2);
    }
    two.proiz(mass, p, kol_hostov, kol_vhojden_hosta);
    std::cout << "/**Itog Point in grafic**/" << std::endl;
/*************************Получение итогових точек для графиков*****************************************/
    itog.resize(kol_vhojden_hosta);
    for (int i = 0; i < 1; ++i)
    {
        itog[i].resize(kol_vhojden_hosta);
    }
    two.itog_cumm(p, itog, kol_hostov, kol_vhojden_hosta);
    std::cout << "Spend time proiz:  " << time(nullptr) - curTime << " sec" << std::endl;/**************************/
    std::cout << " first:   " << itog[0][0] << std::endl;
    std::cout << " second:   " << itog[0][kol_vhojden_hosta-4] <<std::endl;
/******************************Отрисовка графика****************************************/
    Art_Grafic three;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Grafic");
    glutDisplayFunc(Draw);
    three.Init();
    glutMainLoop();
    return 0;
}

