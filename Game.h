//
// Created by duonglh on 30/10/2020.
//

#ifndef DEFENDERPRO_GAME_H
#define DEFENDERPRO_GAME_H
#include "Bug.h"
#include "TableButton.h"
#include "Shooter.h"
#include "Map.h"
#include "Data.h"
#include "TakeCoins.h"
class Game {
private:
    enum isButton{
        D19Button=1,
        D18Button=2,
        D17Button=3,
        GeekForGeekButton=4,
        GitHubButton=5,
        StackOverFlowButton=6,
    };

    enum direct{
        Down,Up,Left,Right
    };
    enum CurrentBug{
        ListBug,ListBugGod
    };
    RenderWindow *window{};
    RectangleShape mapPointer,sellShooter,xWarning,ProTower,
                   GitHub,GeekForGeek,StackOverFlow,localWarning,
                   leftCloud,rightCloud;
    TableButton tableButton;
    Shooter D17,D18,D19;
    Bug bug,bugGod;
    Map map;
    vector<Shooter> listShooter;
    vector<pair<direct,Bug> > listBug;
    vector<TakeCoins> takeCoinsEffect;
    unsigned short coins,death,numberCurrentListBug,currentListBug,currentShooter,countBug,frameLimit;
    float scores,BugHp,BugGodHp,BugSpeed,BugGodSpeed,deltatime,
          totalTimeBug,totalTimeListBug,switchTimeBug,switchTimeListBug,
          BugArmor,BugGodArmor,totalTimeLocalWarning,currentLocalWaring{},totalTimeGameOver;
    bool preD19,preD18,preD17,noPush,ProBeDamage,preGitHub,
         preGeekForGeek,preStackOverFlow,nextList,isLocalWarning,
         increase{},pause,start,currentPre{},gameOver;
    FloatRect mousePointer;
    Vector2f mousePosition;
    Clock clock;
public:
    Game ();
    void newGame();
    void Init(Data&,RenderWindow*&);
    void getEvents();
    void update(short&);
    void draw();
    pair<unsigned short,unsigned short> getCurrentStates();
};


#endif //DEFENDERPRO_GAME_H
