#include <X11/Xlib.h>
#include <iostream>
#include <cstring>
#include "menu/Menu.h"

int main()
{
    Menu menu;
    
    Display* display = XOpenDisplay(nullptr);

    if (display == nullptr)
        return 1;

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(

        display,
        RootWindow(display, screen),
        100, 100,
        1920, 1080,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );
    XStoreName(display, window, "Moja gra");

    XMapWindow(display, window);
    
    XSelectInput(display, window, KeyPressMask | ExposureMask | ButtonPressMask);
    XFlush(display);

    XEvent event;

    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDelete, 1);
    
    GC gc = XCreateGC(display, window, 0, nullptr);
    XSetWindowBackground(display,window,0x301050); //kolor tła


    while (true){

    XNextEvent(display, &event);
    XClearWindow(display, window);

    rysujTlo(display, window);
    rysujMenu(display, window, gc, menu);
    XFlush(display);



    
    //działanie przycisku
if (event.type == ButtonPress) {
    int mouseX = event.xbutton.x;
    int mouseY = event.xbutton.y;

    //Leave
    if (mouseX >= 100 &&
        mouseX <= 100 + menu.width &&
        mouseY >= 100 + menu.odstep &&
        mouseY <= 100 + menu.odstep + menu.height) {

        break;
    }
}

    //Zatrzymanie
    if (event.type == ClientMessage){
    
        break;
    }
}

}