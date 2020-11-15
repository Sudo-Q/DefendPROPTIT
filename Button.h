//
// Created by duonglh on 27/10/2020.
//

#ifndef DEFENDERPRO_BUTTON_H
#define DEFENDERPRO_BUTTON_H
#include "SFML/Graphics.hpp"
using namespace sf;
class Button : public Sprite{
public:
    Button(){};
    bool isOnButton(FloatRect&);
    bool isClickButton(FloatRect&);
    bool isClickButton(Vector2f&);
};


#endif //DEFENDERPRO_BUTTON_H
