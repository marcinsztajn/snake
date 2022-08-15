cmake_minimum_required(VERSION 3.16) 
project(Snake VERSION 1.0.0)
add_executable(snake main.cpp src/apple.cpp src/board.cpp src/drawable.cpp src/empty.cpp src/snake_game.cpp src/snake.cpp)
target_link_libraries(snake -lncurses)

