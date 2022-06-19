#include <iostream>
#include <fstream>
#include <GL/freeglut.h>
#include <Windows.h>

void TestStreamTable1();
void clear();
void read();
void proiz();
void DrawAxis();
void DrawStrip();
void Enable2D(int width, int height);
void Init();
void Draw();

// Размер окна для графика
int width = 512;
int height = 512;
double p[120][2] = {};

int main(int argc, char** argv)
{
    /***************************Создание и форматирофание таблица****************************************/
    TestStreamTable1();
    clear();
    read();
    proiz();
    /*************************Извлечение точек для создания графика*****************************************/
    int i = 0;
    std::ifstream proiz("X:\\Butenko\\LevelUp\\02_LEVEL\\05_LEC\\Table\\proiz.txt");
    proiz.open("proiz.txt");
    if (proiz.is_open())
    {
        while (proiz >> p[i][0] >> p[i][1])
        {
            ++i;
        }
        proiz.close();
    }
    /******************************Отрисовка графика****************************************/
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Grafic");
    glutDisplayFunc(Draw);
    Init();
    glutMainLoop();
}

