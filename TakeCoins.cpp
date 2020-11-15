//
// Created by duonglh on 08/11/2020.
//

#include "TakeCoins.h"

TakeCoins::TakeCoins () {
    display=false;
}

void TakeCoins::setListTexture (vector<Texture> &listTexture) {
    animation.setListTexture(listTexture);
}

void TakeCoins::setBeginPosition (Vector2f _beginPosition) {
    coin.setPosition(_beginPosition);
    float vtx=endPosition.x-_beginPosition.x;
    float vty=endPosition.y-_beginPosition.y;
    float distance=std::sqrt(vtx*vtx + vty*vty);
    velocity.x=vtx/distance;
    velocity.y=vty/distance;
}

void TakeCoins::setEndPosition (Vector2f _endPosition) {
    endPosition=_endPosition;
}

void TakeCoins::update (float deltaTime,unsigned short &coins) {
    animation.setSprite(coin);
    animation.update(deltaTime);
    coin.move(velocity*15.f);
    if(coin.getPosition().x>=endPosition.x) {
        display=false;
        coins+=value;
        value=0;
    }
}

void TakeCoins::draw (RenderWindow &window) {
    window.draw(coin);
}

void TakeCoins::setValue (unsigned short _value) {
    this->value=_value;
}

unsigned short TakeCoins::getValue () {
    return this->value;
}
