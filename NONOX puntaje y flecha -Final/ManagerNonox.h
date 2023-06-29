#pragma once
#include "menuNonox.h"
#include "ArchiveScore.h"
#include "Level.h"
#include "Timer.h"
#include "Ranking.h"
#include "Credits.h"
#include "Rules.h"
#include "AuxiliarScreens.h"
#include <iostream>
using namespace std;


class ManagerNonox {

private:

     sf::RenderWindow window;
     MenuNonox _menu;
     Score _score;
     Rules _rules;
     ArchiveScore _archivoScore;
     Ranking _ranking;
     Credits _credits;
     AuxiliarScreens _auxScreens;
     int _stateWindow;

public:

     ManagerNonox();
     sf::RenderWindow &getWindow() {return window;}
     void setStateWindow(int s);
     int getStateWindow();
     void update();
     void run(Level &level,int numberLevel);
     bool newGame();
     int isGreater(int s);
     void saveScoreArchive();
     void cleanScore();

};
