//
// Created by duonglh on 16/10/2020.
//

#include "Bullet.h"
#include <cmath>
Bullet::Bullet() {
    this->isFire=false;
    velocity.x=velocity.y=0;
    speed=1;
    trueDamage=0;
}

void Bullet::setDamage(float _damage) {
    this->damage=_damage;
}

std::pair<float,float>& Bullet::getDamage(){
    totalDamage.first=this->damage;
    totalDamage.second=this->trueDamage;
    return totalDamage;
//    std::pair<float,float> tmp;
//    tmp.first=this->damage;
//    tmp.second=this->trueDamage;
//    return tmp;
//    return std::make_pair(damage,trueDamage);
}

void Bullet::update() {
    if(distance<=0) isFire = false;
    distance-=std::sqrt(velocity.x*velocity.x+velocity.y*velocity.y)*speed;
    bullet.move(velocity*speed);
}

void Bullet::draw(RenderWindow &window) {
    window.draw(bullet);
}

FloatRect Bullet::getBound() {
    return bullet.getGlobalBounds();
}

void Bullet::setTexture(Texture &texture) {
    bullet.setTexture(texture);
    bullet.setTextureRect(IntRect(0,0,texture.getSize().x,texture.getSize().y));
    bullet.setScale(Vector2f(0.4,0.4));
    bullet.setOrigin((Vector2f)texture.getSize()*0.5f);
}

void Bullet::setSpeed(float speed) {
    this->speed=speed;
}

void Bullet::setTrajectory (Vector2f start, Vector2f end) {
    float vtx=end.x-start.x;
    float vty=end.y-start.y;
    distance=std::sqrt(vtx*vtx + vty*vty);
    velocity.x=vtx/distance;
    velocity.y=vty/distance;
    bullet.setPosition(start);
}

void Bullet::addDamage (float _damage) {
    this->damage+=_damage;
}

void Bullet::addTrueDamage (float _trueDamage) {
    this->trueDamage+=_trueDamage;
}

void Bullet::addSpeed (float _speed) {
    this->speed+=_speed;
}


void Bullet::setPosition (Vector2f position) {
    bullet.setPosition(position);
}
