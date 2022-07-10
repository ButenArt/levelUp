#ifndef ART_GRAFIC_H
#define ART_GRAFIC_H

#include <GL/freeglut.h>
#include <Windows.h>
#include <vector>

class Art_Grafic
{
public:
    void Init();
    void Draw();
    void DrawStrip();
    void DrawAxis();
    void Enable2D(int width, int height);

};

#endif // ART_GRAFIC_H
