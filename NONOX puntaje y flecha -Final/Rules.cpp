#include "Rules.h"


Rules::Rules(){

}

void Rules::LoadDraw(sf::Vector2u ventanaSize) {



                font.loadFromFile("Fuente.ttf");
                string _rules =  "Nonox is a puzzle game where you need to fill certain\n"
                                 "cells of the board to reveal an image. Throughout the\n"
                                 "game, you can interact with different power-ups. Here\n"
                                 "are some of them:\n\n"
                                 "   - Time Boost: You can earn extra time during the \n"
                                 "   game. If you complete a level within a certain number\n"
                                 "   of minutes, the remaining time will be added to the\n"
                                 "   clock in the next level.\n\n"
                                 "   - 50% Power-up: If you choose to use this power-up,\n"
                                 "   50% of the cells on the current level's board will\n"
                                 "   be revealed. However, using this benefit will impact\n"
                                 "   your final score, and you can only use it once per\n"
                                   "   level.\n\n"
                                 "The time to complete the levels is limited. If you are\n"
                                 "unable to solve the puzzles within that time, the game\n"
                                 "will end. If you can solve them and have remaining time,\n"
                                 "it will be reflected in your final score.\n";

//               string _rules = "Nonox es un juego de tipo rompecabezas, que\n"
//                               "consiste en rellenar determinadas casillas del\n"
//                               "tablero para descubrir una imagen. A lo largo de\n"
//                               "la partida, el jugador podrá interactuar con\n"
//                               "distintos Power ups. Estos se listan a continuación:\n\n"
//                               "  - Aumento de tiempo: Se podrá ganar tiempo a\n"
//                               "    lo largo de la partida. Si el nivel se\n"
//                               "    completa en una cierta cantidad de minutos,\n"
//                               "    el tiempo sobrante se sumará al reloj en\n"
//                               "    el próximo nivel.\n\n"
//                               "  - 50%: Si el jugador decide utilizar este\n"
//                               "    power up, se descubrirá el 50% de las celdas\n"
//                               "    del tablero en el nivel en curso. Sin embargo,\n"
//                               "    el uso de este beneficio impactará en el\n"
//                               "    puntaje final y solo podrá usarse una única\n"
//                               "    vez por nivel.\n\n"
//                               "El tiempo para completar los niveles es limitado.\n"
//                               "Si el usuario no es capaz de resolver los tableros\n"
//                               "en ese tiempo, el juego habrá terminado. En caso\n"
//                               "de que pueda resolverlo y le quede tiempo restante,\n"
//                               "será reflejado en el puntaje final.\n";



               int xPosition=ventanaSize.x/2;
               int yPosition=ventanaSize.y/2;
               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(xPosition+(xPosition*0.6f),yPosition+(yPosition*0.6f));


               rulesText.setFont(font);
               rulesText.setString(_rules);
               rulesText.setCharacterSize(23);
               rulesText.setFillColor(Color::White);
               rulesText.setPosition(xPosition*0.5f-70, yPosition*0.3f);

               titleText.setFont(font);
               titleText.setString("Rules");
               titleText.setCharacterSize(50);
               titleText.setFillColor(Color::Cyan);
               titleText.setPosition(xPosition-(xPosition*0.15f), yPosition*0.1f);
}








int Rules::getStateWindow(){return _stateWindow;}



void Rules::draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(titleText);
            target.draw(rulesText);
            target.draw(quitOptionText);
}


void Rules::update(sf::RenderWindow& window) {

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

