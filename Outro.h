//
// Created by duonglh on 14/11/2020.
//

#ifndef DEFENDERPRO_OUTRO_H
#define DEFENDERPRO_OUTRO_H


#include "Data.h"
#include "Button.h"
#include "Animation.h"

class Outro {
private:
    RenderWindow *window;
    RectangleShape leftCloud,rightCloud,table,youLose;
    Animation animationGameOver;
    vector<pair<Vector2f,RectangleShape> > listImpostor;
    vector<Texture> listTexture;
    Sprite gameOver;
    Button close,resume,home;
    float deltaTime,totalTimeGameOver;
    Vector2f Scale;
    Clock clock;
    bool run;
    Text scoresText,deathText;
public:
    Outro();
    void Init(Data&,RenderWindow*&);
    void update(short&);
    void draw();
    void setCurrentState(pair<unsigned short,unsigned short>);
    void newOutro();
};


#endif //DEFENDERPRO_OUTRO_H
