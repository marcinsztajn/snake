#pragma once
#include "board.h"
#include "apple.h"
#include "snake.h"
#include "empty.h"
#include <ncurses.h>
#include <stdexcept>

/* Main controller class */
class SnakeGame{
public:
    SnakeGame(int height, int width);
    ~SnakeGame();
    void processInput();
    void updateState();
    void redraw();
    bool isOver();
    int getScore();
    void setSnakeChar(chtype ch);
    void setAppleChar(chtype ch);
    chtype getSnakeChar();
    chtype getAppleChar();
private:
    void initSnake(int y, int x);
    void createApple();
    void destroyApple();
    void handleNextPiece(SnakePiece next);
    Board _board;
    bool _game_over;
    Apple *_apple;
    Snake snake;
    int score = 0;
    chtype _snake_sym = '#';
    chtype _apple_sym = 'A';
};