#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;


class Rules: public Drawable{



 private:

      int  _option,_stateWindow,_size=10;
      Font font;
      Text quitOptionText;
      Text rulesText;
      Text titleText;


 public:

      Rules();
      void LoadDraw(sf::Vector2u ventanaSize);
      int getStateWindow();
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
      void update(sf::RenderWindow& window);


};

