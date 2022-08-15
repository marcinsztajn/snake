#include "include/snake_game.h"
#include <random>

/* Class constructor */
SnakeGame::SnakeGame(int height, int width){
    this->_board = Board(height, width);
    this->_board.init();
    this->_board.setScore(score);
    this->_game_over = false;
    this->_apple = NULL;
    srand(time(NULL)); // seeds random number generator
    this->initSnake(1,1);

}

/* Class destructor */
SnakeGame::~SnakeGame(){
    if (this->_apple != NULL){
        delete this->_apple;
    }
}

/* Get the input from the board */
void SnakeGame::processInput(){
    chtype input = this->_board.getInput();
    switch(input){
        case KEY_UP:
            this->snake.setDirection(Direction::up);
        break;
        case KEY_DOWN:
            this->snake.setDirection(Direction::down);
        break;
        case KEY_LEFT:
            this->snake.setDirection(Direction::left);
        break;
        case KEY_RIGHT:
            this->snake.setDirection(Direction::right);
        break;
        case 'p':
            this->_board.setTimeout(-1); // wait forever until the user press the 'p' key
            while(this->_board.getInput() != 'p'); 
            this->_board.setTimeout(500); // come back to the old timeout settings
        break ;
    }
}

/* Update the state of the game */
void SnakeGame::updateState()
{    
    // SnakePiece next = snake.nextHead();
    handleNextPiece(snake.nextHead());
    if (this->_apple == NULL) { createApple();}
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
 
/* Initialize snake object */
void SnakeGame::initSnake(int y, int x){
    // initaialize snake
    snake.setDirection(Direction::down);
    
    /* Create the first piece */
    // SnakePiece next = SnakePiece(y,x);  // starting point
    handleNextPiece(SnakePiece(y,x));
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());
    handleNextPiece(snake.nextHead());
    snake.setDirection(Direction::right);
    handleNextPiece(snake.nextHead());

    // text = "Second piece: Y: " + std::to_string(next.getY()) + "  X: " + std::to_string(next.getX());
    // mvwaddstr(stdscr,1, 0, text.c_str());
    // wrefresh(stdscr);
    
    this->_board.refresh();

    createApple();

    snake.setWindowSize(this->_board.getWidth(), this->_board.getHeight());

}
/* Function create an apple */
void SnakeGame::createApple(){
    /* Add the apple here */
    int ay, ax;
    this->_board.getEmptyCoordinates(ay, ax);
    if(this->_apple != NULL){
        throw std::runtime_error("Free apple's memory before creating new one!");
    }
    this->_apple = new Apple(ay, ax, 'A');
    this->_board.add(*this->_apple);
    this->_board.refresh();  
}

/* Function destroys an apple */
void SnakeGame::destroyApple(){
    if (this->_apple != NULL){
        delete this->_apple;
        this->_apple = NULL;
    }
}

/* Handle moving the snake aka adding new pieces to his body */
void SnakeGame::handleNextPiece(SnakePiece next){
    if (this->_apple != NULL){
        /* Chech next head position */
        switch(this->_board.getCharAt(next.getY(), next.getX())){
            case 'A':
            /* If there is an apple */
            destroyApple();
            score++;
            _board.setScore(score);
            break;
            case ' ':
            {
            /* if there is a free spot */
            int emptyRow = snake.tail().getY();
            int emptyCol = snake.tail().getX();
            // put the empty spot where the tail was
            this->_board.add(Empty(emptyRow, emptyCol));
            snake.removePiece(); // drop the tail of the snake
            break;
            }
            case '#':
            /* Colission with its body */
            _game_over = true;
        }
    }
    
    this->_board.add(next);
    snake.addPiece(next);
    _board.refresh();

}

/* Get the game score */
int SnakeGame::getScore(){
    return this->score;
}

/* Set the snake piece symbol */
void SnakeGame::setSnakeChar(chtype ch){
    this->_snake_sym = ch;
}

/* Set the apple symbol */
void SnakeGame::setAppleChar(chtype ch){
    this->_apple_sym = ch;
}