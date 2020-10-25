//
// Created by duonglh on 16/10/2020.
//

#ifndef DEFENDERPRO_BULLET_H
#define DEFENDERPRO_BULLET_H

#include "SFML/Graphics.hpp"
using namespace sf;
class Bullet {
private:
    RectangleShape bullet;
    Texture texture;
    int damage;
    Vector2f velocity;
    float speed,distance;

public:
    Bullet();
    bool disappear;
    void setTexture (Texture);
    void setDamage(int);
    int getDamage();
    void setTrajectory(Vector2f,Vector2f);// set quy dao chuyen dong
    void update();
    void draw(RenderWindow&);
    FloatRect getBound();
    void setSpeed(float);
};


#endif //DEFENDERPRO_BULLET_H
