#pragma once
#include "drawable.h"

/* Helpfull when we you want to place a blank pixel/character in the window*/
class Empty : public Drawable
{
public:
    Empty(int y, int x);
};