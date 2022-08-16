#include "include/board.h"
#include <random>

/* Class default constructor */
Board::Board()
{
    Board(0, 0);
}

/* Class constructor */
Board::Board(int height, int width)
{
    getmaxyx(stdscr, this->_max_y, this->_max_x);
    this->_center_y = this->_max_y / 2;
    this->_center_x = this->_max_x / 2;
    this->_height = height;
    this->_width = width;
    _board = newwin(height, width, this->_center_y - this->_height / 2, this->_center_x - this->_width / 2);
    wtimeout(this->_board, 500); // refreshing the screen
    /* Enable the keypad of the user's terminal*/
    keypad(this->_board, true);
}

/* Method draws the border around the _board*/
void Board::addBorder()
{
    box(_board, 0, 0);
}

/* Method clears the _board and redraws the _boarder*/
void Board::clear()
{
    wclear(this->_board);
    this->addBorder();
}

/* Method refreshes the border*/
void Board::refresh()
{
    wrefresh(this->_board);
}

/* Method to init*/
void Board::init()
{
    this->clear();
    this->refresh();
}

/* Add the char at given point on the _board*/
void Board::addPoint(int y, int x, chtype ch)
{
    mvwaddch(this->_board, y, x, ch);
}

/* Get input character from the curses terminal keyboard*/
chtype Board::getInput()
{
    return wgetch(this->_board);
}

/* Allows to pass a Snake or Apple and draw at*/
void Board::add(Drawable drawable)
{
    this->addPoint(drawable.getY(), drawable.getX(), drawable.getIcon());
}

/* Get empty coordinates where to place an Apple*/
void Board::getEmptyCoordinates(int &y, int &x)
{
    /* One-liner which runs until it finds the empty spot on the board */
    while (mvwinch(this->_board, y = (rand() % this->_height), x = (rand() % this->_width)) != ' ')
        ;
}

/* Set the input timeout */
void Board::setTimeout(int timeout)
{
    wtimeout(this->_board, timeout);
}

/* Set the game score */
void Board::setScore(int score)
{
    std::string txt = "Score: " + std::to_string(score);
    mvwaddstr(stdscr, _center_y + _height / 2, _center_x - _width / 2, txt.c_str());
    wrefresh(stdscr);
}

/* Get the character and given coordinates */
chtype Board::getCharAt(int y, int x)
{
    return mvwinch(this->_board, y, x);
}

/* Get board's width */
int Board::getWidth()
{
    return this->_width;
}

/* Get board's height */
int Board::getHeight()
{
    return this->_height;
}