#include <X11/Xlib.h>
#include <iostream>

int main()
{
    int playerx = 100;
    int playery = 100;
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

XFillRectangle(
    display,
    window,
    gc,
    playerx, playery,
    50, 50
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
            
        }
        
    }

    //Zatrzymanie
    if (event.type == ClientMessage){
    
        break;
    }
}

}