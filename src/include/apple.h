#pragma once
#include "drawable.h"

/* Apple class - the Snake's foodiee :D */
class Apple : public Drawable
{
public:
    Apple();
    Apple(int y, int x);
    Apple(int y, int x, chtype ch);
};