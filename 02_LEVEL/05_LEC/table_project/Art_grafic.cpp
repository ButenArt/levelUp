#include <GL/freeglut.h>
#include <Windows.h>

void DrawAxis();
void DrawStrip();
void Enable2D(int width, int height);

extern int width;
extern int height;
// Points
const int nPoinst = 118;
const int halfOfNPoints = nPoinst;

extern double p[120][2];

void Init()
{
    Enable2D(width, height);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    DrawAxis();
    DrawStrip();

    glutSwapBuffers();
}

void DrawStrip()
{
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 2)
    {
        glVertex2f(p[i][0]*width/146.0f -width / 2.0f + 40, p[i][1]*width/170.0f-0.09f);
    }
    glEnd();
}

void DrawAxis()
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

void Enable2D(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-width / 2.0f, width / 2.0f, -height / 5000.0f, height / 5000.0f, 0.0f, 2.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
