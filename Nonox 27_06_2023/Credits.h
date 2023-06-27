#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;


class Credits: public Drawable{



 private:

      int  _option,_stateWindow,_size=10;
      Font font;
      Text quitOptionText;
      Text creditsText;
      Text titleText;


 public:

      Credits();
      int getStateWindow();
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
      void update(sf::RenderWindow& window);


};
