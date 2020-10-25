//
// Created by duonglh on 23/10/2020.
//

#include "Data.h"
#include <iostream>
void Data::loadFromFile () {
    string nameTexture;
    vector<Texture> tmp;
    vector<string> namePath = {"Down","Up", "Left", "Right"};
    // load Data Bug
    map<string,vector<Texture> >TMP;
    for(int i=0;i<namePath.size();i++) {
        for(int j=1;j<=6;j++){
            texture.loadFromFile("../Data/DataBug/Bug/"+namePath[i]+"/"+to_string(j)+".png");
            tmp.push_back(texture);
        }
        TMP.insert({namePath[i],tmp});
        tmp.clear();
    }
    DataBug.insert({"Bug",TMP});

    // load data BugGod
    TMP.clear();
    tmp.clear();
    for(int i=0;i<namePath.size();i++) {
        for(int j=1;j<=6;j++){
            texture.loadFromFile("../Data/DataBug/BugGod/"+namePath[i]+"/"+to_string(j)+".png");
            tmp.push_back(texture);
        }
        TMP.insert({namePath[i],tmp});
        tmp.clear();
    }
    DataBug.insert({"BugGod",TMP});

    // load Data Bullet
    texture.loadFromFile("../Data/DataBullet/Blue.png");
    DataBullet.insert({"Blue",texture});

//    texture.loadFromFile("../Data/DataBullet/BlueBullet2.png");
//    DataBullet.insert({"lightBlue",texture});

//    texture.loadFromFile("../Data/DataBullet/GreenBullet.png");
//    DataBullet.insert({"Green",texture});

    texture.loadFromFile("../Data/DataBullet/Red.png");
    DataBullet.insert({"Red",texture});

    //load Data Map

    tmp.clear();
    for(int i=0;i<=28;i++){
        texture.loadFromFile("../Data/DataMap/"+to_string(i)+".png");
        tmp.push_back(texture);
    }
    DataMap.insert({"baseMap",tmp});


    //load Data Shooter

    for(int i=17;i<=19;i++){
        nameTexture="D"+to_string(i);
        texture.loadFromFile("../Data/DataShooter/"+nameTexture+".png");
        DataShooter.insert({nameTexture,texture});
    }

    // load Data Avatar

    for(int i=17;i<=19;i++){
        nameTexture="D"+to_string(i);
        texture.loadFromFile("../Data/DataAvatar/"+nameTexture+".png");
        DataAvatar.insert({nameTexture,texture});
    }

}

map<string,vector<Texture> >Data::getDataBug (string nameData) {
    return DataBug.at(nameData);
}

Texture Data::getDataBullet (string nameData) {
    return DataBullet.at(nameData);
}

vector<Texture> Data::getDataMap (string nameData) {
    return DataMap.at(nameData);
}

Texture Data::getDataShooter (string nameData) {
    return DataShooter.at(nameData);
}

Texture Data::getDataAvatar (string nameData) {
    return DataAvatar.at(nameData);
}


