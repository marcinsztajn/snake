//here will be classes and functions
#include <string>
#include <iostream>
#include <ncurses.h>

class Board
{
public:
    Board(int height, int width){
        getmaxyx(stdscr, this->max_y,this->max_x);
        center_y = max_y/2;
        center_x = max_x/2;
        this->height = height;
        this->width = width;
        board = newwin(height,width,center_y - height/2, center_x - width/2);
        // this->addBorder();
        // this->refresh();
    }
    
    /* Method draws the border around the board*/
    void addBorder(){
        box(board,0,0);
    }
    /* Method clears the board and redraws the boarder*/
    void clear(){
       wclear(board); 
       this->addBorder();
    }
    /* Method refreshes the border*/
    void refresh(){
        wrefresh(board);
    }
    /* Method to init*/
    void init(){
        this->clear();
        this->refresh();
    }
    /* Add the char at given point on the board*/
    void addPoint(int y, int x, chtype ch){
        mvwaddch(board, y, x, ch);
    }

    /* Get input from the user*/
    chtype getInput(){
        return wgetch(board);
    }

private:
    WINDOW *board;
    int max_y, max_x, center_y, center_x, height, width;
};