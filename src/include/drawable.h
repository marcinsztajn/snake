#pragma once
#include <ncurses.h>

/* Base class for Apple and Snake object */
class Drawable{
public:
    Drawable();
    Drawable(const int y, const int x, const chtype ch);
    int getX() const;
    int getY() const;
    chtype getIcon() const;
    void setPosition(int y, int x);

protected:
    int _y, _x;
    chtype _icon;
};