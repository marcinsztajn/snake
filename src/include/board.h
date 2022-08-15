#pragma once
#include <ncurses.h>
#include "drawable.h"

class Board
{
public:
    Board();
    Board(int height, int width);
    void addBorder();
    void clear();
    void refresh();
    void init();
    void addPoint(int y, int x, chtype ch);
    chtype getInput();
    void add(Drawable drawable);
    void getEmptyCoordinates(int &y, int &x);
    void setTimeout(int timeout);
    void setScore(int score);
    chtype getCharAt(int y, int x);
    int getWidth();
    int getHeight();

private:
    WINDOW *_board;
    int _max_y, _max_x, _center_y, _center_x, _height, _width;
};
