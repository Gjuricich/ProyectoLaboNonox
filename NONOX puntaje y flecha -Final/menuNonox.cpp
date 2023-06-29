#include "menuNonox.h"


 void MenuNonox::LoadDraw(sf::Vector2u ventanaSize) {

        _option = -1;
        _size=5;
        _stateWindow=-1;
        _yPosition = 270;
        int xPosition=(ventanaSize.x/2)-200;
        string menuOption[5]={"New game","Score","Credits","Rules","Exit"};

        font.loadFromFile("Fuente.ttf");
        titleTexture.loadFromFile("titulo.png");
        titleSprite.setTexture(titleTexture);
        titleSprite.setPosition(xPosition,100);

        backgroundTexture.loadFromFile("Fondo.png");
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setPosition(110,0);
        backgroundSprite.setScale(0.4f, 0.4f);


        for (int i = 0; i < _size; ++i) {
            menuText[i].setFont(font);
            menuText[i].setString(menuOption[i]);
            menuText[i].setCharacterSize(50);
            menuText[i].setFillColor(Color::White);
            menuText[i].setPosition(xPosition+50, _yPosition);
            _yPosition += 50;
        }
 }


void MenuNonox::draw(RenderTarget& target, RenderStates states) const {

        target.draw(backgroundSprite);
        target.draw(titleSprite);
        for(int i=0;i<_size;i++){
            target.draw(menuText[i]);
        }
     }


int MenuNonox::getStateWindow(){return _stateWindow;}

void MenuNonox::update(RenderWindow& window){

          sf::Vector2i mousePos = Mouse::getPosition(window);
          _option = -1;
          _stateWindow=-1;
          for(int i = 0; i < _size; ++i){
            if(menuText[i].getGlobalBounds().contains(mousePos.x, mousePos.y)){
                _option = i;
                menuText[i].setFillColor(Color::Cyan);
            }else{
                menuText[i].setFillColor(Color::White);
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left)){
        _stateWindow=_option;
        }

    }


