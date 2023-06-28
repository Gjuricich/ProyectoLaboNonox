#include "Credits.h"


Credits::Credits(){


}

void Credits::LoadDraw(sf::Vector2u ventanaSize){


               int xPosition=ventanaSize.x/2;
               int yPosition=ventanaSize.y/2;
               font.loadFromFile("Fuente.ttf");

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(xPosition+(xPosition*0.6f),yPosition+(yPosition*0.6f));

               backgroundTexture.loadFromFile("Fondo.png");
               backgroundSprite.setTexture(backgroundTexture);
               backgroundSprite.setPosition(110,0);
               backgroundSprite.setScale(0.4f, 0.4f);


               creditsText.setFont(font);
               creditsText.setString("Guada Juricich - Alejanddro Morales");
               creditsText.setCharacterSize(30);
               creditsText.setFillColor(Color::White);
               creditsText.setPosition(xPosition-(xPosition*0.5f), yPosition );

               titleText.setFont(font);
               titleText.setString("Created by:");
               titleText.setCharacterSize(50);
               titleText.setFillColor(Color::Cyan);
               titleText.setPosition(xPosition-(xPosition*0.25f), 250);
}







int Credits::getStateWindow(){return _stateWindow;}



void Credits::draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(backgroundSprite);
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

