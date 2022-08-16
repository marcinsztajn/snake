#pragma once
#include <ncurses.h>
#include <queue>
#include "drawable.h"

enum Direction
{
    up = -1,
    down = 1,
    left = -2,
    right = 2
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
    Direction getDirection() const;
    void setDirection(Direction direction);
    SnakePiece nextHead();
    void setWindowSize(int width, int height);
    void setDefaultSnakeChar(chtype ch);

private:
    std::queue<SnakePiece> _snake;
    Direction _snake_direction;
    int win_width, win_height;
    chtype _snake_ch;
};
