#include "menuNonox.h"


 MenuNonox::MenuNonox() {

        _option = -1;
        _size=5;
        _stateWindow=-1;
        _yPosition = 250;

        font.loadFromFile("Fuente.ttf");
        titleTexture.loadFromFile("titulo.png");
        titleSprite.setTexture(titleTexture);
        titleSprite.setPosition(170, 80);


         for (int i = 0; i < _size; ++i) {
            menuText[i].setFont(font);
            menuText[i].setString(menuOption[i]);
            menuText[i].setCharacterSize(50);
            menuText[i].setFillColor(Color::White);
            menuText[i].setPosition(180, _yPosition);
            _yPosition += 50;
        }
     }

void MenuNonox::draw(RenderTarget& target, RenderStates states) const {

        target.draw(titleSprite);
        for(int i=0;i<_size;i++){
            target.draw(menuText[i]);
        }
     }


int MenuNonox::getStateWindow(){return _stateWindow;}

void MenuNonox::update(RenderWindow& window) {

          sf::Vector2i mousePos = Mouse::getPosition(window);
          _option = -1;
          _stateWindow=-1;

          for (int i = 0; i < _size; ++i) {

            if (menuText[i].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                _option = i;
                menuText[i].setFillColor(Color::Cyan);
            } else {
                menuText[i].setFillColor(Color::White);
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {

        _stateWindow=_option;}

    }


