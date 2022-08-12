#include "include/drawable.h"

/* Class default constructor */
Drawable::Drawable(){
    this->_y = this->_x = 0;
    this->_icon = ' ';
}

/* Class constructor */
Drawable::Drawable(int y, int x, chtype ch){
    this->_y = y;
    this->_x = x;
    this->_icon = ch;
}

/* Get the X value */
int Drawable::getX(){
    return this->_x;
}

/* Get the Y value */
int Drawable::getY(){
    return this->_y;
}

/* Get the icon value */
chtype Drawable::getIcon(){
    return this->_icon;
}