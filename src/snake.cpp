#include "include/snake.h"

/* Snake piecie default constructor */
SnakePiece::SnakePiece(){
    this->_y = this->_x = 0;
    this->_icon = '#';
}

/* Snake piecie constructor */
SnakePiece::SnakePiece(int y, int x){
    this->_y = y;
    this->_x = x;
    this->_icon = '#';
}

/* Snake piece constructor */
SnakePiece::SnakePiece(int y, int x, chtype ch){
    this->_y = y;
    this->_x = x;
    this->_icon = ch;
}

/* Snake class default constructor */
Snake::Snake(){
    this->_snake_direction = down;
}

/* Add piece of body to the snake */
void Snake::addPiece(SnakePiece piece){
    this->_snake.push(piece);
}

/* Remove the piece of the snake's butt hehe */
void Snake::removePiece(){
    this->_snake.pop();
    /* https://stackoverflow.com/questions/71032192/does-pop-method-delete-the-object-from-the-memory */
}

/* Return the arsh of the snake's body */
SnakePiece Snake::tail(){
    return this->_snake.front();
}

/* Return the head of the snake */
SnakePiece Snake::head(){
    return this->_snake.back();
}

/* Get the snake's direction */
Direction Snake::getDirection() const{
    return this->_snake_direction;
}

/* Set snake's direction */
void Snake::setDirection(Direction direction){
    /* Check current direction and avoid going backwards */
    if (direction + this->_snake_direction != 0){ 
        this->_snake_direction = direction;
    }
}

/* Returns the next position of the Snake's head */
SnakePiece Snake::nextHead(){
    int row = this->head().getY();
    int col = this->head().getX();
    switch(this->_snake_direction){
        case down:
            row ++;
            if (row == (win_height - 1)){row = 1;}
        break;
        case up:
            row--;
            if (row == 0){row = win_height - 2 ;}
        break;
        case right:
            col++;
            if (col == (win_width - 1)) {col = 1;}
        break;
        case left:
            col--;
            if (col < 1) {col = win_width - 2;}
        break;
    }
    // TODO: modulo to overlap the board
    return SnakePiece(row, col);
}

/* Inform snake about the boarders of the window it moves in */
void Snake::setWindowSize(int width, int height){
    this->win_width = width;
    this->win_height = height;
}

/* Set default snake apperance */
void Snake::setDefaultSnakeChar(chtype ch){
    this->_snake_ch = ch;
}
