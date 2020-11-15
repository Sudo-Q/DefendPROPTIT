//
// Created by duonglh on 14/11/2020.
//

#include "Outro.h"

Outro::Outro () {
    this->run=false;
    this->totalTimeGameOver=0;
    this->Scale=Vector2f(0,0);
    srand(time(nullptr));
}

void Outro::newOutro () {
    this->run=false;
    this->totalTimeGameOver=0;
    this->Scale=Vector2f(0,0);
    this->window->setFramerateLimit(60);
}

void Outro::Init (Data &dataBase, RenderWindow *&window) {
    this->window=window;
    leftCloud.setTexture(&dataBase.getIntro("leftClouds"));
    leftCloud.setSize(Vector2f(1500,1080));
    leftCloud.setPosition(Vector2f(-80,0));

    rightCloud.setTexture(&dataBase.getIntro("rightClouds"));
    rightCloud.setSize(Vector2f(1500,1080));
    rightCloud.setPosition((Vector2f(500,0)));

    listTexture=dataBase.getListOutro("impostor");
    RectangleShape tmp;
    for(int i=0;i<10;i++){
        tmp.setTexture(&listTexture[i]);
        tmp.setTextureRect(IntRect(0,0,listTexture[i].getSize().x,listTexture[i].getSize().y));
        tmp.setSize(Vector2f(listTexture[i].getSize().x,listTexture[i].getSize().y));
        tmp.setOrigin((Vector2f) tmp.getSize()*0.5f);
        int x=rand()%1920;
        int y=rand()%1080;
        int velocity=rand()%8+1;
        tmp.setPosition(Vector2f(x,y));
        listImpostor.emplace_back(Vector2f(velocity,velocity),tmp);
    }

    animationGameOver.setListTexture(dataBase.getListOutro("gameOver"));
    gameOver.setTexture(dataBase.getListOutro("gameOver").at(0));
    gameOver.setOrigin((Vector2f)gameOver.getTexture()->getSize()*0.5f);
    gameOver.setPosition(Vector2f(window->getSize().x/2,window->getSize().y/2));
    gameOver.setScale(Scale);

    table.setTexture(&dataBase.getOutro("table"));
    table.setSize((Vector2f)table.getTexture()->getSize());
    table.setOrigin((Vector2f)table.getSize()*0.5f);
    table.setPosition(Vector2f(window->getSize().x/2,window->getSize().y/2+200));

    youLose.setTexture(&dataBase.getOutro("youLose"));
    youLose.setSize((Vector2f)youLose.getTexture()->getSize());
    youLose.setOrigin((Vector2f)youLose.getSize()*0.5f);
    youLose.setPosition(Vector2f(table.getPosition().x,table.getPosition().y-150));

    scoresText.setFont(dataBase.getFont());
    scoresText.setCharacterSize(75);
    scoresText.setFillColor(Color::Red);
    scoresText.setStyle(Text::Bold);
    scoresText.setPosition(Vector2f(youLose.getPosition().x-youLose.getSize().x+150,youLose.getPosition().y+youLose.getSize().y/2));

    deathText.setFont(dataBase.getFont());
    deathText.setCharacterSize(75);
    deathText.setFillColor(Color::Black);
    deathText.setStyle(Text::Bold);
    deathText.setPosition(Vector2f(scoresText.getPosition().x,scoresText.getPosition().y+75));

    resume.setTexture(dataBase.getOutro("resume"));
    resume.setOrigin((Vector2f)resume.getTexture()->getSize()*0.5f);
    resume.setPosition(Vector2f(table.getPosition().x,table.getPosition().y+table.getSize().y/2-100));

    close.setTexture(dataBase.getOutro("close"));
    close.setOrigin((Vector2f)close.getTexture()->getSize()*0.5f);
    close.setPosition(resume.getPosition().x+150,resume.getPosition().y);

    home.setTexture(dataBase.getOutro("home"));
    home.setOrigin((Vector2f)home.getTexture()->getSize()*0.5f);
    home.setPosition(Vector2f(resume.getPosition().x-150,resume.getPosition().y));

}

void Outro::update (short &currentState) {
    deltaTime=clock.restart().asSeconds();
    FloatRect mousePointer=FloatRect (Mouse::getPosition (*window).x,Mouse::getPosition (*window).y,0.001f,0.001f);
    totalTimeGameOver+=deltaTime;
    if (totalTimeGameOver >= 0.1f) {
        if (Scale.x < 1.5f) {
            totalTimeGameOver = 0;
            Scale.x += 0.1f;
            Scale.y = Scale.x;
            gameOver.setScale (Scale);
            gameOver.rotate (144.05f);//
        }else{
            gameOver.move(0,-2.f);
            if(gameOver.getPosition().y<=200){
                gameOver.setPosition(gameOver.getPosition().x,200);
                run=true;
            }
        }
    }
    animationGameOver.update (deltaTime);
    animationGameOver.setSprite (gameOver);

    if(run){

    }
    for(auto &impostor : listImpostor){
        impostor.second.move(impostor.first);
//        int velocity=rand()%8+1;
//        impostor.first.x=velocity;
//        impostor.first.y=velocity;
        impostor.second.rotate(5.f);
        if(impostor.second.getPosition().x<=0 || impostor.second.getPosition().x > 1920) impostor.first.x=-impostor.first.x;
        if(impostor.second.getPosition().y<=0 || impostor.second.getPosition().y > 1080) impostor.first.y=-impostor.first.y;
    }
    if(resume.isClickButton(mousePointer)){
        currentState=1;
    }
    else if(close.isClickButton(mousePointer)) window->close();
    else home.isClickButton(mousePointer);
}

void Outro::draw () {
    window->clear();
    window->draw(leftCloud);
    window->draw(rightCloud);
    for(auto &impostor : listImpostor){
        window->draw(impostor.second);
    }
    window->draw(gameOver);
    if(run){
        window->draw(table);
        window->draw(resume);
        window->draw(home);
        window->draw(close);
        window->draw(youLose);
        window->draw(scoresText);
        window->draw(deathText);
    }
    window->display();
}

void Outro::setCurrentState (pair<unsigned short,unsigned short> preState) {
    scoresText.setString("Scores: "+to_string(preState.first));
    deathText.setString("Deaths: "+to_string(preState.second));
}

