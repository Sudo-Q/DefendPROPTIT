//
// Created by duonglh on 16/10/2020.
//

#include "Shooter.h"

Shooter::Shooter() {
    range.setOutlineThickness(2.f);
    range.setOutlineColor(Color::Black);
    range.setFillColor(Color(0,0,0,0));
    listBullet.resize(25);
    fireTime=0.2f;
    totalTime=0;
    fire=false;
    this->bound.setSize(Vector2f(64,64));
    this->bound.setOrigin(Vector2f(32,32));
    this->levelBullet = vector<int>{100,150,200,250,300,400,500,700,1000};
}

void Shooter::setTexture (short id,Texture &T_Shooter, vector<Texture> &_listBulletTexture) {
    this->listBulletTexture=_listBulletTexture;
    for(Bullet &bullet : listBullet){
        bullet.setTexture(listBulletTexture[id-1]);
    }
//    this->buff(0,0,0,0);
    person.setTexture(&T_Shooter);
    person.setSize((Vector2f)T_Shooter.getSize());
    person.setOrigin((Vector2f)person.getSize()*0.5f);
}

void Shooter::buff (float _damage,float _trueDamage,float _range,float _speed) {
    for(Bullet &bullet : listBullet){
        bullet.addDamage(_damage);
        bullet.addTrueDamage(_trueDamage);
        bullet.addSpeed(_speed);
    }
//    this->range.setRadius(this->range.getRadius()+_range);
//    this->range.setOrigin(Vector2f(range.getRadius(),range.getRadius()));
    this->setRange(range.getRadius()+_range);
    for(int i=8;i>=0;i--){
        if(int(listBullet[0].getDamage().first)>=levelBullet[i]){
            for(Bullet &bullet : listBullet){
                bullet.setTexture(listBulletTexture[i]);
            }
            return;
        }
    }
}

void Shooter::setPosition (Vector2f position) {
    person.setPosition(position);
    bound.setPosition(position);
    range.setPosition(position);
}

void Shooter::setRange (float radius) {
    range.setRadius(radius);
    range.setOrigin(Vector2f(radius,radius));
}

bool Shooter::update (Vector2f bugPosition,float deltatime) {
    float vtx=bugPosition.x-range.getPosition().x;
    float vty=bugPosition.y-range.getPosition().y;
    float distance=sqrt(vtx*vtx+vty*vty);

    float alpha;
    if(bugPosition.y>=30 && distance<=range.getRadius()) {
        fire = true;
        alpha = acos (-vtx / distance);
        alpha = float(alpha / M_PI * 180);
        if (bugPosition.y > range.getPosition ().y) person.setRotation (-alpha);
        else person.setRotation (alpha);

        totalTime += deltatime;
        if(totalTime >= fireTime) {
            totalTime = 0;
            shootPosition.x = person.getPosition ().x - (person.getSize ().x / 2) * (-vtx / distance);
            shootPosition.y = person.getPosition ().y - (person.getSize ().y / 2) * (-vty / distance);
            targetPosition.x = range.getPosition ().x - range.getRadius () * (-vtx / distance);
            targetPosition.y = range.getPosition ().y - range.getRadius () * (-vty / distance);

            for (Bullet &bullet : listBullet) {
                if (!bullet.isFire) {
                    bullet.setTrajectory (shootPosition, targetPosition);
                    bullet.isFire = true;
                    break;
                }
            }
        }
    }
    else fire = false;
    return fire;
}

void Shooter::setFireTime (float _fireTime) {
    this->fireTime=_fireTime;
}

void Shooter::setDamageForBullet (float _damage) {
    for(Bullet &bullet : listBullet){
        bullet.setDamage(_damage);
    }
}

void Shooter::setTrueDamage (float _trueDamage) {
    for(Bullet &bullet : listBullet){
        bullet.addTrueDamage(_trueDamage);
    }
}

pair<float, float>& Shooter::getAllDamage () {
    return listBullet[0].getDamage();
}

bool Shooter::checkCollision (FloatRect bugBound) {
    for(Bullet &bullet : listBullet){
        if(bullet.getBound().intersects(bugBound)){
            bullet.isFire= false;
            bullet.setPosition(person.getPosition());
            return true;
        }
    }
    return false;
}

void Shooter::setSpeedForBullet (float _speed) {
    for(Bullet &bullet:listBullet){
        bullet.setSpeed(_speed);
    }
}

void Shooter::draw (RenderWindow &window,bool showRange) {
    window.draw(person);
    if(fire){
        for(Bullet &bullet : listBullet){
            if(bullet.isFire){
                bullet.draw(window);
            }
        }
    }
    if(showRange) window.draw(range);
}

FloatRect Shooter::getShooterBound () {
    return this->bound.getGlobalBounds();
}

Vector2f Shooter::getPosition () {
    return this->person.getPosition();
}


void Shooter::updateBullet () {
    for(Bullet &bullet : listBullet)
        bullet.update();
}

bool Shooter::playShootMusic () {
    for(Bullet &bullet : listBullet){
        if(bullet.isFire){
            return true;
        }
    }
    return false;
}


