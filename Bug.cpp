//
// Created by duonglh on 16/10/2020.
//

#include "Bug.h"


Bug::Bug() {
    barBlood.setSize(Vector2f(100,10));
    barBlood.setOrigin((Vector2f)barBlood.getSize()*0.5f);
    barBlood.setOutlineThickness(1.0f);
    barBlood.setOutlineColor(Color::Black);
    blood=100;
    Blood.setSize(Vector2f(blood,10));
    Blood.setFillColor(Color::Red);
    Blood.setOrigin(Vector2f(0,5));
    Bound.setOutlineThickness(1.0f);
    Bound.setFillColor(Color(0,0,0,0));
}

void Bug::setData (map<string,vector<Texture> > data) {
    this->Down=data.at("Down");
    this->Up=data.at("Up");
    this->Right=data.at("Right");
    this->Left=data.at("Left");
}

void Bug::update(int direct) {// 0->down, 1->up, 2->left, 3->right
//    velocity.x=velocity.y=0;
    if(direct==0){
        currentAnimation.setListTexture(Down);
        velocity.y=speed;
    }
    if(direct==1){
        currentAnimation.setListTexture(Up);
        velocity.y=-speed;
    }
    if(direct==2){
        currentAnimation.setListTexture(Left);
        velocity.x=-speed;
    }
    if(direct==3){
        currentAnimation.setListTexture(Right);
        velocity.x=speed;
    }
    currentAnimation.setSprite(sprite);
    currentAnimation.update();
    sprite.move(velocity);
    Bound.setSize((Vector2f)currentAnimation.getCurrentSize());
    Bound.setOrigin((Vector2f)Bound.getSize()*0.5f);
    Bound.setPosition(sprite.getPosition());
    barBlood.setPosition(Vector2f(sprite.getPosition().x,sprite.getPosition().y-currentAnimation.getCurrentSize().y/2-10));
    Blood.setPosition(barBlood.getPosition().x-barBlood.getSize().x/2,barBlood.getPosition().y);
}

void Bug::draw(RenderWindow &window) {
    window.draw(sprite);
    window.draw(barBlood);
    window.draw(Blood);
    window.draw(Bound);
}

void Bug::beDamage(int damage) {
    if(damage>armor && blood){
        blood=blood-(damage-armor);
    }
    Blood.setSize(Vector2f(blood*100/baseBlood,10));
}

void Bug::setArmor(int armor) {
    this->armor=armor;
}

bool Bug::isAlive() {
    return blood>0;
}

void Bug::setBlood(int baseBlood) {
    this->baseBlood=baseBlood;
    this->blood=baseBlood;
    Blood.setSize(Vector2f(blood*100/baseBlood,10));
}

Vector2f Bug::getPosition() {
    return sprite.getPosition();
}

RectangleShape Bug::getBound() {
    return Bound;
}

void Bug::setPosition(Vector2f position) {
    sprite.setPosition(position);
}

void Bug::setSpeed (float speed) {
    this->speed=speed;
}







