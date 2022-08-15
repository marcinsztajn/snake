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
            if (this->_snake_direction == Direction::down){ row ++; }
        break;
        case up:
            if (this->_snake_direction == Direction::up){ row--; }
        break;
        case right:
            if (this->_snake_direction == Direction::right){ col++; }
        break;
        case left:
            if (this->_snake_direction == Direction::left){ col--; }
        break;
    }
    return SnakePiece(row, col);
}
