//
// Created by duonglh on 16/10/2020.
//

#ifndef DEFENDERPRO_SHOOTER_H
#define DEFENDERPRO_SHOOTER_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Bullet.h"
#include <cmath>
using namespace std;
using namespace sf;
class Shooter {
private:
    CircleShape range;
    RectangleShape person,bound;
    Vector2f shootPosition,targetPosition;
    vector<Bullet> listBullet;
    vector<Texture> listBulletTexture;
    vector<int> levelBullet;
    bool fire;
    float fireTime,totalTime;
public:
    Shooter();
    void setTexture(short,Texture&, vector<Texture>&);
    void setPosition(Vector2f);
    Vector2f getPosition();
    void setRange(float);
    bool update(Vector2f,float);
    void draw(RenderWindow&,bool);
    void setFireTime(float);
    void setDamageForBullet(float);
    void buff(float,float,float,float);
    void setTrueDamage(float);
    pair<float,float>& getAllDamage();
    bool checkCollision(FloatRect);
    void setSpeedForBullet(float);
    FloatRect getShooterBound();
    void updateBullet();
    bool playShootMusic();

};


#endif //DEFENDERPRO_SHOOTER_H
