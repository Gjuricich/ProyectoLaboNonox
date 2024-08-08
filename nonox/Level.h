#pragma once
#include <SFML/Graphics.hpp>
#include "ArchiveMatrix.h"
#include <iostream>
#include <string.h>




class Level: public sf::Drawable{

private:

     Matrix _level;
     short _lifes;
     int _stateWindow,_seconds, _minutes;
     int _sizeCell,_rows,_columns, _option;
     bool Won=false,Lost=false,_powerUpOn=false;
     sf::RectangleShape **RectangleCell;
     sf::Font font;
     sf::Text LevelText, powerUpText,quitOptionText,*referenceText;
     sf::Texture lifesTexture, backgroundTexture;
     sf::Sprite *lifesSprite,backgroundSprite;


public:


     Level();
    ~Level() {
        for (int i = 0; i < getRows(); ++i) {
            delete[] RectangleCell[i];
        }
        delete[] RectangleCell;
        delete[]referenceText;
        delete[]lifesSprite;
    }
    void loadParametersLevel(int level);
    void loadDraw(int level, sf::Vector2u ventanaSize);
    void loadLevel(int level,int rows, int columns);
    void loadDrawLifes(int level, sf::Vector2u ventanaSize);
    void loadDrawPowerUp(int level,sf::Vector2u ventanaSize);
    void loadLevelText(sf::Vector2u ventanaSize);
    void loadLevelBackground();
    void loadQuitBoton(sf::Vector2u ventanaSize);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void update(sf::RenderWindow& window);
    bool youWintheLevel();
    int mistakes();
    void powerUp();

    int getStateWindow(){return _stateWindow;}
    void setVidas(int vidas);
    void setlevelActual(int levelActual);
    int getLifes();
    int getRows();
    int getColumns();
    void setRows(int F);
    void setColumns(int C);
    void setWon(bool G);
    void setLost(bool P);
    bool getWon();
    bool getLost();
    bool getPowerUpOn(){return _powerUpOn;}
    void setPowerUpOn(bool aux){_powerUpOn=aux;}
    int getSeconds();
    void setSeconds(int s);
    int getMinutes();
    void setMinutes(int m);
    void showlevel(int level, int rows, int columns);

};
