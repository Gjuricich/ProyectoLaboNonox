#pragma once
#include <SFML/Graphics.hpp>
#include "ArchiveMatrix.h"



class Level: public sf::Drawable{

private:

    Matrix _level;
    short _lifes;
    int _currentLevel;
    int _sizeCell;
    int _rows;
    int _columns;
    bool Won=false;
    bool Lost=false;
    sf::RectangleShape **RectangleCell;
    sf::Font font;
    sf::Text *referenceText;


public:

    Level(sf::Vector2u ventanaSize, int level);
    Level();
    ~Level() {
        for (int i = 0; i < getRows(); ++i) {
            delete[] RectangleCell[i];
        }
        delete[] RectangleCell;
        delete[]referenceText;
    }
     void loadParametersLevel(int level);
     void loadDraw(int level, sf::Vector2u ventanaSize);
     void loadLevel(int level,int rows, int columns);

       virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {

//            target.draw(quitOptionText);
//        for(int i=0;i<_size;i++){
//            target.draw(playerText[i]);
//            target.draw(playerScoreText[i]);
         }

    void setVidas(int vidas);
    void setlevelActual(int levelActual);
    int getLifes();
    int getCurrentLevel();
    int getRows();
    int getColumns();
    void setRows(int F);
    void setColumns(int C);
    void setWon(bool G);
    void setLost(bool P);
    bool getWon();
    bool getLost();

    bool yowWintheLevel();
    void showlevel(int level, int rows, int columns);
    void corregirCell();
    bool siCliquea( sf::RenderWindow &Ventana,int sizeCell,sf::Text& Equis);
    ///Hacer updateMatrix bool para saber cuando se completo el level(si Lost o si Won son igual a true)
    void updateMatrix(sf::RenderWindow &ventana);
    void updatelevel(sf::Vector2u ventanaSize,int level);
    Matrix get_level(){
     return _level;
    }





};
