#include "include/snake_game.h"
#include <random>

/* Class constructor */
SnakeGame::SnakeGame(int height, int width){
    this->_board = Board(height, width);
    this->_board.init();
    this->_game_over = false;
    this->_apple = NULL;
    srand(time(NULL)); // seeds random number generator
    // initaialize snake
    snake.setDirection(Direction::down);
    std::string text;  
    
    /* Create the first piece */
    SnakePiece next = SnakePiece(3,1);  // starting point
    // text = "First piece: Y: " + std::to_string(next.getY()) + "  X: " + std::to_string(next.getX());
    // mvwaddstr(stdscr,0, 0, text.c_str());
    // wrefresh(stdscr);
    _board.add(next);
    snake.addPiece(next);

    /* Create the second piece of snake */
    next = snake.nextHead();
    _board.add(next);
    snake.addPiece(next);

    // text = "Second piece: Y: " + std::to_string(next.getY()) + "  X: " + std::to_string(next.getX());
    // mvwaddstr(stdscr,1, 0, text.c_str());
    // wrefresh(stdscr);
    
    /* Create the third piece of snake */
    next = snake.nextHead();
    _board.add(next);
    snake.addPiece(next);

    /* Create the fourth piece of snake */
    next = snake.nextHead();
    _board.add(next);
    snake.addPiece(next);

    /* Change snake direction to the right */
    snake.setDirection(Direction::right);

    /* Create the fifth piece of snake */
    next = snake.nextHead();
    _board.add(next);
    snake.addPiece(next);
    this->_board.refresh();

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
    if (this->_apple == NULL){
        int y, x;
        this->_board.getEmptyCoordinates(y, x);
        _apple = new Apple(y, x, 'A');
        this->_board.add(*_apple);
    }
    SnakePiece next = snake.nextHead();
    
    if(next.getX() != _apple->getX() && next.getY() != _apple->getY()){ /* if its blank spot*/
        int emptyRow = snake.tail().getY();
        int emptyCol = snake.tail().getX();
        // put the empty spot where the tail was
        this->_board.add(Empty(emptyRow, emptyCol));
        snake.removePiece();
    }
    this->_board.add(next);
    snake.addPiece(next);
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