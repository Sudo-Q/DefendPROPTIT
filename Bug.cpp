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
    Scale=Vector2f(1,1);
    blooding.setScale(Vector2f(2,2));
    blooding.setSwitchTime(0.01f);
    beBlood=false;
    currentdirect=-1;
}

void Bug::setData (map<string,vector<Texture> > &data,vector<Texture> &bloodTexture) {
    this->Down=data.at("Down");
    this->Up=data.at("Up");
    this->Right=data.at("Right");
    this->Left=data.at("Left");
    this->blooding.setListTexture(bloodTexture);
    blooding.initSprite(spriteBlood);
}

void Bug::update(short direct,float deltatime) {// 0->down, 1->up, 2->left, 3->right
    if(currentdirect!=direct) {
        currentdirect=direct;
        velocity.x=velocity.y=0;
        if (currentdirect == 0) {
            currentAnimation.setListTexture (Down);
            velocity.y = speed;
        }
        if (currentdirect == 1) {
            currentAnimation.setListTexture (Up);
            velocity.y = -speed;
        }
        if (currentdirect == 2) {
            currentAnimation.setListTexture (Left);
            velocity.x = -speed;
        }
        if (currentdirect == 3) {
            currentAnimation.setListTexture (Right);
            velocity.x = speed;
        }
        Bound.setSize((Vector2f)currentAnimation.getCurrentSize()*Scale.x);
        Bound.setOrigin((Vector2f)Bound.getSize()*0.5f);
        currentAnimation.setScale(Scale);
        currentAnimation.initSprite(spriteBug);
    }
    currentAnimation.setSprite(spriteBug);
    currentAnimation.update(deltatime);
    spriteBug.move(velocity);
    Bound.setPosition(spriteBug.getPosition());
    barBlood.setPosition(Vector2f(spriteBug.getPosition().x,spriteBug.getPosition().y-Bound.getSize().y/2-10));
    Blood.setPosition(barBlood.getPosition().x-barBlood.getSize().x/2,barBlood.getPosition().y);

    if(beBlood){
        blooding.setSprite(spriteBlood);
        blooding.update(deltatime);
        spriteBlood.setPosition(spriteBug.getPosition());
        if(blooding.endOfListTexture) beBlood=false;
    }
}

void Bug::draw(RenderWindow &window) {
    window.draw(spriteBug);
    window.draw(barBlood);
    window.draw(Blood);
    if(beBlood) window.draw(spriteBlood);
//    window.draw(Bound);
}

void Bug::beDamage(pair<float,float> &damage) {
    //  first = damage ; second = trueDamage
    this->beBlood=true;
    if(damage.first>armor && blood>0){
        blood=blood-(damage.first-armor);
    }
//    else this->beBlood=false;
    if(blood>0) blood-=damage.second;
    //    else this->beBlood=false;
    if(damage.first<armor && damage.second==0 && blood > 0)
        blood-=1;
    Blood.setSize(Vector2f(blood*100/baseBlood,10));
}

void Bug::setArmor(float _armor) {
    this->armor=_armor;
}

bool Bug::isAlive() const {
    return blood>0;
}

void Bug::setBlood(float _baseBlood) {
    this->baseBlood=_baseBlood;
    this->blood=_baseBlood;
    Blood.setSize(Vector2f(blood*100/baseBlood,10));
}

Vector2f Bug::getPosition() {
    return spriteBug.getPosition();
}

FloatRect Bug::getBound() {
    return Bound.getGlobalBounds();
}

void Bug::setPosition(Vector2f position) {
    spriteBug.setPosition(position);
    Bound.setPosition(spriteBug.getPosition());
    barBlood.setPosition(Vector2f(spriteBug.getPosition().x,spriteBug.getPosition().y-Bound.getSize().y/2-10));
    Blood.setPosition(barBlood.getPosition().x-barBlood.getSize().x/2,barBlood.getPosition().y);
    spriteBlood.setPosition(spriteBug.getPosition());
}

void Bug::setSpeed (float _speed) {
    this->speed=_speed;
}

float Bug::getSpeed () const {
    return this->speed;
}

void Bug::setScale (Vector2f _scale) {
    this->Scale=_scale;
}

float Bug::getBlood () const {
    return this->baseBlood;
}







