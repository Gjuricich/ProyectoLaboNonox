#include "Ranking.h"


Ranking::Ranking(){

     loadDraw();
}


int Ranking::getStateWindow()
{return _stateWindow;}

void Ranking::loadDraw(){

               font.loadFromFile("Fuente.ttf");
               int yPosition=100;
               ArchiveScore archScore;
               Score score;

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(550,500);

           for (int i = 0; i < _size; ++i) {

               score=archScore.leerArchivo(i);
               string playerName(score.getName());
               if(score.getScore()>0){

               playerText[i].setFont(font);
               playerText[i].setString(playerName);
               playerText[i].setCharacterSize(40);
               playerText[i].setFillColor(Color::White);
               playerText[i].setPosition(240, yPosition);


               playerScoreText[i].setFont(font);
               playerScoreText[i].setString(to_string(score.getScore()));
               playerScoreText[i].setCharacterSize(40);
               playerScoreText[i].setFillColor(Color::White);
               playerScoreText[i].setPosition(450, yPosition);
               yPosition += 50;
               }
       }

      }


void Ranking::draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(quitOptionText);
        for(int i=0;i<_size;i++){
            target.draw(playerText[i]);
            target.draw(playerScoreText[i]);
         }


      }

void Ranking::update(sf::RenderWindow& window) {

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



