//
// Created by duonglh on 29/10/2020.
//

#ifndef DEFENDERPRO_TABLEBUTTON_H
#define DEFENDERPRO_TABLEBUTTON_H

#include "Button.h"
#include <vector>
#include <iostream>
using namespace std;
class TableButton {
private:
    RectangleShape table,coinsBag,Skull,Score,logoPro,heart,
                    barHP,HP,barFullHP,fullHP,QR,infoHP;
    vector<pair<Button,Text> > buttons;
    Texture pauseTexture,playTexture;
    Button pauseButton,minus,plus,nextList,googlePlay,setting,close;
    vector<RectangleShape> informationOfButton;
    short currentInformation,ProHP;
    Text scores,coins,death,infomationHP;
    Font font;
    bool pause,isClick;
    float totalTime;
public:
    TableButton(){
        newTableButton();
    }
    void Init(Texture&,Texture&,Texture&,Texture&,Texture&,Texture&,
              Texture&,Texture&,Texture&,Texture&,Texture&,Texture&,
              Texture&,Texture&,Texture&,Texture&,Texture&,Texture&,
              Texture&,Texture&);
    void setListTextureButton(vector<Texture>&,vector<Texture>&);
    void setInformationButton(vector<Texture>&);
    void setFont(Font&);
    int isOnButton(FloatRect &);
    int isClickButton(FloatRect&);
    void draw(RenderWindow&);
    void update(unsigned short&,unsigned short&,float&,FloatRect&,bool&);
    short getProHP() const;
    Vector2<float> getPositionCoinsBag() const;
    bool isClickPauseButton(FloatRect&,float);
    bool isClickNextListButton(FloatRect&);
    bool isClickCloseButton(FloatRect&);
    int otherButton(FloatRect&);
    void newTableButton();
};


#endif //DEFENDERPRO_TABLEBUTTON_H
