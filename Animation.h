//
// Created by duonglh on 13/10/2020.
//

#ifndef DEFENDERPRO_ANIMATION_H
#define DEFENDERPRO_ANIMATION_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>
using namespace sf;
using namespace std;
class Animation {
private:
    vector<Texture> listTexture;
    short currentFrame;
    float totaltime,switchtime;
    Vector2f Scale;

public:
    Animation();
    bool endOfListTexture;
    void update(float);
    void initSprite(Sprite&);
    void setSprite(Sprite&);
    Vector2u getCurrentSize();
    void setListTexture(vector<Texture>&);
    void setScale(Vector2f);
    void setSwitchTime(float);
//    vector<Texture> getListTexture();
};


#endif //DEFENDERPRO_ANIMATION_H
