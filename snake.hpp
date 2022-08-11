//here will be classes and functions
#include <string>
#include <iostream>
#include <ncurses.h>


/* TODO:
 - underscore private class members
*/

class Board
{
public:
    /* Default constructor*/
    Board(){
        Board(0,0);        
    }

    Board(int height, int width){
        getmaxyx(stdscr, this->max_y,this->max_x);
        center_y = max_y/2;
        center_x = max_x/2;
        this->height = height;
        this->width = width;
        _board = newwin(height,width,center_y - height/2, center_x - width/2);
        // this->addBorder();
        // this->refresh();
    }
    
    /* Method draws the border around the _board*/
    void addBorder(){
        box(_board,0,0);
    }
    /* Method clears the _board and redraws the _boarder*/
    void clear(){
       wclear(_board); 
       this->addBorder();
    }
    /* Method refreshes the border*/
    void refresh(){
        wrefresh(_board);
    }
    /* Method to init*/
    void init(){
        this->clear();
        this->refresh();
    }
    /* Add the char at given point on the _board*/
    void addPoint(int y, int x, chtype ch){
        mvwaddch(_board, y, x, ch);
    }

    /* Get input from the user*/
    chtype getInput(){
        return wgetch(_board);
    }

private:
    WINDOW *_board;
    int max_y, max_x, center_y, center_x, height, width;
};

/* Main controller class */
class SnakeGame{
public:
    SnakeGame(int height, int width){
        _board = Board(height, width);
        _board.init();
        _game_over = false;
    }
    /* Get the input from the board*/
    void processInput()
    {
        chtype inout = _board.getInput();
        // process the input
    }
    /* Update the state of the game */
    void updateState()
    {
        // update state
    }
    void redraw()
    {
        _board.refresh();
    }
    bool isOver()
    {
        return _game_over;
    }
private:
    Board _board;
    bool _game_over;
};