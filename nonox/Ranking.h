#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
#include "cstring"
#include "ArchiveScore.h"




class Ranking: public Drawable{



 private:

      int  _option,_stateWindow,_size=10;
      Font font;
      Text quitOptionText;
      Text playerText[10];
      Text playerScoreText[10];
      Texture backgroundTexture;
      Sprite backgroundSprite;

 public:

      Ranking();

      int getStateWindow();
      void LoadDraw(sf::Vector2u ventanaSize);
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
      void update(sf::RenderWindow& window);
      void LoadDrawUpdate(sf::Vector2u ventanaSize);


};
