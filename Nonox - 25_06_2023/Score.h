#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>
using namespace std;
#include "cstring"




class Score: public Drawable{



 private:


     char _name[12];
     int  _score, _yPosition=250;
     int  _seconds,_option,_stateWindow;
     const int _size=10;

     Font font;

     Text quitOptionText;
     string quitText={"Quit"};

     Text playerText[10];//lo inicializo en el constructor? aca me ahorro un for
     string nameText[10]={"Ale","Guada"};

     Text playerScoreText[10];//lo inicializo en el constructor? aca me ahorro un for
     string scoreText[10]={"36273","8393"};



     virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {

            target.draw(quitOptionText);
        for(int i=0;i<_size;i++){
            target.draw(playerText[i]);
            target.draw(playerScoreText[i]);
         }


      }




 public:

      Score(){

        loadDraw();
      }

      Score(const char *name, int seconds){

            strcpy(_name,name);
            _seconds=seconds;


      }
      int getStateWindow(){return _stateWindow;}
      void loadDraw(){

              font.loadFromFile("Fuente.ttf");

               quitOptionText.setFont(font);
               quitOptionText.setString(quitText);
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(Color::White);
               quitOptionText.setPosition(550,500);

           for (int i = 0; i < _size; ++i) {

               playerText[i].setFont(font);
               playerText[i].setString(nameText[i]);
               playerText[i].setCharacterSize(40);
               playerText[i].setFillColor(Color::White);
               playerText[i].setPosition(240, _yPosition);


               playerScoreText[i].setFont(font);
               playerScoreText[i].setString(scoreText[i]);
               playerScoreText[i].setCharacterSize(40);
               playerScoreText[i].setFillColor(Color::White);
               playerScoreText[i].setPosition(450, _yPosition);
               _yPosition += 50;
        }

      }

      void update(sf::RenderWindow& window) {

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




      //Sets and gets
      void setName(const char *name){strcpy(_name,name);}
      void setScore(int score){_score=score;}
      void setSeconds(int seconds){_seconds=seconds;}
      const char *getName(){return _name;}
      int getScore(){return _score;}
      int getSeconds(){return _seconds;}


      //Funciones
      int scoreCalculation(int level, int lifes, bool powerUp){

          const int multiplier=100;
          int scoreAuxiliar;
          scoreAuxiliar = ((lifes*level*multiplier)+_seconds);
          if(powerUp){return scoreAuxiliar/2;}
          else{return scoreAuxiliar;}
      }






};
