//
// Created by duonglh on 23/10/2020.
//

#ifndef DEFENDERPRO_DATA_H
#define DEFENDERPRO_DATA_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include <map>
using namespace std;
using namespace sf;
class Data {
private:
    Texture texture;
    Font font;
    map<string,map<string,vector<Texture> > >DataBug;
    map<string,vector<Texture> >DataMap,DataListButton,DataBlooding,DataEffect,
                                DataBullet,DataListIntro,DataListOutro;
    map<string,Texture> DataShooter;
    map<string,Texture> DataButton;
    map<string,Texture> DataIntro;
    map<string,Texture> DataOutro;
    map<string,Music> DataMusic;
public:
    Data(){};
    void loadDataIntro();
    void loadDataGame();
    void loadDataOutro();
    map<string,vector<Texture> >& getBug(const string&);
    vector<Texture>& getBullet();
    vector<Texture>& getMap(string);
    Texture& getShooter(const string&);
    Texture& getButton(const string&);
    vector<Texture>& getListButton(const string&);
    vector<Texture>& getBlooding(const string&);
    vector<Texture>& getEffect(string);
    Texture& getIntro(const string&);
    vector<Texture>& getListIntro(const string&);
    Texture& getOutro(const string&);
    vector<Texture>& getListOutro(const string&);
    Music& getMusic(const string&);
    Font& getFont();

};


#endif //DEFENDERPRO_DATA_H
