//
// Created by duonglh on 19/10/2020.
//

#ifndef DEFENDERPRO_INTRO_H
#define DEFENDERPRO_INTRO_H
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;
class Intro {
private:
    RenderWindow window;
    Event event;
    RectangleShape barLoading,loading;
    int percentLoading;
    Clock clock;
public:
    Intro();
    void draw();


};


#endif //DEFENDERPRO_INTRO_H
