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
    int currentFrame;
public:
    Animation(){
        currentFrame=0;
    };
    void update();
    void setSprite(Sprite&);
    Vector2u getCurrentSize();
    void setListTexture(vector<Texture>);
    vector<Texture> getListTexture();
};


#endif //DEFENDERPRO_ANIMATION_H
