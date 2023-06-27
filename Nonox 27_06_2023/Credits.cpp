#include "Credits.h"


Credits::Credits(){



               font.loadFromFile("Fuente.ttf");

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(550,500);


               creditsText.setFont(font);
               creditsText.setString("Guada Juricich - Alejanddro Morales");
               creditsText.setCharacterSize(30);
               creditsText.setFillColor(Color::White);
               creditsText.setPosition(30, 250 );

               titleText.setFont(font);
               titleText.setString("Created by:");
               titleText.setCharacterSize(50);
               titleText.setFillColor(Color::Cyan);
               titleText.setPosition(230, 100);
}







int Credits::getStateWindow(){return _stateWindow;}



void Credits::draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(titleText);
            target.draw(creditsText);
            target.draw(quitOptionText);
}


void Credits::update(sf::RenderWindow& window) {

          sf::Vector2i mousePos = sf::Mouse::getPosition(window);
          _option = -1;
          _stateWindow=-1;


            if (quitOptionText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                _option = 0;
               quitOptionText.setFillColor(sf::Color::Red);
            } else {
               quitOptionText.setFillColor(sf::Color::White);
            }


           if (_option == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

           _stateWindow=5;
        }

    }

