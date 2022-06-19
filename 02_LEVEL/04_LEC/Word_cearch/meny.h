#ifndef MENU_H
#define MENU_H

#include "State.h"

struct MenuPoint
{
    char name[255];
    State (*fun)();
};

struct Menu
{
    MenuPoint menu_point[2];
    int current_point;
};

void init_meny(Menu* menu);
void print_meny(Menu& menu);
State move_meny(Menu* menu, int key);

#endif // MENU_H
