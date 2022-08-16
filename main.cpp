#include <iostream>
#include <string>
#include <ncurses.h>
#include <stdexcept>
#include "src/include/snake_game.h"

#define BOARD_SIZE 20
#define BOARD_WIDTH (BOARD_SIZE * 2.5)
#define BOARD_HEIGHT BOARD_SIZE

using namespace std;

// https://invisible-island.net/ncurses/man/ncurses.3x.html

chtype apple_ch = 'O';
chtype snake_ch = '#';

int main(int argc, char **argv)
{
    initscr();
    refresh();
    cbreak();    // works by deafult
    noecho();    // we want it
    curs_set(0); // hide the cursor

    // get the dimension of the current window
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    if (max_y < BOARD_HEIGHT || max_x < BOARD_SIZE)
    {
        throw std::runtime_error("Please increase your console window size to at least " + std::to_string(BOARD_SIZE) + " in both dimensions");
    }

    SnakeGame *game = new SnakeGame(BOARD_HEIGHT, BOARD_WIDTH);

    while (!game->isOver())
    {
        game->processInput();

        game->updateState();

        game->redraw();
    }

    endwin();
    cout << "Game over! Your score was: " << game->getScore();
    cout << "" << endl;
}
