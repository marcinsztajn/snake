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

/* Snake piecie constructor */
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
}

/* Return the arsh of the snake's body */
SnakePiece Snake::tail(){
    return this->_snake.back();
}

/* Return the head of the snake */
SnakePiece Snake::head(){
    return this->_snake.front();
}