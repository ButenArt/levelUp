#include <GL\freeglut.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <string.h>
#include <ctype.h>
#include <math.h>

#include "parser.h"

// Window size
int width = 512;
int height = 512;
int widhtCal = 415;

const int nPoinst = 256;
const int halfOfNPoints = nPoinst / 2;
double points[nPoinst];
static float Re[halfOfNPoints];
static float Im[halfOfNPoints];

//Определения типов для устранения неоднозначностей
typedef GLfloat point;

//задает начальные и конечные координаты Y для всех кнопок.
//Значение изменяется каждый раз перед рисованием отдельной строки.
point rowMinY, rowMaxY;

void DrawAxes();
void DrawGraf();
void GenerateBPF();
void DrawBPFreal();
void DrawBPFamplitude();
void DrawBPFmagnitude();
void GeneratePoints(int amountOfPoints, double xMin, double xMax, char str[]);
void Enable2D(int width, int height);
bool FFT(float *Rdat, float *Idat, int N, int LogN, int Ft_Flag);

//Принимает 4 точки в качестве аргументов и рисует многоугольник, используя его.
void DrawMenyButton(point p1, point p2, point p3, point p4);
//Вызывает DrawMenyButtons несколько раз, чтобы нарисовать все кнопки калькулятора
void DrawMeny(void);
//Для печати заданной строки или символа в местоположении (x, y)
void output(int x, int y, char const* string);
//Обрабатывает событие мыши.
void Mouse(int btn, int state, int x, int y);
//Отображение обратного вызова.
void CalcRez(void);

typedef enum {
    MODE_BITMAP,
    MODE_STROKE
} mode_type;
static mode_type mode;
static int font_index;

void Init()
{
    Enable2D(width + widhtCal, height);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    mode = MODE_BITMAP;
    font_index = 0;
}

void GeneratePoints(int amountOfPoints, double xMin, double xMax,char str[])
{
    TParser parser;
    parser.Compile(str);
    double step = abs((xMax - xMin) / (double)amountOfPoints);
    double xScaleCof = 40.0f;
    double yScaleCof = 100.0f;
    double x = xMin;

    for (int i = 0, index = 0; i < amountOfPoints; ++i, index += 2)
    {
        points[index] = x * xScaleCof;
        points[index + 1] = parser.Evaluate(x) * yScaleCof; // (sin(x[0])^2)/x[0]   // cos(x[0])   /*pow(sin(x),2)/x*/
        x += step;                                          // (sin(x[0])^2)/x[0] + cos(x[0])
    }
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    DrawAxes();
    DrawMeny();
    GenerateBPF();
    glutSwapBuffers();
}

void DrawGraf()
{
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 2)
    {
        glVertex2f(points[index], points[index + 1] + height/4);
    }
    glEnd();
}

void GenerateBPF()
{
    // формируем сигнал
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 2)
    {
      Re[i] = points[index];  // заполняем действительную часть сигнала
      Im[i] = points[index + 1];         // заполняем мнимую часть сигнала
    }
    FFT(Re, Im, 128, 7, -1); // вычисляем прямое БПФ

    // выводим действительную и мнимую части спектра и спектр мощности
    /*FILE *f = fopen("spectrum.txt", "w");
    for(i=0; i<halfOfNPoints; i++)
    {
      fprintf(f, "%10.6f  %10.6f  %10.6f\n", Re[i], Im[i], Re[i]*Re[i]+Im[i]*Im[i]);
    }
    fclose(f);*/
}

void DrawBPFreal()
{
    glLineWidth(10.0);
    // выводим действительную часть спектра
        glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 1.0f);
        for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 4)
        {
            glVertex2f(points[index], Re[i]/50 - height / 4.0f);
            glVertex2f(points[index], - height / 4.0f);
        }
        glEnd();
}

void DrawBPFamplitude()
{
    glLineWidth(10.0);
    //выводим мнимую часть спектра
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 4)
    {
        glVertex2f(points[index], Im[i]/100 - height / 4.0f);
        glVertex2f(points[index], - height / 4.0f);
    }
    glEnd();
}

void DrawBPFmagniyude()
{
    glLineWidth(10.0);
    //выводим спектр мощности
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 4)
    {
        glVertex2f(points[index],(Re[i]*Re[i]+Im[i]*Im[i])/1000000 - height / 4.0f);
        glVertex2f(points[index], - height / 4.0f);
    }
    glEnd();
    //выводим действительную и мнимую части спектра и спектр мощности
/*        glLineWidth(10.0);
        glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 1.0f);
    for (int i = 0, index = 0; i < halfOfNPoints; ++i, index += 4)
    {
        glVertex2f(points[index],points[index+1] - height / 4.0f);
        glVertex2f(points[index], - height / 4.0f);
    }
    glEnd();*/
}

void DrawAxes()
{
    glLineWidth(1.0);
    //  X
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, height / 4.0f);
    glVertex2f(width / 2.0f, height / 4.0f);
    glEnd();

    //  Y
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, height / 2);
    glEnd();

    //  Razdel
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, 5.0f);
    glVertex2f(width / 2.0f, 5.0f);
    glVertex2f(width / 2.0f, -5.0f);
    glVertex2f(-width / 2.0f, -5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, width/ 2.0f);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, height / 2.0f);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, height / 2.0f - 5.0f);
    glVertex2f(-width / 2.0f, width/ 2.0f -5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, -width/ 2.0f);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, -height / 2.0f);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, -height / 2.0f + 5.0f);
    glVertex2f(-width / 2.0f, -width/ 2.0f + 5.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(width / 2.0f, height);
    glVertex2f(width / 2.0f+5.0f, height);
    glVertex2f(width / 2.0f+5.0f, -height);
    glVertex2f(width / 2.0f, -height);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(width / 2.0f + widhtCal / 2.0f - 5.0f, height);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, height);
    glVertex2f(width / 2.0f + widhtCal / 2.0f, -height);
    glVertex2f(width / 2.0f + widhtCal / 2.0f - 5.0f, -height);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, height);
    glVertex2f(-width / 2.0f+5.0f, height);
    glVertex2f(-width / 2.0f+5.0f, -height);
    glVertex2f(-width / 2.0f, -height);
    glEnd();

    //  X
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-width / 2.0f, -height / 4.0f);
    glVertex2f(width / 2.0f, -height / 4.0f);
    glEnd();

    //  Y
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, -height / 2.);
    glEnd();
}


void Enable2D(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(width - widhtCal) / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, 0.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//***********************************************************************************//
//*************************Раздел*с*меню*********************************************//
//***********************************************************************************//


void DrawMenyButton(point p1, point p2, point p3, point p4)
{
    glBegin(GL_POLYGON);
    glVertex2f(p1, rowMinY);
    glVertex2f(p2, rowMinY);
    glVertex2f(p3, rowMaxY);
    glVertex2f(p4, rowMaxY);
    glEnd();
}

void output(int x, int y, char const* string)
{
    int len, i;
    glRasterPos2f(x, y);
    len = (int)strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

void DrawMeny(void)
{
    glColor3f(0.79f, 0.79f, 0.79f);
    rowMinY = -224.0, rowMaxY = -160.0;                 //5-й ряд кнопок
    DrawMenyButton(width / 2.0f + 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + 30.0);
    rowMinY = -128.0, rowMaxY = -64.0;                  //4-й ряд кнопок
    DrawMenyButton(width / 2.0f + 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + 30.0);
    rowMinY = -32.0, rowMaxY = 32.0;                   //3-й ряд кнопок
    DrawMenyButton(width / 2.0f + 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + 30.0);
    rowMinY = 128.0, rowMaxY = 64.0;                  //2-й ряд кнопок
    DrawMenyButton(width / 2.0f + 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + 30.0);
    rowMinY = 224.0, rowMaxY = 160.0;                 //1-й ряд кнопок
    DrawMenyButton(width / 2.0f + 71.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + widhtCal / 2.0f - 30.0, width / 2.0f + 71.0);
    glColor3f(1.0, 1.0, 1.0);
    DrawMenyButton(width / 2.0f + 30.0, width / 2.0f + 71.0, width / 2.0f + 71.0, width / 2.0f + 30.0);


    glColor3f(0.0, 0.0, 0.0);                       //Отображение каждого из названий кнопок.
    output(width / 2.0f + 40.0, 186.0, "Y =");      //1-й ряд кнопок
    output(width / 2.0f + 60.0, 90.0, "BPF Real part");      //2-й ряд кнопок
    output(width / 2.0f + 60.0, -6.0, "BPF Amplitude");      //3-й ряд кнопок
    output(width / 2.0f + 60.0, -102.0, "BPF Magnitude");      //4-й ряд кнопок
    output(width / 2.0f + 80.0, -198.0, "Calculate");      //5-й ряд кнопок
}


//***********************************************************************************//
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE/* | GLUT_RGB | GLUT_DEPTH*/);
    glutInitWindowSize(width + widhtCal, height);
    glutCreateWindow("BPF Grafic");

    glutDisplayFunc(Draw);
    glutReshapeWindow(width + widhtCal, height);
    Init();

    glutMouseFunc(Mouse);
//    glutKeyboardFunc(Keys);
    //glutDisplayFunc(CalcRez);                                     // пока не дошел
    glutIdleFunc(CalcRez);
    glutMainLoop();
    return 0;
}
