
#include "Menu.h"

//Kolor tła
void rysujTlo(Display* display, Window window)
{
    XSetWindowBackground(display, window, 0x301050);
}

//Kwadrat Graj i Leave
void rysujMenu(Display* display, Window window, GC gc, Menu menu)
{
    //Kwadrat Graj
    XSetForeground(display, gc, 0x0000FF00);
    XFillRectangle(
        display,
        window,
        gc,
        100, 100,
        menu.width, menu.height
    );

    XSetForeground(display, gc, 0x00000000);
    XDrawString(
        display,
        window,
        gc,
        185, 140,
        "Graj",
        4
    );

    //drugi wkadrat
    XSetForeground(display, gc, 0x0000FF00);
    XFillRectangle(
        display,
        window,
        gc,
        100, 100 + menu.odstep,
        menu.width, menu.height
    );

    XSetForeground(display, gc, 0x000000);
    XDrawString(
        display,
        window,
        gc,
        185, 140 + menu.odstep,
        "Leave",
        5
    );
}
