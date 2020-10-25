//
// Created by duonglh on 16/10/2020.
//

#include "Bullet.h"
#include <cmath>
Bullet::Bullet() {

//    bullet.setFillColor(Color::Yellow);
    this->disappear=false;
    velocity.x=velocity.y=0;
    speed=1;
}

void Bullet::setDamage(int damage) {
    this->damage=damage;
}

int Bullet::getDamage() {
    return this->damage;
}

void Bullet::update() {
    if(distance<0)
        disappear=true;
    distance-=sqrt(velocity.x*velocity.x+velocity.y*velocity.y)*speed;
    bullet.move(velocity*speed);
}

void Bullet::draw(RenderWindow &window) {
    window.draw(bullet);
}

FloatRect Bullet::getBound() {
    return bullet.getGlobalBounds();
}

void Bullet::setTexture(Texture texture) {
    this->texture=texture;
    this->texture.setSmooth(true);
    bullet.setTexture(&this->texture);
    bullet.setSize((Vector2f)this->texture.getSize());
    bullet.setScale(0.3f,0.3f);
}

void Bullet::setSpeed(float speed) {
    this->speed=speed;
}

void Bullet::setTrajectory (Vector2f start, Vector2f end) {
    float vtx=end.x-start.x;
    float vty=end.y-start.y;
    distance=sqrt(vtx*vtx + vty*vty);
    velocity.x=vtx/distance;
    velocity.y=vty/distance;
    bullet.setPosition(start);
}


