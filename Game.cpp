//
// Created by duonglh on 30/10/2020.
//

#include "Game.h"

Game::Game () {
    newGame();
}

void Game::newGame () {
    tableButton.newTableButton();
    this->listShooter.clear();
    this->listBug.clear();
    this->coins=200;
    this->death=0;
    this->scores=0;
    this->BugHp=100;
    this->BugGodHp=300;
    this->BugSpeed=2;
    this->BugGodSpeed=3;
    this->BugArmor=70;
    this->BugGodArmor=90;
    this->preD19=false;
    this->preD18=false;
    this->preD17=false;
    this->preGeekForGeek=false;
    this->preGitHub=false;
    this->preStackOverFlow=false;
    this->pause= false;
    this->start=true;
    this->isLocalWarning=false;
    this->gameOver=false;
    this->noPush=false;
    this->ProBeDamage=false;
    this->nextList=false;
    this->numberCurrentListBug=0;
    this->currentListBug=ListBug;
    this->totalTimeBug=0;
    this->totalTimeListBug=0;
    this->totalTimeGameOver=0;
    this->switchTimeBug=20.f/BugGodSpeed;
    this->switchTimeListBug=500.f/BugGodSpeed;
    this->currentListBug=0;
    this->totalTimeLocalWarning=0;
    this->currentShooter=0;
    this->countBug=0;
    this->frameLimit=60;
    this->listShooter.resize(100);
    this->deltatime=0;
    this->mapPointer.setSize(Vector2f(64,64));
    this->mapPointer.setOutlineThickness(2.f);
    this->mapPointer.setOutlineColor(Color::Black);
    this->mapPointer.setFillColor(Color(0,0,0,0));
    this->takeCoinsEffect.resize(20);
    // khởi tạo các thông số cơ bản cho shooter
    this->D19.setSpeedForBullet(10.f);
    this->D19.setDamageForBullet(100);
    this->D19.setFireTime(0.3);
    this->D19.setRange(150);

    this->D18.setSpeedForBullet(10.f);
    this->D18.setDamageForBullet(150);
    this->D18.setFireTime(0.2);
    this->D18.setRange(175);

    this->D17.setSpeedForBullet(10.f);
    this->D17.setDamageForBullet(200);
    this->D17.setFireTime(0.1);
    this->D17.setRange(200);
    this->D17.setTrueDamage(2);

    this->bug.setArmor(BugArmor);
    this->bug.setBlood(BugHp);
    this->bug.setSpeed(BugSpeed);
    this->bug.setScale(Vector2f(2,2));

    this->bugGod.setArmor(BugGodArmor);
    this->bugGod.setBlood(BugGodHp);
    this->bugGod.setSpeed(BugGodSpeed);

}

void Game::Init (Data &dataBase, RenderWindow *&_window) {
    this->window=_window;
    this->localWarning.setSize((Vector2f) window->getSize());
    // set Map
    map.setMap(dataBase.getMap("baseMap"));

    // set shooter
    D19.setTexture(1,dataBase.getShooter("D19"),dataBase.getBullet());

    D18.setTexture(2,dataBase.getShooter("D18"),dataBase.getBullet());

    D17.setTexture(3,dataBase.getShooter("D17"),dataBase.getBullet());

    // set bug;
    bug.setData(dataBase.getBug("Bug"),dataBase.getBlooding("Blooding"));
    bug.setPosition(Vector2f(64*6+30,0));

    // set bugGod
    bugGod.setData(dataBase.getBug("BugGod"),dataBase.getBlooding("Blooding"));
    bugGod.setPosition(Vector2f(64*6+30,0));

    //set buff
    this->GitHub.setTexture(&dataBase.getButton("GitHub"));
    this->GitHub.setSize((Vector2f)dataBase.getButton("GitHub").getSize());
    this->GitHub.setOrigin((Vector2f)dataBase.getButton("GitHub").getSize()*0.5f);

    this->GeekForGeek.setTexture(&dataBase.getButton("GeekForGeek"));
    this->GeekForGeek.setSize((Vector2f)dataBase.getButton("GeekForGeek").getSize());
    this->GeekForGeek.setOrigin((Vector2f)dataBase.getButton("GeekForGeek").getSize()*0.5f);

    this->StackOverFlow.setTexture(&dataBase.getButton("StackOverFlow"));
    this->StackOverFlow.setSize((Vector2f)dataBase.getButton("StackOverFlow").getSize());
    this->StackOverFlow.setOrigin((Vector2f)dataBase.getButton("StackOverFlow").getSize()*0.5f);

    // set tableButton
    tableButton.Init(dataBase.getButton("Table"),dataBase.getButton("coinsBag"),
                     dataBase.getButton("skull"),dataBase.getButton("score"),
                     dataBase.getButton("logoPro"),dataBase.getButton("heart"),
                     dataBase.getButton("QR"),dataBase.getButton("barHP"),
                     dataBase.getButton("HP"),dataBase.getButton("barFullHP"),
                     dataBase.getButton("fullHP"),dataBase.getButton("PointsHP"),
                     dataBase.getButton("Play"),dataBase.getButton("Pause"),
                     dataBase.getButton("minus"),dataBase.getButton("nextList"),
                     dataBase.getButton("plus"),dataBase.getButton("googlePlay"),
                     dataBase.getButton("setting"),dataBase.getButton("close"));

    tableButton.setListTextureButton(dataBase.getListButton("shooterButton"),dataBase.getListButton("addButton"));
    tableButton.setFont(dataBase.getFont());
    tableButton.setInformationButton(dataBase.getListButton("InformationButton"));

    // set takeCoins
    Vector2f coinsBagPosition = tableButton.getPositionCoinsBag();
    for(TakeCoins &takeCoins:takeCoinsEffect){
        takeCoins.setListTexture(dataBase.getEffect("TakeCoins"));
        takeCoins.setEndPosition(coinsBagPosition);
    }

    sellShooter.setTexture(&dataBase.getButton("sell"));
    sellShooter.setSize((Vector2f)sellShooter.getTexture()->getSize());
    sellShooter.setOrigin(Vector2f(10,sellShooter.getSize().y));
    sellShooter.setScale(Vector2f(0.5,0.5));

    //set x warning
    xWarning.setTexture(&dataBase.getButton("xWarning"));
    xWarning.setSize((Vector2f)xWarning.getTexture()->getSize());
    xWarning.setOrigin(xWarning.getSize()*0.5f);

    this->ProTower.setTexture(&dataBase.getMap("ProTower").at(0));
    this->ProTower.setSize((Vector2f)ProTower.getTexture()->getSize());
    this->ProTower.setPosition(Vector2f(12*64+32,14*64+30));

    this->leftCloud.setTexture(&dataBase.getIntro("leftClouds"));
    this->leftCloud.setSize(Vector2f(1500,1080));
    this->leftCloud.setPosition(Vector2f(-80,0));

    this->rightCloud.setTexture(&dataBase.getIntro("rightClouds"));
    this->rightCloud.setSize(Vector2f(1500,1080));
    this->rightCloud.setPosition((Vector2f(500,0)));

}//Init

void Game::getEvents () {
    deltatime=clock.restart().asSeconds();
    //update mousePosition
    this->mousePosition=(Vector2f)Mouse::getPosition(*window);
    // update mousePointer
    this->mousePointer= FloatRect (mousePosition.x,mousePosition.y,0.001f,0.001f);
    currentPre = preD19 | preD18 | preD17 | preGeekForGeek | preGitHub | preStackOverFlow;
    // sự kiện đặc biệt
    pause=tableButton.isClickPauseButton(mousePointer,deltatime);
    if(tableButton.isClickCloseButton(mousePointer)) window->close();
    //
    if(!pause) {
        if (mousePosition.x > 1280) {// nếu mouse trong vùng của table thì mới xét sự kiện trên table: 20*64
            int isClickButton = tableButton.isClickButton (mousePointer);
            if (!currentPre) {
                //pick shooter
                if (isClickButton == D19Button && coins >= 75) preD19 = true;
                else if (isClickButton == D18Button && coins >= 150) preD18 = true;
                else if (isClickButton == D17Button && coins >= 200) preD17 = true;
                    //pick buff
                else if (isClickButton == GeekForGeekButton && coins >= 50) preGeekForGeek = true;
                else if (isClickButton == GitHubButton && coins >= 100) preGitHub = true;
                else if (isClickButton == StackOverFlowButton && coins >= 150) preStackOverFlow = true;
            } else {
                // delete pre shooter
                if (Mouse::isButtonPressed (Mouse::Right)) {
                    int isOnButton = tableButton.isOnButton (mousePointer);
                    if (isOnButton == D19Button) preD19 = false;
                    else if (isOnButton == D18Button) preD18 = false;
                    else if (isOnButton == D17Button) preD17 = false;
                    //delete pre buff
                    if (isOnButton == GeekForGeekButton) preGeekForGeek = false;
                    else if (isOnButton == GitHubButton) preGitHub = false;
                    else if (isOnButton == StackOverFlowButton) preStackOverFlow = false;
                }
            }
        } else {
            //choose position shooter and buff
            if (currentPre && Mouse::isButtonPressed (Mouse::Left)) {
                if (!noPush) {
                    if (preD19) {
                        preD19 = false;
                        listShooter[currentShooter] = D19;
                        currentShooter++;
                        coins -= 75;
                    } else if (preD18) {
                        preD18 = false;
                        listShooter[currentShooter] = D18;
                        currentShooter++;
                        coins -= 150;
                    } else if (preD17) {
                        preD17 = false;
                        listShooter[currentShooter] = D17;
                        currentShooter++;
                        coins -= 200;
                    }
                } else {
                    //buff shooter
                    for (int i = 0; i < currentShooter; i++) {
                        if (listShooter[i].getShooterBound ().intersects (mousePointer)) {
                            if (preGeekForGeek) {
                                listShooter[i].buff (10, 0, 0, 0);
                                preGeekForGeek = false;
                                coins -= 50;
                            } else if (preGitHub) {
                                listShooter[i].buff (0, 0, 5, 0.1);
                                preGitHub = false;
                                coins -= 100;
                            } else if (preStackOverFlow) {
                                listShooter[i].buff (5, 2, 0, 0);
                                preStackOverFlow = false;
                                coins -= 150;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}//getEvents

void Game::update (short &currentState) {
    if(tableButton.getProHP()<=-2) {
        gameOver=true;
        if (leftCloud.getPosition ().x < -80) {
            leftCloud.move (Vector2f (10.f, 0));
            rightCloud.move (Vector2f (-10.f, 0));
        } else {
            totalTimeGameOver += deltatime;
            if (totalTimeGameOver >= 1.f) {
                currentState=3;
                return;
            }
        }
    }
    if(!pause && !gameOver) {
        // update ProHP and local Warning
        if (tableButton.getProHP () < 4) {
            isLocalWarning = true;
            totalTimeLocalWarning += deltatime;
            if (totalTimeLocalWarning >= 0.08f) {
                totalTimeLocalWarning -= 0.08f;
                if (increase) currentLocalWaring += 15;
                else currentLocalWaring -= 15;
                if (currentLocalWaring >= 50) increase = false;
                if (currentLocalWaring <= 0) increase = true;
            }
            localWarning.setFillColor (Color (255, 0, 0, currentLocalWaring));
        }

        // update shooter ưu tiên bắn bug gần trụ sở nhất.
        for (int e=0;e<currentShooter;e++) {
            short i = 0;
            listShooter[e].updateBullet();
            for (pair<direct, Bug> &m_Bug:listBug) {
                if (listShooter[e].update (m_Bug.second.getPosition (), deltatime)) {// kiểm tra xem bug có nằm trong tầm bắn k?
                    if (listShooter[e].checkCollision (m_Bug.second.getBound ())) {// kiểm tra đạn có trúng bug k?
                        m_Bug.second.beDamage (listShooter[e].getAllDamage());
                        // nếu bug chết thì update coins và death
                        if (!m_Bug.second.isAlive ()) {
                            death++;
                            for (TakeCoins &takeCoins:takeCoinsEffect) {
                                if (!takeCoins.display) {
                                    takeCoins.display = true;
                                    takeCoins.setValue((unsigned short)(m_Bug.second.getBlood () * 0.01f));
                                    takeCoins.setBeginPosition (m_Bug.second.getPosition ());
                                    break;
                                }
                            }
                            listBug.erase (listBug.begin () + i);
                        }
                    }
                    break;
                }
                i++;
            }
        }

        //update takeCoins effect
        for (TakeCoins &takeCoins:takeCoinsEffect) {
            if (takeCoins.display) {
                takeCoins.update (deltatime,coins);
            }
        }

        // update bug
        for (pair<direct,Bug> &m_Bug:listBug) {
            if (m_Bug.second.isAlive ()) {
                Vector2f bugPosition = m_Bug.second.getPosition();
                auto i = short ((bugPosition.y-30) / 64);
                auto j = short ((bugPosition.x-30) / 64);
                float bugSpeed = m_Bug.second.getSpeed();
                int numberMap = map.getNumberMap (i, j);
                if (numberMap == 24) m_Bug.first = Left;
                else if((numberMap == 25 && bugPosition.x <= (float)j * 64 + 30 + bugSpeed) || numberMap == 19)
                        m_Bug.first = Down;
                else if((numberMap == 27 && bugPosition.y >= (float)i * 64 + 94 - bugSpeed) || numberMap == 17)
                        m_Bug.first = Right;
                else if(numberMap == 28 && bugPosition.x >= (float)j * 64 + 94 - bugSpeed)
                    m_Bug.first = Up;

                m_Bug.second.update (m_Bug.first, deltatime);
            }
        }
        // check proBeDamage
        short e = 0;
        for (pair<direct,Bug> &m_Bug : listBug) {
            if (m_Bug.second.getPosition().y>=1000) {
                ProBeDamage = true;
                listBug.erase (listBug.begin () + e);
                break;
            }
            e++;
        }

        // update scores
        if(!start)scores += 0.01f;
        tableButton.update (coins,death,scores,mousePointer,ProBeDamage);
        if (ProBeDamage) ProBeDamage = false;

        // update pre
        if (preD19)
            D19.setPosition (Vector2f (int ((mousePosition.x-30) / 64) * 64 + 62, int ((mousePosition.y-30) / 64) * 64 + 62));
        else if (preD18)
            D18.setPosition (Vector2f (int ((mousePosition.x-30) / 64) * 64 + 62, int ((mousePosition.y-30) / 64) * 64 + 62));
        else if (preD17)
            D17.setPosition (Vector2f (int ((mousePosition.x-30) / 64) * 64 + 62, int ((mousePosition.y-30) / 64) * 64 + 62));
        else if (preGeekForGeek) GeekForGeek.setPosition (mousePosition);
        else if (preGitHub) GitHub.setPosition (mousePosition);
        else if (preStackOverFlow) StackOverFlow.setPosition (mousePosition);

        // sell shooter
        for (int i=0;i<currentShooter;i++) {
            if (listShooter[i].getShooterBound ().intersects (mousePointer) && Mouse::isButtonPressed (Mouse::Right)) {
                listShooter.erase (listShooter.begin () + i);
                currentShooter--;
                coins += int (listShooter[i].getAllDamage ().first * 0.2f + listShooter[i].getAllDamage ().second * 0.8f);// tiền bán được tính theo 20% damage thường và 80% sát thương chuẩn.
                break;
            }
        }

        // tính toán thời gian giữa 2 con bug và giữa 2 listBug
        tableButton.isClickNextListButton(mousePointer);
        if(!nextList) {
            nextList=tableButton.isClickNextListButton(mousePointer);
            totalTimeBug=switchTimeListBug;
        }
        if (!nextList) {
            totalTimeListBug += 0.05;
            if (totalTimeListBug >= switchTimeListBug) {
                totalTimeListBug = 0;
                totalTimeBug = 0;
                nextList = true;
            }
        } else {
            totalTimeBug += 0.05;
            if (totalTimeBug >= switchTimeBug) {
                totalTimeBug = 0;
                if (currentListBug == ListBug) listBug.emplace_back (Down, bug);
                else listBug.emplace_back (Down, bugGod);
                numberCurrentListBug++;
                if (numberCurrentListBug >= 10) {
                    numberCurrentListBug = 0;
                    if (currentListBug == ListBugGod) {
                        this->BugGodHp += this->BugGodHp * 0.07f;
                        this->BugGodArmor += this->BugGodArmor * 0.04f;
                        this->BugGodSpeed += 0.07f;
                        bugGod.setSpeed (BugGodSpeed);
                        bugGod.setBlood (BugGodHp);
                        bugGod.setArmor (BugGodArmor);
                        switchTimeBug = 20.f / BugGodSpeed;
                        switchTimeListBug = 500.f / BugGodSpeed;
                    } else {
                        this->BugHp += this->BugHp * 0.06f;
                        this->BugArmor += this->BugArmor * 0.03f;
                        this->BugSpeed += 0.05f;
                        bug.setArmor (BugArmor);
                        bug.setBlood (BugHp);
                        bug.setSpeed (BugSpeed);
                    }
                    if(countBug<=2) {
                        // 2 turn đầu là bug
                        currentListBug=ListBug;
                        countBug++;
                    }
                    else {
                        if (int (random () % 2)) {
                            if(currentListBug == ListBugGod) currentListBug = ListBug;
                            else currentListBug = ListBugGod;
                        }
                        else currentListBug = ListBug;
                    }
                    nextList = false;
                }
            }
        }
        int control=tableButton.otherButton(mousePointer);
        if(control==1){
            frameLimit-=3;
            if(frameLimit<=60) frameLimit=60;
            window->setFramerateLimit(frameLimit);
        }
        else if(control==2){
            frameLimit+=2;
            if(frameLimit>=200) frameLimit=200;
            window->setFramerateLimit(frameLimit);
        }
    }
    if(start){
        if(leftCloud.getPosition().x>-1500){
            leftCloud.move(Vector2f(-10.f,0));
            rightCloud.move(Vector2f(10.f,0));
        }
        else start = false;
    }

    // 1 số buff ẩn :v
    if(Keyboard::isKeyPressed(Keyboard::Num1)){
        BugGodSpeed+=0.01;
        BugGodArmor+=20;
        BugGodHp+=100;
        bugGod.setSpeed (BugGodSpeed);
        bugGod.setBlood (BugGodHp);
        bugGod.setArmor (BugGodArmor);
    }
    if(Keyboard::isKeyPressed(Keyboard::Num2)){
            BugSpeed+=0.005;
            BugArmor+=10;
            BugHp+=50;
            bug.setArmor (BugArmor);
            bug.setBlood (BugHp);
            bug.setSpeed (BugSpeed);
    }
    if(Keyboard::isKeyPressed(Keyboard::Num3)){
        for(int i=0;i<currentShooter;i++){
            listShooter[i].buff(10,1,1,0.1);
        }
        cout<<listShooter[0].getAllDamage().first<<' '<<listShooter[0].getAllDamage().second<<endl;
    }
    if(Keyboard::isKeyPressed(Keyboard::Num4)){
            coins+=100;
            scores+=50;
            death+=25;
    }
    if(Keyboard::isKeyPressed(Keyboard::Num5)){
        for(int i=0;i<currentShooter;i++){
            listShooter[i].buff(0,0,0,1);
        }
    }

}// update

void Game::draw () {
    window->clear(Color(71, 40, 0));
    // draw map
    map.draw(*window);
    //draw table button
    tableButton.draw(*window);

    //vẽ pre nếu có và xử lý TH xem có thể đặt vị trí của shooter dc không.
    if(currentPre) {
        if (preD19) D19.draw (*window, true);
        else if (preD18) D18.draw (*window, true);
        else if (preD17) D17.draw (*window, true);
        // draw pre buff
        else if (preGeekForGeek) window->draw (GeekForGeek);
        else if (preGitHub) window->draw (GitHub);
        else if (preStackOverFlow) window->draw (StackOverFlow);
        Vector2i intNum = Vector2i ((mousePosition.x - 30) / 64.f,(mousePosition.y - 30) / 64.f);
        if (preD19 || preD18 || preD17) {
            if (map.getNumberMap (intNum.y,intNum.x) == 1) {
                mapPointer.setPosition (Vector2f(intNum.x * 64 + 30,intNum.y * 64 + 30));
                window->draw (mapPointer);
                noPush = false;
            } else {
                xWarning.setPosition (Vector2f (intNum.x * 64 + 62,intNum.y * 64 + 62));
                window->draw (xWarning);
                noPush = true;
            }
            for (Shooter &shooter:listShooter) {
                if (shooter.getShooterBound ().intersects (mousePointer)) {
                    xWarning.setPosition (Vector2f (intNum.x * 64 + 62,intNum.y * 64 + 62));
                    window->draw (xWarning);
                    noPush = true;
                    break;
                }
            }
        }
        else noPush=true;
    }

    // draw list shooter
    for(int i=0;i<currentShooter;i++) {
        if(listShooter[i].getShooterBound().intersects(mousePointer)){// kiểm tra xem con trỏ có trỏ vào shooter thứ i hay không?
            listShooter[i].draw(*window,true);
            mapPointer.setPosition(Vector2f(int(listShooter[i].getPosition().x/64)*64 + 30,int(listShooter[i].getPosition().y/64)*64 +30));
            window->draw(mapPointer);
            if(!currentPre){
                sellShooter.setPosition(mousePosition.x-15,mousePosition.y);
                window->draw(sellShooter);
            }
        }
        else listShooter[i].draw (*window, false);
    }

    //draw list bug
    for(pair<direct,Bug> &m_Bug : listBug) {
        if(m_Bug.second.getPosition().y>80)
            m_Bug.second.draw (*window);
    }
    //draw takeCoins Effect
    for(TakeCoins &takeCoins:takeCoinsEffect){
        if(takeCoins.display){
            takeCoins.draw(*window);
        }
    }
    //draw proTower
    window->draw(ProTower);
    if(isLocalWarning && !gameOver) window->draw(localWarning);
    if(gameOver || start){
        window->draw(leftCloud);
        window->draw(rightCloud);
    }
    window->display();
}//draw

pair<unsigned short,unsigned short> Game::getCurrentStates () {
    return make_pair(scores,death);
}


