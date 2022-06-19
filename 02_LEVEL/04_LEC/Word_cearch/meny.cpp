#include "meny.h"

//#include "Keys.h"
#include "State.h"

#include <string.h>
//#include <ncurses.h>

State exit_from_game()
{
    return EXIT;
}

State start_game()
{
    return GAME;
}

State none()
{
    return state;
}

void init_menu(Menu* menu )
{
    strcpy(menu->menu_point[0].name, "Start game");
    menu->menu_point[0].fun = &start_game;

    strcpy(menu->menu_point[1].name, "Exit");
    menu->menu_point[1].fun = &exit_from_game;
    menu->current_point = 0;
}
