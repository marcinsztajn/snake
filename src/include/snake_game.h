#pragma once
#include "board.h"
#include "apple.h"
#include "snake.h"
#include "empty.h"
#include <ncurses.h>

/* Main controller class */
class SnakeGame{
public:
    SnakeGame(int height, int width);
    ~SnakeGame();
    void processInput();
    void updateState();
    void redraw();
    bool isOver();
private:
    Board _board;
    bool _game_over;
    Apple *_apple;
    Snake snake;
};