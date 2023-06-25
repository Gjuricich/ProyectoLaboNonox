#pragma once
#include "menuNonox.h"
#include "ArchiveScore.h"
#include "Level.h"
#include "Timer.h"




class ManagerNonox {

private:

     sf::RenderWindow window;
     MenuNonox _menu;
     Score _score;
     int _stateWindow;

public:

     ManagerNonox();

     sf::RenderWindow &getWindow() {return window;}
     void setStateWindow(int s);
     int getStateWindow();
     void NewGame();

     void update(sf::RenderWindow& window);
     void run(sf::RenderWindow &window,Level &level);
     bool newGame(sf::RenderWindow &ventana);


};
