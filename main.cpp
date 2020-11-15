
#include "Data.h"
#include "Intro.h"
#include "Game.h"
#include "Outro.h"

enum States{
    newGame=1,
    gameRunning=2,
    endGame=3
};
int main(){
    auto *window = new RenderWindow(VideoMode(1920,1080),"DEFENDER PROPTIT",Style::Fullscreen);
    window->setFramerateLimit(60);
    Event event{};
    short currentState=newGame;

    Data data;
    Intro intro;
    Game game;
    Outro outro;

    data.loadDataIntro();
    data.loadDataGame();
    data.loadDataOutro();

    intro.Init(data,window);
    game.Init(data,window);
    outro.Init(data,window);

    while(window->isOpen()){
        while(window->pollEvent(event)){
            if(event.type==Event::Closed || Keyboard::isKeyPressed(Keyboard::Q)){
                window->close();
            }
        }
        if(currentState==newGame){
            intro.getEvents();
            intro.update(currentState);
            intro.draw();
            if(currentState==gameRunning){
                game.newGame();
            }
        }
        else if(currentState==gameRunning) {
            game.getEvents ();
            game.update (currentState);
            game.draw ();
            if(currentState==endGame){
                outro.newOutro();
                outro.setCurrentState(game.getCurrentStates());

            }
        }
        else if(currentState==endGame){
            outro.update(currentState);
            outro.draw();
            if(currentState==newGame){
                intro.newIntro();
            }
        }
    }
    return 0;
}