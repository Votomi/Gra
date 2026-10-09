#include <X11/Xlib.h>
#include <iostream>
#include "Enemy.h"
#include "info.h"

int main()
{
    Info info;
    Enemy enemy;
    int playerx = 100;
    int playery = 100;
    int playersize = 50;
    
    Display* display = XOpenDisplay(nullptr);

    if (display == nullptr)
        return 1;

    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(

        display,
        RootWindow(display, screen),
        100, 100,
        1280, 720,
        1,
        BlackPixel(display, screen),
        WhitePixel(display, screen)
    );
    XStoreName(display, window, "Moja gra");

    XMapWindow(display, window);
    
    XSelectInput(display, window, KeyPressMask | ExposureMask);
    XFlush(display);

    XEvent event;

    Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDelete, 1);
    
    GC gc = XCreateGC(display, window, 0, nullptr);
    while (true){

    XNextEvent(display, &event);
    XClearWindow(display, window);
//ty
XFillRectangle(
    display,
    window,
    gc,
    playerx, playery,
    playersize, playersize
);
//przeciwnik
XFillRectangle(
    display,
    window,
    gc,
    enemy.x, enemy.y,
    enemy.size, enemy.size
);
//kolor czerowny
XSetForeground(display, gc, 0xFF0000);
//ramka info
XFillRectangle(
    display,
    window,
    gc,
    info.x, info.y,
    info.width, info.height
);

XFlush(display);
    //klaiwatura
    if (event.type == KeyPress){
    //Symbol klawisza
    char key = XLookupKeysym(&event.xkey, 0);
    //Sterowanie oknem
        if (key == 'd'){
            playerx += 5;
        }else if (key == 'w'){
            playery -= 5;
        } else if(key =='s'){
            playery +=5;
        }else if(key == 'a'){
            playerx -=5;
            
        }else if (key =='r'){
            if(playersize > 0){
                playersize -= 5;
            }
        }else if(key == 'f'){
            if(playersize <= 250){
                playersize += 5;
            }
        }
        
    }

    //Zatrzymanie
    if (event.type == ClientMessage){
    
        break;
    }
}

}