//
// Created by duonglh on 16/10/2020.
//

#include "Shooter.h"

Shooter::Shooter() {
    range.setOutlineThickness(1.5f);
    range.setOutlineColor(Color::Black);
    range.setFillColor(Color(0,0,0,0));
    circle.setRadius(5.f);
    circle.setFillColor(Color::Red);
    circle.setOrigin(Vector2f(circle.getRadius(),circle.getRadius()));
    Circle.setRadius(5.f);
    Circle.setFillColor(Color::Red);
    Circle.setOrigin(Vector2f(circle.getRadius(),circle.getRadius()));
    fire=false;
}

void Shooter::setTexture (Texture T_Shooter, Texture T_Bullet) {
    bullet.setTexture(T_Bullet);
    this->texture=T_Shooter;
    person.setTexture(&this->texture);
//    person.setFillColor(Color::Green);
//    person.setScale(0.35,0.35);
    person.setSize((Vector2f)this->texture.getSize());
    person.setOrigin((Vector2f)person.getSize()*0.5f);

}

void Shooter::setPosition (Vector2f position) {
    person.setPosition(position);
    range.setPosition(position);
}

void Shooter::setRange (float radius) {
    range.setRadius(radius);
    range.setOrigin(Vector2f(radius,radius));
}

void Shooter::update (Vector2f bugPosition) {
    float vtx=bugPosition.x-range.getPosition().x;
    float vty=bugPosition.y-range.getPosition().y;
    float distance=sqrt(vtx*vtx+vty*vty);
    float alpha;
    if(distance<=range.getRadius()){
        fire=true;
        alpha=acos(-vtx/distance);
        alpha=alpha/3.14*180;
        if(bugPosition.y>range.getPosition().y) person.setRotation(-alpha);
        else person.setRotation(alpha);
        bullet.update();
        circle.setPosition(Vector2f(person.getPosition().x-(person.getSize().x/2)*(-vtx/distance),person.getPosition().y-(person.getSize().y/2)*(-vty/distance)));
        Circle.setPosition(Vector2f (range.getPosition().x-range.getRadius()*(-vtx/distance),range.getPosition().y-range.getRadius()*(-vty/distance)));
    }
    else fire=false;
}

void Shooter::setTrajectoryOfBullet (Vector2f bugPosition) {
    float vtx=bugPosition.x-range.getPosition().x;
    float vty=bugPosition.y-range.getPosition().y;
    float distance=sqrt(vtx*vtx+vty*vty);
    shootPosition.x=person.getPosition().x-(person.getSize().x/2)*(-vtx/distance);
    shootPosition.y=person.getPosition().y-(person.getSize().y/2)*(-vty/distance);
    targetPosition.x=range.getPosition().x-range.getRadius()*(-vtx/distance);
    targetPosition.y=range.getPosition().y-range.getRadius()*(-vty/distance);
    bullet.setTrajectory(shootPosition,targetPosition);
    bullet.disappear=false;
}

void Shooter::draw (RenderWindow &window,bool showRange) {
    window.draw(person);
    if(fire)
        bullet.draw(window);
    if(showRange) window.draw(range);
//    window.draw(circle);
//    window.draw(Circle);
}

void Shooter::setSpeedForBullet (float speed) {
    bullet.setSpeed(speed);
}

void Shooter::setDamageForBullet (int damage) {
    bullet.setDamage(damage);
}

Bullet Shooter::getBullet () {
    return this->bullet;
}




