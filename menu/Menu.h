
#ifndef MENU_H
#define MENU_H

#include <X11/Xlib.h>

struct Menu
{
    int x = 100;
    int y = 100;
    int width = 200;
    int height = 75;
    int odstep = 100;
};

void rysujTlo(Display* display, Window window);
void rysujMenu(Display* display, Window window, GC gc, Menu menu);

#endif
