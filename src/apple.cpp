#include "include/apple.h"

/* Class constructor */
Apple::Apple(int y, int x){
    this->_y = y;
    this->_x = x;
    this->_icon = 'A';   // hardcoded here - consider set/get method in future
}