//
// Created by duonglh on 19/10/2020.
//

#ifndef DEFENDERPRO_INTRO_H
#define DEFENDERPRO_INTRO_H
#include "Data.h"
#include "Animation.h"
#include "Button.h"
using namespace sf;
using namespace std;
class Intro {
private:
    RenderWindow *window{};
    Animation impostor,animationTitle;
    Button playButton,rankButton,settingButton;
    RectangleShape loadingBar,loading,background,clouds1,clouds2,leftCloud,rightCloud,intro,madeBy,cover;
    Sprite animationLoading,title;
    float deltaTime{},totalTimeTitle{},totalTimeStart{},totalTimeLoading{},scaleLoading{},timeBlur{},alpha{};
    bool isClickPlayButton{},isLoading,start,drawIntro{};
    Vector2f Scale;
    Text loadingPercents;
    Clock clock;
public:
    Intro();
    void Init(Data&,RenderWindow*&);
    void getEvents();
    void update(short&);
    void newIntro();
    void draw();

};


#endif //DEFENDERPRO_INTRO_H
