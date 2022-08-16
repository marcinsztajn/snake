#include "include/apple.h"

/* Class constructor */
Apple::Apple()
{
    _y = 1;
    _x = 1;
    _icon = '#';
}

/* Class constructor */
Apple::Apple(int y, int x)
{
    _y = y;
    _x = x;
    _icon = '#';
}

/* Class constructor */
Apple::Apple(int y, int x, chtype ch)
{
    _y = y;
    _x = x;
    _icon = ch;
}