#include "include/snake_game.h"
#include "include/apple.h"
#include "include/empty.h"
#include <random>

/* Class constructor */
SnakeGame::SnakeGame(int height, int width){
    this->_board = Board(height, width);
    this->_board.init();
    this->_game_over = false;
    srand(time(NULL)); // seeds random number generator
}

/* Class destructor */
SnakeGame::~SnakeGame(){
    if (this->_apple != NULL){
        delete this->_apple;
    }
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
    if (_apple != NULL){                                             /* if there is already an apple on the board*/
        _board.add(Empty(_apple->getY(), _apple->getX()));            /* add an empty space in this spot */
        delete _apple;
    }
    _apple = new Apple(y, x);
    this->_board.add(*_apple);
    // this->_board.add(Drawable(3, 3, '#'));
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