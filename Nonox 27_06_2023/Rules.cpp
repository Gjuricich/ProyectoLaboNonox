#include "Rules.h"


Rules::Rules(){



               font.loadFromFile("Fuente.ttf");
               string _rules="   Nonox es un juego de tipo rompecabezas, que consiste en\n"
                             "rellenar determinadas casillas de un tablero para descubrir una imagen. \n"
                             " A lo largo de la partida, el jugador podrá interactuar con distintos\n"
                             "Power ups. Los mismos se listan a continuación:\n\n"
                             "     - Aumento de tiempo: Se va a a poder ganar tiempo a lo largo de\n"
                             " la partida. Si el nivel se completa en una cierta cantidad de minutos,\n"
                             "el tiempo sobrante se va a sumar al reloj en el próximo nivel.\n\n"
                             "     -50%: Si el jugador decide utilizar este power up, se descubrirá el 50%\n"
                             " de las celdas del tablero en el nivel en curso.Sin embargo,\n\n"
                             "el uso de este beneficio impactará en el puntaje final y además sólo podrá\n"
                             "usarse una única vez.\n\n"
                             "El jugador deberá completar 3 niveles que presentarán tableros de distintos\n"
                             "tamaños. El tiempo para completar los niveles es limitado. Si el usuario no es\n"
                             "capaz de resolver los tableros en ese tiempo el juego habrá terminado.\n"
                             " En caso que pueda resolverlo y le quede tiempo restante será reflejado en\n"
                             " el puntaje final.Los controles de Nonox serán únicamente por mouse.\n"
                             "Para pintar una celda se deberá posicionar\n\n"
                             "el puntero sobre la casilla y utilizar el click izquierdo.\n"
                             " Mientras que, si quisiera descartar la misma se utiliza el click derecho.";

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(550,550);


               rulesText.setFont(font);
               rulesText.setString(_rules);
               rulesText.setCharacterSize(15);
               rulesText.setFillColor(Color::White);
               rulesText.setPosition(15, 150);

               titleText.setFont(font);
               titleText.setString("Rules");
               titleText.setCharacterSize(50);
               titleText.setFillColor(Color::Cyan);
               titleText.setPosition(290, 70);
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

