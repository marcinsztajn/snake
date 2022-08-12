#include "include/snake_game.h"
#include "include/apple.h"
#include <random>

/* Class constructor */
SnakeGame::SnakeGame(int height, int width){
    this->_board = Board(height, width);
    this->_board.init();
    this->_game_over = false;
    srand(time(NULL)); // seeds random number generator
}

/* Get the input from the board */
void SnakeGame::processInput(){
    chtype inout = this->_board.getInput();
    // process the input
}

/* Update the state of the game */
void SnakeGame::updateState()
{
    int y, x;
    this->_board.getEmptyCoordinates(y, x);
    this->_board.add(Apple(y, x));
    this->_board.add(Drawable(3, 3, '#'));
}

/* Redraw the board surface/canvas*/
void SnakeGame::redraw()
{
    this->_board.refresh();
}

/* Chech if the game is over */
bool SnakeGame::isOver()
{
    return this->_game_over;
}