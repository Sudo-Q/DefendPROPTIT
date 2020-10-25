//
// Created by duonglh on 16/10/2020.
//

#ifndef DEFENDERPRO_SHOOTER_H
#define DEFENDERPRO_SHOOTER_H
#include "SFML/Graphics.hpp"
#include "Bullet.h"
#include <cmath>
using namespace sf;
class Shooter {
private:
    CircleShape range,circle,Circle;
    Bullet bullet;
    RectangleShape person;
    Texture texture;
    Vector2f shootPosition,targetPosition;
    bool fire;
public:
    Shooter();
    void setTexture(Texture, Texture);
    void setPosition(Vector2f);
    void setRange(float);
    void update(Vector2f);
    void setTrajectoryOfBullet(Vector2f);
    void setSpeedForBullet(float);
    void setDamageForBullet(int);
    Bullet getBullet();
    void draw(RenderWindow&,bool);


};


#endif //DEFENDERPRO_SHOOTER_H
