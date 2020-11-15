//
// Created by duonglh on 27/10/2020.
//

#include "Button.h"


bool Button::isOnButton (FloatRect& rectMouse) {
    if(this->getGlobalBounds().intersects(rectMouse)){
//        this->setScale(Vector2f(1.1,1.1));
        return true;
    }
//    this->setScale(Vector2f(1,1));
    return false;
}

bool Button::isClickButton (FloatRect& rectMouse) {
    if(Mouse::isButtonPressed(Mouse::Left) && this->getGlobalBounds().intersects(rectMouse) ){
        this->setScale(Vector2f(0.9,0.9));
        return true;
    }
    this->setScale(Vector2f(1,1));
    return false;
}

bool Button::isClickButton (Vector2f &mousePosition) {
    FloatRect rectMouse = FloatRect (mousePosition.x,mousePosition.y,0.001f,0.001f);
    if(this->getGlobalBounds().intersects(rectMouse) && Mouse::isButtonPressed(Mouse::Left)){
        this->setScale(Vector2f(0.9,0.9));
        return true;
    }
    this->setScale(Vector2f(1,1));
    return false;
}


