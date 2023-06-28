#include "Rules.h"


Rules::Rules(){

}

void Rules::LoadDraw(sf::Vector2u ventanaSize) {



               font.loadFromFile("Fuente.ttf");
               string _rules="   Nonox es un juego de tipo rompecabezas, que consiste en\n"
                             "rellenar determinadas casillas de un tablero para descubrir una imagen. \n"
                             " A lo largo de la partida, el jugador podr� interactuar con distintos\n"
                             "Power ups. Los mismos se listan a continuaci�n:\n\n"
                             "     - Aumento de tiempo: Se va a a poder ganar tiempo a lo largo de\n"
                             " la partida. Si el nivel se completa en una cierta cantidad de minutos,\n"
                             "el tiempo sobrante se va a sumar al reloj en el pr�ximo nivel.\n\n"
                             "     -50%: Si el jugador decide utilizar este power up, se descubrir� el 50%\n"
                             " de las celdas del tablero en el nivel en curso.Sin embargo,\n\n"
                             "el uso de este beneficio impactar� en el puntaje final y adem�s s�lo podr�\n"
                             "usarse una �nica vez.\n\n"
                             "El jugador deber� completar 3 niveles que presentar�n tableros de distintos\n"
                             "tama�os. El tiempo para completar los niveles es limitado. Si el usuario no es\n"
                             "capaz de resolver los tableros en ese tiempo el juego habr� terminado.\n"
                             " En caso que pueda resolverlo y le quede tiempo restante ser� reflejado en\n"
                             " el puntaje final.Los controles de Nonox ser�n �nicamente por mouse.\n"
                             "Para pintar una celda se deber� posicionar\n\n"
                             "el puntero sobre la casilla y utilizar el click izquierdo.\n"
                             " Mientras que, si quisiera descartar la misma se utiliza el click derecho.";


               int xPosition=ventanaSize.x/2;
               int yPosition=ventanaSize.y/2;
               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(xPosition+(xPosition*0.6f),yPosition+(yPosition*0.6f));


               rulesText.setFont(font);
               rulesText.setString(_rules);
               rulesText.setCharacterSize(20);
               rulesText.setFillColor(Color::White);
               rulesText.setPosition(xPosition*0.3f, yPosition*0.3f);

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

