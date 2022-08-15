#include "include/drawable.h"

/* Class default constructor */
Drawable::Drawable(): _y(0), _x(0), _icon(' '){}

/* Class constructor */
Drawable::Drawable(const int y,const int x, chtype ch): _y(y), _x(x), _icon(ch) {}

/* Get the X value */
int Drawable::getX() const{
    return this->_x;
}

/* Get the Y value */
int Drawable::getY() const{
    return this->_y;
}

/* Get the icon value */
chtype Drawable::getIcon() const{
    return this->_icon;
}

/* Set coordinates for the drawable object */
void Drawable::setPosition(int y, int x){
    this->_y = y;
    this->_x = x; 
}