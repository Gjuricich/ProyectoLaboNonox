#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;


class AuxiliarScreens: public Drawable{

 private:

      int  _option,_stateWindow,_size=10;
      Font font;
      Text askNameText;
      Texture arrowTexture;
      Sprite arrowSprite;

 public:

      AuxiliarScreens();
      void LoadDraw(sf::Vector2u ventanaSize);
      int getStateWindow();
      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
