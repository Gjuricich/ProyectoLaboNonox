#include "AuxiliarScreens.h"


AuxiliarScreens::AuxiliarScreens(){


}


void AuxiliarScreens::LoadDraw(sf::Vector2u ventanaSize){


               int xPosition=ventanaSize.x/2;
               int yPosition=ventanaSize.y/2;
               font.loadFromFile("Fuente.ttf");

               string aux="Enter your name\n"
                          "in the console";
               askNameText.setFont(font);
               askNameText.setString(aux);
               askNameText.setCharacterSize(60);
               askNameText.setFillColor(Color::Cyan);
               askNameText.setPosition(xPosition-(xPosition*0.5f), 250);


}

int AuxiliarScreens::getStateWindow(){return _stateWindow;}

void AuxiliarScreens::draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(askNameText);

}

