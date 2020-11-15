//
// Created by duonglh on 19/10/2020.
//

#include "Intro.h"

Intro::Intro () {
    newIntro();
    this->start=true;
    this->isLoading=false;
    this->cover.setSize(Vector2f(1920,1080));
    srand(time(nullptr));
}

void Intro::newIntro () {
    this->isClickPlayButton=false;
    this->totalTimeTitle=0;
    this->totalTimeLoading=0;
    this->isLoading = true;
    this->scaleLoading=0;
    this->drawIntro = true;
    this->alpha=255;
    this->timeBlur = 0;
    this->Scale=Vector2f(0,0);

}

void Intro::Init (Data &dataBase, RenderWindow *&_window) {
    this->window=_window;
    this->background.setTexture(&dataBase.getIntro("background"));
    this->background.setSize((Vector2f)window->getSize());

    this->impostor.setListTexture(dataBase.getListIntro("impostor"));
    this->impostor.initSprite(animationLoading);

    loadingPercents.setFont(dataBase.getFont());
    loadingPercents.setCharacterSize(25);
    loadingPercents.setPosition(Vector2f(window->getSize().x/2,885));
    loadingPercents.setFillColor(Color::White);

    animationTitle.setListTexture(dataBase.getListIntro("Title"));
    title.setTexture(dataBase.getIntro("title"));
    title.setOrigin((Vector2f)title.getTexture()->getSize()*0.5f);
    //title.setTextureRect(IntRect(0,0,title.getTexture()->getSize().x,title.getTexture()->getSize().y));
    title.setPosition(Vector2f(window->getSize().x*0.5f,title.getTexture()->getSize().y));
    title.setScale(Scale);

    playButton.setTexture(dataBase.getIntro("playButton"));
    playButton.setOrigin((Vector2f)playButton.getTexture()->getSize()*0.5f);
    playButton.setPosition(Vector2f(955,900));

    rankButton.setTexture(dataBase.getIntro("rankButton"));
    rankButton.setOrigin((Vector2f)rankButton.getTexture()->getSize()*0.5f);
    rankButton.setPosition(Vector2f(playButton.getPosition().x-playButton.getTexture()->getSize().x-20,playButton.getPosition().y+playButton.getTexture()->getSize().y/2));

    settingButton.setTexture(dataBase.getIntro("settingButton"));
    settingButton.setOrigin((Vector2f)settingButton.getTexture()->getSize()*0.5f);
    settingButton.setPosition(Vector2f(playButton.getPosition().x+playButton.getTexture()->getSize().x+20,playButton.getPosition().y+playButton.getTexture()->getSize().y/2));

    clouds1.setTexture(&dataBase.getIntro("clouds"));
    clouds1.setSize((Vector2f)clouds1.getTexture()->getSize());
    clouds2.setTexture(&dataBase.getIntro("clouds"));
    clouds2.setSize((Vector2f)clouds2.getTexture()->getSize());
    clouds2.setPosition(Vector2f(-clouds2.getSize().x,0));

    leftCloud.setTexture(&dataBase.getIntro("leftClouds"));
    leftCloud.setSize(Vector2f(1500,1080));
    leftCloud.setPosition(Vector2f(-1500,0));

    rightCloud.setTexture(&dataBase.getIntro("rightClouds"));
    rightCloud.setSize(Vector2f(1500,1080));
    rightCloud.setPosition((Vector2f(window->getSize().x,0)));

    loadingBar.setTexture(&dataBase.getIntro("loadingBar"));
    loadingBar.setSize((Vector2f)loadingBar.getTexture()->getSize());
    loadingBar.setOrigin((Vector2f)loadingBar.getSize()*0.5f);
    loadingBar.setPosition(Vector2f(window->getSize().x/2,900));

    loading.setTexture(&dataBase.getIntro("loading2"));
    loading.setSize((Vector2f)loading.getTexture()->getSize());
    loading.setOrigin(Vector2f(0,loading.getSize().y/2));
    loading.setPosition((Vector2f(loadingBar.getPosition().x-loadingBar.getSize().x/2+8,loadingBar.getPosition().y)));
    loading.setScale(0,1);

    intro.setTexture(&dataBase.getIntro("intro"));
    intro.setSize((Vector2f) intro.getTexture()->getSize());

    madeBy.setTexture(&dataBase.getIntro("madeBy"));
    madeBy.setSize((Vector2f)madeBy.getTexture()->getSize());


}//Init

void Intro::getEvents () {
    deltaTime = clock.restart ().asSeconds ();
    if(!start && !isLoading) {
        FloatRect mousePointer = FloatRect (Mouse::getPosition (*window).x,Mouse::getPosition (*window).y,0.001f,0.001f);
        if(playButton.isOnButton(mousePointer)){
            playButton.setPosition(Vector2f(955,880));
        }
        else playButton.setPosition(Vector2f(955,900));
        if (playButton.isClickButton (mousePointer)) {
            isClickPlayButton = true;
        }
        settingButton.isClickButton (mousePointer);
        rankButton.isClickButton (mousePointer);
    }
}

void Intro::update (short& currentState) {
    if(!start) {
        clouds1.move (Vector2f (1.f, 0));
        clouds2.move (Vector2f (1.f, 0));
        if (clouds1.getPosition ().x >= window->getSize ().x) clouds1.setPosition (Vector2f (-clouds1.getSize ().x, 0));
        if (clouds2.getPosition ().x >= window->getSize ().x) clouds2.setPosition (Vector2f (-clouds2.getSize ().x, 0));
        totalTimeTitle += deltaTime;
        if (totalTimeTitle >= 0.1f) {
            totalTimeTitle = 0;
            if (Scale.x < 1) {
                Scale.x += 0.1f;
                Scale.y = Scale.x;
                title.setScale (Scale);
                title.rotate (108.f);
            }
        }
        if (Scale.x >= 1) {
            animationTitle.update (deltaTime);
            animationTitle.setSprite (title);
        }
        if (isLoading) {
            impostor.update (deltaTime);
            impostor.setSprite (animationLoading);
            animationLoading.setPosition (
                    Vector2f (loading.getPosition ().x + loading.getSize ().x * loading.getScale ().x,
                              loading.getPosition ().y - loading.getSize ().y - 40));
            totalTimeLoading += deltaTime;
            if (loading.getScale ().x < 1 && totalTimeLoading >= 0.5f) {
                totalTimeLoading = 0;
                float ranNumber = rand () % 25;
                scaleLoading += float (ranNumber / 100.f);
                if (scaleLoading > 1) scaleLoading = 1;
                loadingPercents.setString (to_string (int (scaleLoading * 100)) + "%");
                loading.setScale (scaleLoading, 1);
            }
            if (totalTimeLoading >= 0.5f) isLoading = false;
        } else {
            if (isClickPlayButton) {
                if (leftCloud.getPosition ().x < -80) {
                    leftCloud.move (Vector2f (20.f, 0));
                    rightCloud.move (Vector2f (-20.f, 0));
                } else {
                    totalTimeStart += deltaTime;
                    if (totalTimeStart >= 1.f) {
                        currentState = 2;
                    }
                }
            }
        }
    }
    else{
        timeBlur += deltaTime;
        if (timeBlur >= 0.05f) {
            timeBlur = 0;
            alpha -= 2;
            cover.setFillColor(Color(0,0,0,alpha));
        }
        if(alpha <= 0){
            sleep(seconds(3));
            start = false;
            isLoading=true;
        }
        else if(drawIntro && alpha<=10) {
            sleep(seconds(1));
            alpha=255;
            cover.setFillColor(Color(0,0,0,alpha));
            drawIntro = false;
            sleep(seconds(2));
        }
    }
}

void Intro::draw () {
    window->clear();
    if(!start) {
        window->draw (background);
        window->draw (clouds1);
        window->draw (clouds2);
        window->draw (title);

        if (isLoading) {
            window->draw (loadingBar);
            window->draw (loading);
            window->draw (loadingPercents);
            window->draw (animationLoading);
        } else {
            window->draw (playButton);
            window->draw (settingButton);
            window->draw (rankButton);
        }
        if (isClickPlayButton) {
            window->draw (leftCloud);
            window->draw (rightCloud);
        }
    }
    else{
        if(drawIntro)
            window->draw(intro);
        else window->draw(madeBy);
        window->draw(cover);
    }
    window->display();
}





