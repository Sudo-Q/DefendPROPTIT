//
// Created by duonglh on 29/10/2020.
//

#include "TableButton.h"

void TableButton::newTableButton () {
    this->ProHP=30;
    this->pause=false;
    this->isClick=false;
    this->totalTime=0;
}

void TableButton::Init (Texture &Table,Texture &_coins, Texture &skull,Texture &_score,
                        Texture& _logo,Texture& _heart,Texture &QR,Texture &_barHP,
                        Texture &HP,Texture &_barFullHP,Texture &_fullHP,Texture &_infoHP,
                        Texture &_Play,Texture &_Pause,Texture &_minus,Texture &_nextList,
                        Texture &_plus,Texture &_googlePlay,Texture &_setting,Texture &_close) {
    this->table.setTexture(&Table);
    this->table.setSize(Vector2f(Table.getSize().x,Table.getSize().y+72));
    this->table.setPosition(1310.f,30.f);
    Vector2f tablePosition=table.getPosition(),tableSize=table.getSize();

    this->coinsBag.setTexture(&_coins);
    this->coinsBag.setSize((Vector2f)_coins.getSize());
    this->coinsBag.setPosition(Vector2f(tablePosition.x+50,tablePosition.y+30));

    this->Skull.setTexture(&skull);
    this->Skull.setSize((Vector2f)skull.getSize());
    this->Skull.setPosition(coinsBag.getPosition().x,coinsBag.getPosition().y+_coins.getSize().y+20);

    this->Score.setTexture(&_score);
    this->Score.setSize((Vector2f)_score.getSize());
    this->Score.setPosition(Vector2f(coinsBag.getPosition().x+220,coinsBag.getPosition().y+20));

    this->logoPro.setTexture(&_logo);
    this->logoPro.setSize((Vector2f)_logo.getSize());
    this->logoPro.setOrigin((Vector2f)logoPro.getSize()*0.5f);
    this->logoPro.setPosition(Vector2f(tablePosition.x+175,tablePosition.y+tableSize.y*0.7f));

    this->QR.setTexture(&QR);
    this->QR.setSize((Vector2f)QR.getSize());
    this->QR.setOrigin((Vector2f)QR.getSize()*0.5f);
    this->QR.setPosition(Vector2f(logoPro.getPosition().x+logoPro.getSize().x+50,logoPro.getPosition().y));

    this->heart.setTexture(&_heart);
    this->heart.setSize((Vector2f)_heart.getSize());
    this->heart.setPosition(Vector2f(logoPro.getPosition().x-logoPro.getSize().x,logoPro.getPosition().y+logoPro.getSize().y));

    this->scores.setFont(font);
    this->coins.setFont(font);
    this->death.setFont(font);
    this->infomationHP.setFont(font);

    this->scores.setPosition(Score.getPosition().x+_score.getSize().x*0.2f,Score.getPosition().y+_score.getSize().y+15);
    this->scores.setCharacterSize(50);
    this->scores.setFillColor(Color::White);
    this->scores.setStyle(Text::Bold);

    this->coins.setPosition(coinsBag.getPosition().x+_coins.getSize().x+20,coinsBag.getPosition().y+_coins.getSize().y*0.5f);
    this->coins.setCharacterSize(20);
    this->coins.setFillColor(Color::White);
    this->coins.setStyle(Text::Bold);

    this->death.setPosition(Skull.getPosition().x+skull.getSize().x+10,Skull.getPosition().y+skull.getSize().y*0.5f);
    this->death.setCharacterSize(20);
    this->death.setFillColor(Color::White);
    this->death.setStyle(Text::Bold);

    this->barHP.setTexture(&_barHP);
    this->barHP.setSize((Vector2f)_barHP.getSize());

    this->barFullHP.setTexture(&_barFullHP);
    this->barFullHP.setSize((Vector2f)_barFullHP.getSize());

    this->HP.setTexture(&HP);
    this->HP.setSize((Vector2f)HP.getSize());

    this->fullHP.setTexture(&_fullHP);
    this->fullHP.setSize((Vector2f)_fullHP.getSize());

    this->infoHP.setTexture(&_infoHP);
    this->infoHP.setSize((Vector2f)_infoHP.getSize());
    this->infoHP.setPosition(Vector2f(heart.getPosition().x+11.5*21,heart.getPosition().y+heart.getSize().y-15));

    this->infomationHP.setCharacterSize(15);
    this->infomationHP.setStyle(Text::Bold);
    this->infomationHP.setPosition(Vector2f(infoHP.getPosition().x+28,infoHP.getPosition().y+5));

    this->pauseButton.setTexture(_Pause);
    this->pauseButton.setOrigin((Vector2f)_Pause.getSize()*0.5f);
    this->pauseButton.setPosition(Vector2f(table.getPosition().x+table.getSize().x/2-25,table.getPosition().y+table.getSize().y-_Pause.getSize().y/2-20));
    this->pauseTexture=_Pause;
    this->playTexture=_Play;

    this->minus.setTexture(_minus);
    this->minus.setOrigin((Vector2f) _minus.getSize()*0.5f);
    this->minus.setPosition(Vector2f(pauseButton.getPosition().x-215,pauseButton.getPosition().y+20));

    this->plus.setTexture(_plus);
    this->plus.setOrigin((Vector2f) _plus.getSize()*0.5f);
    this->plus.setPosition(Vector2f(minus.getPosition().x,minus.getPosition().y-50));

    this->nextList.setTexture(_nextList);
    this->nextList.setOrigin((Vector2f) _nextList.getSize()*0.5f);
    this->nextList.setPosition(Vector2f(pauseButton.getPosition().x+pauseButton.getTexture()->getSize().x+20,pauseButton.getPosition().y));

    this->googlePlay.setTexture(_googlePlay);
    this->googlePlay.setOrigin((Vector2f)_googlePlay.getSize()*0.5f);
    this->googlePlay.setPosition(Vector2f(pauseButton.getPosition().x-pauseButton.getTexture()->getSize().x-20,pauseButton.getPosition().y));

    this->setting.setTexture(_setting);
    this->setting.setOrigin((Vector2f) _setting.getSize()*0.5f);
    this->setting.setPosition(Vector2f(nextList.getPosition().x+nextList.getTexture()->getSize().x+20,nextList.getPosition().y));

    this->close.setTexture(_close);
    this->close.setOrigin((Vector2f) _close.getSize()*0.5f);
    this->close.setPosition(Vector2f(tablePosition.x+tableSize.x+20,25));
}

void TableButton::setListTextureButton (vector<Texture> &listshooterButton,vector<Texture> &listAddButton) {
    pair<Button,Text> tmp;
    tmp.second.setFont(font);
    tmp.second.setCharacterSize(25);
    tmp.second.setFillColor(Color::Red);
    tmp.second.setStyle(Text::Bold);

    Vector2f tablePosition=table.getPosition();
    for(int i=0;i<listshooterButton.size();i++){
        tmp.first.setTexture(listshooterButton[i]);
        tmp.first.setOrigin((Vector2f)listshooterButton[i].getSize()*0.5f);
        tmp.first.setPosition(Vector2f(tablePosition.x+float((listshooterButton[i].getSize().x+50)*i)+125.5,300));
        tmp.second.setPosition(tmp.first.getPosition().x-20,tmp.first.getPosition().y+listshooterButton[i].getSize().y/2+10);
        buttons.push_back(tmp);
    }

    tmp.first=Button();
    tmp.second.setFillColor(Color::Cyan);
    tmp.second.setCharacterSize(15);
    for(int i=0;i<listAddButton.size();i++){
        tmp.first.setTexture(listAddButton[i]);
        tmp.first.setOrigin((Vector2f)listAddButton[i].getSize()*0.5f);
        tmp.first.setPosition(Vector2f(tablePosition.x+float((listAddButton[i].getSize().x+50)*i)+125.5,buttons[0].first.getPosition().y+listshooterButton[0].getSize().y+100));
        buttons.push_back(tmp);
    }

    buttons[0].second.setString("D19");
    buttons[1].second.setString("D18");
    buttons[2].second.setString("D17");

    buttons[3].second.setString("GeekForGeek");
    buttons[3].second.setPosition(buttons[3].first.getPosition().x-60,buttons[3].first.getPosition().y+listAddButton[0].getSize().y/2+15);

    buttons[4].second.setString("GitHub");
    buttons[4].second.setPosition(buttons[4].first.getPosition().x-30,buttons[4].first.getPosition().y+listAddButton[1].getSize().y/2+10);

    buttons[5].second.setString("StackOverFlow");
    buttons[5].second.setPosition(buttons[5].first.getPosition().x-70,buttons[5].first.getPosition().y+listAddButton[2].getSize().y/2+15);


}

void TableButton::draw (RenderWindow &window) {
    window.draw(table);
    window.draw(coinsBag);
    window.draw(Skull);
    window.draw(Score);
    window.draw(coins);
    window.draw(death);
    window.draw(scores);
    window.draw(logoPro);
    window.draw(QR);

    for(pair<Button,Text> & button : buttons){
        window.draw(button.first);
        window.draw(button.second);
    }

    if(currentInformation) window.draw(informationOfButton[currentInformation-1]);

    Vector2f heartPosition=heart.getPosition();
    Vector2f heartSize=heart.getSize();
    //draw HP Pro
    for(int i=0;i<=13;i++){
        barHP.setPosition(Vector2f(heartPosition.x+heartSize.x+i*21-18,heartPosition.y+heartSize.y/2-16));
        window.draw(barHP);
    }
    barFullHP.setPosition(Vector2f(barHP.getPosition().x + barHP.getSize().x, barHP.getPosition().y));
    window.draw(barFullHP);
    HP.setPosition(Vector2f(heartPosition.x+heartSize.x+ProHP*9,heartPosition.y+heartSize.y/2-16));
    for(int i=0;i<=ProHP;i++){
        HP.setPosition(Vector2f(heartPosition.x+heartSize.x+i*9,heartPosition.y+heartSize.y/2-16));
        window.draw(HP);
    }
    fullHP.setPosition(HP.getPosition().x+HP.getSize().x-1,HP.getPosition().y);
    window.draw(fullHP);
    window.draw(heart);
    window.draw(infoHP);
    window.draw(infomationHP);
    window.draw(pauseButton);
    window.draw(minus);
    window.draw(plus);
    window.draw(nextList);
    window.draw(googlePlay);
    window.draw(setting);
    window.draw(close);
}

void TableButton::setFont (Font &font) {
    this->font=font;
}

int TableButton::isOnButton (FloatRect &rectMouse) {//theo thứ tự D19:1 D18:2 D17:3 ...
    for(int i=0;i<buttons.size();i++){
        if(buttons[i].first.isOnButton(rectMouse)){
            return i+1;
        }
    }
    return 0;
}

int TableButton::isClickButton (FloatRect &rectMouse) {
    for(int i=0;i<buttons.size();i++){
        if(buttons[i].first.isClickButton(rectMouse)){
            return i+1;
        }
    }
    return 0;
}

void TableButton::update (unsigned short &_coins,unsigned short &_death,float &_scores,FloatRect &rectMouse,bool &isDamage) {
    currentInformation=this->isOnButton(rectMouse);
    this->death.setString(to_string(_death));
    this->coins.setString(to_string(_coins)+" $");
    this->scores.setString(to_string((int)_scores));
    if(isDamage) ProHP--;
    this->infomationHP.setString(to_string(ProHP+2)+"/32");

    googlePlay.isClickButton(rectMouse);
}

void TableButton::setInformationButton (vector<Texture> &listInformation) {
    RectangleShape tmp;
    for(int i=0;i<listInformation.size();i++){
        tmp.setTexture(&listInformation[i]);
        tmp.setSize((Vector2f)listInformation[i].getSize());
        tmp.setOrigin(Vector2f(listInformation[i].getSize().x-70,listInformation[i].getSize().y));
        tmp.setPosition(buttons[i].first.getPosition().x,buttons[i].first.getPosition().y-buttons[i].first.getTexture()->getSize().y/2);

        informationOfButton.push_back(tmp);
    }
}

short TableButton::getProHP () const {
    return this->ProHP;
}

Vector2<float> TableButton::getPositionCoinsBag () const {
    return Vector2f(coinsBag.getPosition().x+coinsBag.getSize().x/2,coinsBag.getPosition().y+coinsBag.getSize().y/2);
}

bool TableButton::isClickPauseButton (FloatRect &rectMouse,float deltaTime) {
    if (pauseButton.isClickButton(rectMouse) || Keyboard::isKeyPressed(sf::Keyboard::P)) {
        isClick=true;
    }
    // sau 0.3s mới được bấm pause thêm lần nữa.
    if(isClick){
        totalTime+=deltaTime;
        if(totalTime>=0.3f){
            totalTime=0;
            isClick= false;
            if (pause) {
                pause = false;
                pauseButton.setTexture (pauseTexture);
            } else {
                pause = true;
                pauseButton.setTexture (playTexture);
            }
        }
    }
    return pause;
}

bool TableButton::isClickNextListButton (FloatRect &rectMouse) {
    return nextList.isClickButton(rectMouse);
}

int TableButton::otherButton (FloatRect &rectMouse) {
    if(minus.isClickButton(rectMouse)) return 1;
    if(plus.isClickButton(rectMouse)) return 2;
    if(setting.isClickButton(rectMouse)) return 3;
    return 0;
}

bool TableButton::isClickCloseButton (FloatRect &rectMouse) {
    if(close.isClickButton(rectMouse) || Keyboard::isKeyPressed(Keyboard::Escape)){
        return true;
    }
    return false;
}




