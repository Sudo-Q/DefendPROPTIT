//
// Created by duonglh on 13/10/2020.
//

#include "Animation.h"

Animation::Animation () {
    currentFrame=0;
    totaltime=0;
    switchtime=0.1f;
    this->Scale=Vector2f(1,1);
}

void Animation::update(float deltatime) {
    totaltime+=deltatime;
    if(totaltime>=switchtime) {
        totaltime-=switchtime;
        currentFrame++;
        if (currentFrame > listTexture.size () - 1) {
            endOfListTexture=true;
            currentFrame = 0;
        }
        else endOfListTexture=false;
    }
}

void Animation::initSprite (Sprite &sprite) {
    sprite.setTextureRect(IntRect(0,0,listTexture[currentFrame].getSize().x,listTexture[currentFrame].getSize().y));
    sprite.setOrigin((Vector2f)listTexture[currentFrame].getSize()*0.5f);
    sprite.setScale(this->Scale);
}

void Animation::setSprite(Sprite &sprite) {
    sprite.setTexture(listTexture[currentFrame]);
}

Vector2u Animation::getCurrentSize() {
    return listTexture[currentFrame].getSize();
}

void Animation::setListTexture(vector<Texture> &lisTexture) {
    this->currentFrame=0;
    this->listTexture=lisTexture;
}

void Animation::setScale (Vector2f scale) {
    this->Scale=scale;
}

void Animation::setSwitchTime (float _switchTime) {
    this->switchtime=_switchTime;
}


//vector<Texture> Animation::getListTexture() {
//    return this->listTexture;
//}
