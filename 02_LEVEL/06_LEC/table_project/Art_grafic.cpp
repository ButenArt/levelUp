#include "Art_grafic.h"
#include <GL/freeglut.h>
#include <Windows.h>
#include <vector>
//
//void DrawAxis();
//void DrawStrip();
//void Enable2D(int width, int height);

extern int width;
extern int height;
extern int kol_vhojden_hosta;

extern std::vector<std::vector<double>> itog;;

void Art_Grafic::Enable2D(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width / 2.0f, width / 2.0f, -height / 5000.0f, height / 5000.0f, 0.0f, 2.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Art_Grafic::Init()
{
    Enable2D(width, height);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Art_Grafic::DrawStrip()
{
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 1; i < kol_vhojden_hosta-1; ++i)
    {
        glVertex2f(i * 0.10f -width / 2.0f + 40.0f, itog[0][i-1] * 0.01f-0.09f); //*width/146.0f -width / 2.0f + 40
    }
    glEnd();
}

void Art_Grafic::DrawAxis()
{
    // Draw X axis
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, -0.09f );
    glVertex2f(width / 2.0f, -0.09f );
    glEnd();

    // Draw Y axis
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f + 40, -height / 1.0f);
    glVertex2f(-width / 2.0f + 40, height / 1.0f);
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Art_Grafic one;
    one.DrawAxis();
    one.DrawStrip();

    glutSwapBuffers();
}


