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
    Sprite sprite;
    Animation currentAnimation;
    vector<Texture> Down,Up,Left,Right;
    Vector2f velocity;
    RectangleShape barBlood,Blood,Bound;
    int armor,blood,baseBlood;
    float speed;
    
public:
    Bug();
    void setData(map<string,vector<Texture> >);
    void update(int);
    void draw(RenderWindow&);
    void beDamage(int);
    void setArmor(int);
    bool isAlive();
    void setBlood(int);
    Vector2f getPosition();
    RectangleShape getBound();
    void  setPosition(Vector2f);
    void setSpeed(float);
};


#endif //DEFENDERPRO_BUG_H
