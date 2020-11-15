//
// Created by duonglh on 16/10/2020.
//

#ifndef DEFENDERPRO_BULLET_H
#define DEFENDERPRO_BULLET_H

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
class Bullet {
private:
    Sprite bullet;
    Texture currentTexture;
    float damage,trueDamage;
    Vector2f velocity;
    float speed,distance;
    std::pair<float,float> totalDamage;

public:
    Bullet();
    bool isFire;
    void setTexture (Texture&);
    void setDamage(float);
    std::pair<float,float>& getDamage();
    void setTrajectory(Vector2f,Vector2f);// set quy dao chuyen dong
    void update();
    void draw(RenderWindow&);
    FloatRect getBound();
    void setSpeed(float);
    void addDamage(float);
    void addTrueDamage(float);
    void addSpeed(float);
    void setPosition(Vector2f);
};


#endif //DEFENDERPRO_BULLET_H
