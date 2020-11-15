//
// Created by duonglh on 23/10/2020.
//

#include "Data.h"
#include <iostream>

void Data::loadDataIntro () {
    vector<Texture>listTexture;
    font.loadFromFile("../Data/Font.ttf");
    texture.loadFromFile("../Data/DataIntro/BackGround.png");
    DataIntro.insert({"background",texture});
    texture.loadFromFile("../Data/DataIntro/clouds.png");
    DataIntro.insert({"clouds",texture});
    texture.loadFromFile("../Data/DataIntro/leftClouds.png");
    DataIntro.insert({"leftClouds",texture});
    texture.loadFromFile("../Data/DataIntro/rightClouds.png");
    DataIntro.insert({"rightClouds",texture});
    texture.loadFromFile("../Data/DataIntro/playButton.png");
    DataIntro.insert({"playButton",texture});
    texture.loadFromFile("../Data/DataIntro/rankButton.png");
    DataIntro.insert({"rankButton",texture});
    texture.loadFromFile("../Data/DataIntro/settingButton.png");
    DataIntro.insert({"settingButton",texture});
    texture.loadFromFile("../Data/DataIntro/Title1.png");
    DataIntro.insert({"title",texture});
    texture.loadFromFile("../Data/DataIntro/loadingBar.png");
    DataIntro.insert({"loadingBar",texture});
    texture.loadFromFile("../Data/DataIntro/loading1.png");
    DataIntro.insert({"loading1",texture});
    texture.loadFromFile("../Data/DataIntro/loading2.png");
    DataIntro.insert({"loading2",texture});

    for(short i=1;i<=3;i++){
        texture.loadFromFile("../Data/DataIntro/Title"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataListIntro.insert({"Title",listTexture});
    listTexture.clear();

    for(short i=1;i<=11;i++){
        texture.loadFromFile("../Data/DataIntro/impostor/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataListIntro.insert({"impostor",listTexture});

    texture.loadFromFile("../Data/DataIntro/intro.png");
    DataIntro.insert({"intro",texture});

    texture.loadFromFile("../Data/DataIntro/madeBy.png");
    DataIntro.insert({"madeBy",texture});

}

void Data::loadDataGame() {
    string nameTexture;
    vector<Texture> listTexture;
    vector<string> namePath = {"Down","Up", "Left","Right"};

    // load Data Bug
    map<string,vector<Texture> >tmp;
    for(string & i : namePath) {
        for(short j=1;j<=6;j++){
            texture.loadFromFile("../Data/DataBug/Bug/"+i+"/"+to_string(j)+".png");
            listTexture.push_back(texture);
        }
        tmp.insert({i,listTexture});
        listTexture.clear();
    }
    DataBug.insert({"Bug",tmp});
    tmp.clear();
    listTexture.clear();

    // load Data BugGod
    for(string &i:namePath) {
        for(short j=1;j<=6;j++){
            texture.loadFromFile("../Data/DataBug/BugGod/"+i+"/"+to_string(j)+".png");
            listTexture.push_back(texture);
        }
        tmp.insert({i,listTexture});
        listTexture.clear();
    }
    DataBug.insert({"BugGod",tmp});

    //load data blooding effect
    for(short i=0;i<=20;i++){
        texture.loadFromFile("../Data/DataBug/Blood/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataBlooding.insert({"Blooding",listTexture});
    listTexture.clear();

    // load Data Bullet
    for(int i=1;i<=9;i++){
        texture.loadFromFile("../Data/DataBullet/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataBullet.insert({"allLevelBullet",listTexture});
    listTexture.clear();

    //load Data Map
    for(short i=0;i<=28;i++){
        texture.loadFromFile("../Data/DataMap/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataMap.insert({"baseMap",listTexture});
    listTexture.clear();
    texture.loadFromFile("../Data/DataMap/ProTower.png");
    listTexture.push_back(texture);
    DataMap.insert({"ProTower",listTexture});
    listTexture.clear();

    //load Data Shooter
    for(short i=17;i<=19;i++){
        nameTexture="D"+to_string(i);
        texture.loadFromFile("../Data/DataShooter/"+nameTexture+".png");
        DataShooter.insert({nameTexture,texture});
    }

    // load Data Button
    texture.loadFromFile("../Data/DataButton/Table.png");
    DataButton.insert({"Table",texture});

    texture.loadFromFile("../Data/DataButton/coinsBag.png");
    DataButton.insert({"coinsBag",texture});

    texture.loadFromFile("../Data/DataButton/skull.png");
    DataButton.insert({"skull",texture});

    texture.loadFromFile("../Data/DataButton/score.png");
    DataButton.insert({"score",texture});

    texture.loadFromFile("../Data/DataButton/X.png");
    DataButton.insert({"X",texture});

    texture.loadFromFile("../Data/DataButton/sell.png");
    DataButton.insert({"sell",texture});

    texture.loadFromFile("../Data/DataButton/X.png");
    DataButton.insert({"xWarning",texture});

    texture.loadFromFile("../Data/DataButton/logoPro.png");
    DataButton.insert({"logoPro",texture});

    texture.loadFromFile("../Data/DataButton/heart.png");
    DataButton.insert({"heart",texture});

    texture.loadFromFile("../Data/DataButton/barHP.png");
    DataButton.insert({"barHP",texture});

    texture.loadFromFile("../Data/DataButton/fullHP.png");
    DataButton.insert({"fullHP",texture});

    texture.loadFromFile("../Data/DataButton/fullBarHP.png");
    DataButton.insert({"barFullHP",texture});

    texture.loadFromFile("../Data/DataButton/HP.png");
    DataButton.insert({"HP",texture});

    texture.loadFromFile("../Data/DataButton/QR.png");
    DataButton.insert({"QR",texture});

    texture.loadFromFile("../Data/DataButton/PointsHP.png");
    DataButton.insert({"PointsHP",texture});

    texture.loadFromFile("../Data/DataButton/Pause.png");
    DataButton.insert({"Pause",texture});

    texture.loadFromFile("../Data/DataButton/Play.png");
    DataButton.insert({"Play",texture});

    texture.loadFromFile("../Data/DataButton/minus.png");
    DataButton.insert({"minus",texture});

    texture.loadFromFile("../Data/DataButton/nextList.png");
    DataButton.insert({"nextList",texture});

    texture.loadFromFile("../Data/DataButton/plus.png");
    DataButton.insert({"plus",texture});

    texture.loadFromFile("../Data/DataButton/googlePlay.png");
    DataButton.insert({"googlePlay",texture});

    texture.loadFromFile("../Data/DataButton/setting.png");
    DataButton.insert({"setting",texture});

    texture.loadFromFile("../Data/DataButton/close.png");
    DataButton.insert({"close",texture});


    for(short i=19;i>=17;i--){
        nameTexture="D"+to_string(i);
        texture.loadFromFile("../Data/DataButton/"+nameTexture+".png");
        DataButton.insert({nameTexture,texture});
        listTexture.push_back(texture);
    }
    DataListButton.insert({"shooterButton",listTexture});
    listTexture.clear();

    texture.loadFromFile("../Data/DataButton/geekforgeek.png");
    DataButton.insert({"GeekForGeek",texture});
    listTexture.push_back(texture);

    texture.loadFromFile("../Data/DataButton/github.png");
    DataButton.insert({"GitHub",texture});
    listTexture.push_back(texture);

    texture.loadFromFile("../Data/DataButton/stackoverflow.png");
    DataButton.insert({"StackOverFlow",texture});
    listTexture.push_back(texture);

    DataListButton.insert({"addButton",listTexture});
    listTexture.clear();

    for(short i=1;i<=6;i++){
        texture.loadFromFile("../Data/DataButton/information"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataListButton.insert({"InformationButton",listTexture});
    listTexture.clear();

    // load Data Effect
    for(short i=1;i<=6;i++){
        texture.loadFromFile("../Data/DataEffect/Coins/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataEffect.insert({"TakeCoins",listTexture});
    listTexture.clear();
}

void Data::loadDataOutro () {
    vector<Texture> listTexture;
    for(int i=1;i<=9;i++){
        texture.loadFromFile("../Data/DataOutro/gameOver/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }
    DataListOutro.insert({"gameOver",listTexture});
    listTexture.clear();

    for(int i=1;i<=10;i++){
        texture.loadFromFile("../Data/DataOutro/impostor/"+to_string(i)+".png");
        listTexture.push_back(texture);
    }

    DataListOutro.insert({"impostor",listTexture});

    texture.loadFromFile("../Data/DataOutro/close.png");
    DataOutro.insert({"close",texture});
    texture.loadFromFile("../Data/DataOutro/home.png");
    DataOutro.insert({"home",texture});
    texture.loadFromFile("../Data/DataOutro/resume.png");
    DataOutro.insert({"resume",texture});
    texture.loadFromFile("../Data/DataOutro/table.png");
    DataOutro.insert({"table",texture});
    texture.loadFromFile("../Data/DataOutro/youLose.png");
    DataOutro.insert({"youLose",texture});


}

map<string,vector<Texture> >& Data::getBug (const string& nameData) {
    return DataBug.at(nameData);
}

vector<Texture>& Data::getBullet () {
    return DataBullet.at("allLevelBullet");
}

vector<Texture>& Data::getMap (string nameData) {
    return DataMap.at(nameData);
}

Texture& Data::getShooter (const string& nameData) {
    return DataShooter.at(nameData);
}

Texture& Data::getButton (const string& nameData) {
    return DataButton.at(nameData);
}

Font& Data::getFont () {
    return this->font;
}

vector<Texture>& Data::getListButton (const string& nameData) {
    return DataListButton.at(nameData);
}

vector<Texture>& Data::getBlooding (const string& nameData) {
    return DataBlooding.at(nameData);
}

vector<Texture>& Data::getEffect (string nameData) {
    return DataEffect.at(nameData);
}

Texture& Data::getIntro (const string& nameData) {
    return DataIntro.at(nameData);
}

vector<Texture>& Data::getListIntro (const string& namePath) {
    return DataListIntro.at(namePath);
}

Texture &Data::getOutro (const string &namePath) {
    return DataOutro.at(namePath);
}

vector<Texture> &Data::getListOutro (const string &namePath) {
    return DataListOutro.at(namePath);
}

Music &Data::getMusic (const string &namePath) {
    return DataMusic.at(namePath);
}





