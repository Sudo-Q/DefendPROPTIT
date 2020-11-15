//
// Created by duonglh on 08/11/2020.
//

#ifndef DEFENDERPRO_TAKECOINS_H
#define DEFENDERPRO_TAKECOINS_H

#include "Animation.h"
#include "cmath"
class TakeCoins {
    Animation animation;
    Sprite coin;
    Vector2f endPosition,velocity;
    unsigned short value;
public:
    TakeCoins();
    bool display;
    void setListTexture(vector<Texture>&);
    void setBeginPosition(Vector2f);
    void setEndPosition(Vector2f);
    void update(float,unsigned short&);
    void draw(RenderWindow&);
    void setValue(unsigned short);
    unsigned short getValue();
};


#endif //DEFENDERPRO_TAKECOINS_H
