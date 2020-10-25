//
// Created by duonglh on 13/10/2020.
//

#include "Animation.h"


void Animation::update() {
    currentFrame++;
    if(currentFrame>listTexture.size()-1){
        currentFrame=0;
    }
}

void Animation::setSprite(Sprite & sprite) {
    sprite.setTexture(listTexture[currentFrame]);
    sprite.setTextureRect(IntRect(0,0,listTexture[currentFrame].getSize().x,listTexture[currentFrame].getSize().y));
    sprite.setOrigin((Vector2f)listTexture[currentFrame].getSize()*0.5f);
}

Vector2u Animation::getCurrentSize() {
    return listTexture[currentFrame].getSize();
}

void Animation::setListTexture(vector<Texture> lisTexture) {
    this->listTexture=lisTexture;
}

vector<Texture> Animation::getListTexture() {
    return this->listTexture;
}
