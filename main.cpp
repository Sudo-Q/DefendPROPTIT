
#include "Map.h"
#include "Data.h"
#include "Bug.h"
#include "Shooter.h"
using namespace sf;
using namespace std;
enum direct{
    Down,Up,Left,Right
};

int main(){
    RenderWindow window(VideoMode(1920,1024),"map");
    window.setFramerateLimit(60);
    Data dataBase;
    dataBase.loadFromFile();
    Map map;
    map.setMap(dataBase.getDataMap("baseMap"));

    int blood=200;

    Bug bug;
    bug.setData(dataBase.getDataBug("BugGod"));
    bug.setArmor(4);
    bug.setBlood(blood);
    bug.setSpeed(1);
    bug.setPosition(Vector2f(300,200));

    Shooter shooter;
    shooter.setTexture(dataBase.getDataShooter("D17"),dataBase.getDataBullet("Red"));
    shooter.setPosition(Vector2f(500,500));
    shooter.setSpeedForBullet(50.f);
    shooter.setDamageForBullet(10);
    shooter.setRange(500);
    shooter.setTrajectoryOfBullet(bug.getPosition());
    Event ev;
    while (window.isOpen()){
        while (window.pollEvent(ev)){
            if(ev.type==Event::Closed){
                window.close();
            }
        }
        bug.update(Right);
        shooter.update(bug.getPosition());
        if(bug.getBound().getGlobalBounds().intersects(shooter.getBullet().getBound())){
            shooter.setTrajectoryOfBullet(bug.getPosition());
            bug.beDamage(shooter.getBullet().getDamage());
        }
        if(shooter.getBullet().disappear){
            shooter.setTrajectoryOfBullet(bug.getPosition());
        }

        if(!bug.isAlive()){
            bug.setPosition(Vector2f(300,800));
            blood+=500;
            bug.setBlood(blood);
        }
        window.clear(Color::Blue);
        map.draw(window);
        bug.draw(window);
        shooter.draw(window,true);
        window.display();
    }

}

/*
#include "Bug.h"
#include "Shooter.h"
#include <iostream>

enum direct{
    Down,Up,Left,Right
};

int main(){
    int blood=200;
    RenderWindow window(VideoMode(1920,1080),"demo");
    window.setFramerateLimit(60);
    Event event;
    Shooter shooter;
    Bug bug;
    bug.loadFromFile("bugGod");
    bug.setArmor(4);
    bug.setBlood(blood);
    bug.setSpeed(2);
    bug.setPosition(Vector2f(300,200));

    shooter.loadFromFile("boss","bullet1");
    shooter.setPosition(Vector2f(500,500));
    shooter.setSpeedForBullet(50.f);
    shooter.setDamageForBullet(10);
    shooter.setRange(500);

    shooter.setTrajectoryOfBullet(bug.getPosition());
    while (window.isOpen()){
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close ();
            }
        }

        bug.update(Right);
        shooter.update(bug.getPosition());
        if(bug.getBound().getGlobalBounds().intersects(shooter.getBullet().getBound().getGlobalBounds())){
            shooter.setTrajectoryOfBullet(bug.getPosition());
            bug.beDamage(shooter.getBullet().getDamage());
        }
        if(shooter.getBullet().disappear){
            shooter.setTrajectoryOfBullet(bug.getPosition());
        }

        if(!bug.isAlive()){
            bug.setPosition(Vector2f(300,800));
//            blood+=500;
            bug.setBlood(blood);
        }
        window.clear(Color::Blue);
        bug.draw(window);
        shooter.draw(window,true);
        window.display();
    }

}*/
