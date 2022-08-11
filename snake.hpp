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
        board = newwin(height,width,center_y - height/2, center_x - width/2);
        box(board,0,0);
        wrefresh(board);
        this->height = height;
        this->width = width;
    }
private:
    WINDOW *board;
    int max_y, max_x, center_y, center_x, height, width;
};