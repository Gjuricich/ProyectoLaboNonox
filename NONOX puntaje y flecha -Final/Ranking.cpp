#include "Ranking.h"


Ranking::Ranking(){


}

int Ranking::getStateWindow()
{return _stateWindow;}

void  Ranking::LoadDrawUpdate(sf::Vector2u ventanaSize){

      int xPosition=ventanaSize.x/2;
      int yPosition=ventanaSize.y/2;
      font.loadFromFile("Fuente.ttf");
      ArchiveScore archScore;
      Score score;
      for (int i = 0; i < _size; ++i) {

               score=archScore.leerArchivo(i);
               string playerName(score.getName());
               if(score.getScore()>0){

               playerText[i].setFont(font);
               playerText[i].setString(playerName);
               playerText[i].setCharacterSize(35);
               playerText[i].setFillColor(Color::White);
               playerText[i].setPosition(xPosition-(xPosition*0.5f), yPosition-300);

               playerScoreText[i].setFont(font);
               playerScoreText[i].setString(to_string(score.getScore()));
               playerScoreText[i].setCharacterSize(35);
               playerScoreText[i].setFillColor(Color::White);
               playerScoreText[i].setPosition(xPosition+(xPosition*0.3f), yPosition-300);
               yPosition += 50;
               }
       }
}





void  Ranking::LoadDraw(sf::Vector2u ventanaSize){

               int xPosition=ventanaSize.x/2;
               int yPosition=ventanaSize.y/2;

               font.loadFromFile("Fuente.ttf");
               ArchiveScore archScore;
               Score score;

               backgroundTexture.loadFromFile("Fondo.png");
               backgroundSprite.setTexture(backgroundTexture);
               backgroundSprite.setPosition(110,0);
               backgroundSprite.setScale(0.4f, 0.4f);

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(xPosition+(xPosition*0.6f),yPosition+(yPosition*0.6f));
               yPosition=80;

           for (int i = 0; i < _size; ++i) {

               score=archScore.leerArchivo(i);
               string playerName(score.getName());
               if(score.getScore()>0){

               playerText[i].setFont(font);
               playerText[i].setString(playerName);
               playerText[i].setCharacterSize(35);
               playerText[i].setFillColor(Color::White);
               playerText[i].setPosition(xPosition-(xPosition*0.5f), yPosition-300);

               playerScoreText[i].setFont(font);
               playerScoreText[i].setString(to_string(score.getScore()));
               playerScoreText[i].setCharacterSize(35);
               playerScoreText[i].setFillColor(Color::White);
               playerScoreText[i].setPosition(xPosition+(xPosition*0.3f), yPosition-300);
               yPosition += 50;
               }
           }
}


void Ranking::draw(sf::RenderTarget& target, sf::RenderStates states) const {

        target.draw(backgroundSprite);
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






