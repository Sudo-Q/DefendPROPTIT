//
// Created by duonglh on 16/10/2020.
//

#ifndef DEFENDERPRO_BUG_H
#define DEFENDERPRO_BUG_H
#include "Animation.h"
#include <cmath>
#include <vector>
class Bug {
private:
    Sprite spriteBug,spriteBlood;
    Animation currentAnimation,blooding;
    vector<Texture> Down,Up,Left,Right;
    Vector2f velocity,Scale;
    RectangleShape barBlood,Blood,Bound;
    float armor{},blood,baseBlood{},speed{};
    bool beBlood;
    short currentdirect;
public:
    Bug();
    void setData(map<string,vector<Texture> >&,vector<Texture>&);
    void update(short,float);
    void draw(RenderWindow&);
    void beDamage(pair<float,float>&);
    void setArmor(float);
    bool isAlive() const;
    void setBlood(float);
    Vector2f getPosition();
    FloatRect getBound();
    void  setPosition(Vector2f);
    void setSpeed(float);
    float getSpeed() const;
    void setScale(Vector2f);
    float getBlood() const;
};


#endif //DEFENDERPRO_BUG_H
