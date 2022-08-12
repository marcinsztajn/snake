#pragma once
#include <ncurses.h>

/* Base class for Apple and Snake object */
class Drawable{
public:
    Drawable();
    Drawable(int y, int x, chtype ch);
    int getX();
    int getY();
    chtype getIcon();

protected:
    int _y, _x;
    chtype _icon;
};