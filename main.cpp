#include <iostream>
#include <string>
#include <ncurses.h>
#include <stdexcept>
#include "snake.hpp"

#define BOARD_SIZE 20
#define BOARD_WIDTH (BOARD_SIZE * 2.5)
#define BOARD_HEIGHT BOARD_SIZE

using namespace std;

// https://invisible-island.net/ncurses/man/ncurses.3x.html


int main (int argc, char ** argv){
    initscr();
    refresh();
    cbreak(); // works by deafult
    noecho(); // we want it

    // let get the dimension of the current window
    int max_y,max_x;
    getmaxyx(stdscr, max_y,max_x);
    if (max_y < BOARD_HEIGHT || max_x < BOARD_SIZE) {
        throw std::runtime_error("Please increase your console window size to at least " + std::to_string(BOARD_SIZE) + " in both dimensions");
    }

    SnakeGame *game = new SnakeGame(BOARD_HEIGHT, BOARD_WIDTH);
    
    while(!game->isOver()){
        game->processInput();

        game->updateState();

        game->redraw();
    }

    // Board* board = new Board(BOARD_HEIGHT, BOARD_WIDTH);
    // board->init();
    // board->addPoint(5, 5, '#');
    // board->refresh();

    // 1: get input from the user

    // 2: update game state

    // 3: redraw display

    // 4: go ro 1, unless game over


    getch();
    endwin();
    
}

/*
cbreak() - when prsssing CTRL + C program is closing
raw() - allows to print 
noecho() - when user puts something in the screen program do not prints it out
mvwaddch() - put the character into the given window at its current window position, which is then advanced
    
)
*/