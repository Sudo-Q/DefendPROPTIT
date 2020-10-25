//
// Created by duonglh on 23/10/2020.
//

#ifndef DEFENDERPRO_DATA_H
#define DEFENDERPRO_DATA_H
#include "SFML/Graphics.hpp"
#include <vector>
#include <map>
using namespace std;
using namespace sf;
class Data {
private:
    Texture texture;
    Font font;
    map<string,map<string,vector<Texture> > >DataBug;
    map<string,Texture> DataBullet;
    map<string,vector<Texture> >DataMap;
    map<string,Texture> DataShooter;
    map<string,Texture> DataAvatar;
public:
    Data(){};
    void loadFromFile();
    map<string,vector<Texture> > getDataBug(string);
    Texture getDataBullet(string);
    vector<Texture> getDataMap(string);
    Texture getDataShooter(string);
    Texture getDataAvatar(string);

};


#endif //DEFENDERPRO_DATA_H
