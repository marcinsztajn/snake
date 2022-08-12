#pragma once
#include <ncurses.h>
#include <queue>
#include "drawable.h"


enum Direction{
    up, down, left, right
};

/* Snake piece class */
class SnakePiece : public Drawable
{
public:
    SnakePiece();
    SnakePiece(int y, int x);
    SnakePiece(int y, int x, chtype ch);
};

/* Snake class */
class Snake
{
public:
    Snake();
    void addPiece(SnakePiece piece);
    void removePiece();
    SnakePiece tail();
    SnakePiece head();
private:
    std::queue<SnakePiece> _snake;
    Direction _snake_direction;
};

