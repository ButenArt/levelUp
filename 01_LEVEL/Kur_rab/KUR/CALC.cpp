#include <stdio.h>
#include <stdlib.h>
#include <GL\freeglut.h>

#include <string.h>
#include <ctype.h>
#include <math.h>

typedef int flag;
static char str[255];
static char result_str[255];
//Структура, определяемая типом, для обозначения состояния структуры calculator
typedef struct {
    flag vvod;
    flag realPart;        //1.Указывает, какой статус кнопки Real PArt. -0, если викл и 1, если вкл-
    flag amplitude;        //2.Указывает, какой статус кнопки Amplitude. -0, если викл и 1, если вкл-
    flag magnitude;         //3.Указывает, какой статус кнопки Magnitude. -0, если викл и 1, если вкл-
    flag calculate;         //4.Указывает, какой статус кнопки Calculate -0, если викл и 1 пока считает
} status;

//Назначенный инициализатор для настройки начального статуса статистики состояния калькулятора
status stat = { 0, 0, 0, 0, 0};
//Строки для хранения введенных операндов и oprtrs
char operand1Str[50], operand2Str[50], resStr[50], totalExp[100], oprtr, ** endptr = NULL;
//Операнды в строках, преобразованные в числа с плавающей запятой, и результат операции
double tempOperand, operand1, operand2, result = 0;
//Некоторые временные переменные, полезные при печати на выходе калькулятора
char tempStr[100];
int temp = -2, x = 0;

extern int width;
extern int height;
extern int widhtCal;
extern GLfloat point;


//Инициализировать дисплей и окно.
//void initCal(void);
//Обрабатывает событие мыши.
void Mouse(int btn, int state, int x, int y);
//Обрабатывает событие клавиатуры.
void Keys();
//Печать на экране вывода калькулятора
void PrintOutput(void);
//Перенастройка операндов для дальнейших операций
void ReconfigureOperands(void);
//Очистить экран вывода дисплея калькулятора
void ClearEverything(void);
//Считайте символ и назначьте ему желаемый операнд
void ReadCharacter(const char key);
//Считывание оператора для выполнения операции
void ReadOperator(const char key);


void Draw();
void DrawGraf();
void DrawBPFreal();
void DrawBPFamplitude();
void DrawBPFmagniyude();
void output(int x, int y, char const* string);
void GeneratePoints(int amountOfPoints, double xMin, double xMax, char str[]);

void CalcRez(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    Draw();
    if (stat.calculate)
    {
        DrawGraf();
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, -224);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, -224);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, -160);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, -160);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        output(width / 2.0f + 77.0, 186.0, result_str);
        GeneratePoints(128, -2*M_PI, 2*M_PI, result_str);
    }
    if (stat.magnitude)
    {
        DrawBPFmagniyude();
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, -128);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, -128);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, -64);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, -64);
        glEnd();
    }
    if (stat.amplitude)
    {
        DrawBPFamplitude();
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, -32);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, -32);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, 32);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, 32);
        glEnd();
    }
    if (stat.realPart)
    {
        DrawBPFreal();
        glColor3f(0.0f, 1.0f, 0.0f);
        glBegin(GL_POLYGON);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, 64);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, 64);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 30.0, 128);
        glVertex2f(width / 2.0f + widhtCal / 2.0f - 40.0, 128);
        glEnd();
    }
    if (stat.vvod)
    {
        //output(width / 2.0f + 75.0, 186.0, "I");
        //char str[255];
            //fgets(str, 254, stdin);
            //printf("%s",str);
            //output(width / 2.0f + 77.0, 186.0, str);
            //extern const int halfOfNPoints;
            //GeneratePoints(128, -2*M_PI, 2*M_PI, str);
            stat.vvod = 0;
    }
    glutSwapBuffers();
    //glutPostRedisplay();
}


void Mouse(int btn, int state, int x, int y)
{
    if (stat.calculate)
    {
        //stat.vvod = 0;
        if (btn == GLUT_LEFT_BUTTON && (x > (width + 30.0)) && (x < (width + widhtCal - 30.0)) && (y > 322 && y < 382) && state == GLUT_DOWN)
        {
            //magnitude не горит
            if (stat.magnitude)
            {
                stat.magnitude = 0;
            }
            else
            {
                stat.magnitude = 1;
            }
        }
        if (btn == GLUT_LEFT_BUTTON && (x > (width + 30.0)) && (x < (width + widhtCal - 30.0)) && (y > 226 && y < 286) && state == GLUT_DOWN)
        {
            //amplitude не горит
            if (stat.amplitude)
            {
                stat.amplitude = 0;
            }
            else
            {
                stat.amplitude = 1;
            }
        }
        if (btn == GLUT_LEFT_BUTTON && (x > (width + 30.0)) && (x < (width + widhtCal - 30.0)) && (y > 132 && y < 190) && state == GLUT_DOWN)
        {
            //realPart не горит
            if (stat.realPart)
            {
                stat.realPart = 0;
            }
            else
            {
                stat.realPart = 1;
            }
        }

    }
    else if (btn == GLUT_LEFT_BUTTON && (x > (width + 30.0)) && (x < (width  + widhtCal - 30.0)) && (y > 418 && y < 477) && state == GLUT_DOWN)
    {
        stat.calculate = 1;
    }
    if (btn == GLUT_LEFT_BUTTON && (x > (width + 30.0)) && (x < (width + widhtCal - 30.0)) && (y > 34 && y < 96) && state == GLUT_DOWN)
    {
        memset(str,0,strlen(str));
        memset(result_str,0,strlen(result_str));
        glClear(GL_COLOR_BUFFER_BIT);
        Draw();
        glColor3f(0.0f, 0.0f, 0.0f);
        output(width / 2.0f + 75.0, 186.0, "I");
        glutSwapBuffers();
        fgets(str, 254, stdin);
        printf("Click Calculate");

        char* ch = str;
        char* result_ch = result_str;

        while(*ch != '\n')
        {
            *result_ch = *ch;
            ++ch;
            ++result_ch;
        }
        //если вводится функция
        stat.calculate = 0;
        stat.realPart = 0;
        stat.amplitude = 0;
        stat.magnitude = 0;
        stat.vvod = 1;
    }
}
