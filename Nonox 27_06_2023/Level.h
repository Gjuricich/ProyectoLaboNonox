#pragma once
#include <SFML/Graphics.hpp>
#include "ArchiveMatrix.h"
#include <iostream>
#include <string.h>




class Level: public sf::Drawable{

private:

    Matrix _level;
    short _lifes;
    int _currentLevel,_stateWindow;
    int _sizeCell,_rows,_columns, _option;
    int _seconds, _minutes, _time;
    bool Won=false;
    bool Lost=false;
    bool _powerUpOn=false;
    sf::RectangleShape **RectangleCell;
    sf::Font font;
    sf::Text LevelText, powerUpText,quitOptionText;
    sf::Text *referenceText;
    sf::Texture lifesTexture;
    sf::Sprite *lifesSprite;

public:

    Level(sf::Vector2u ventanaSize, int level);
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
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update(sf::RenderWindow& window);

    void powerUp();
    int getStateWindow(){return _stateWindow;}
    void setVidas(int vidas);
    void setlevelActual(int levelActual);
    int getLifes();
    int getCurrentLevel();
    void setCurrentLevel(int l){_currentLevel=l;}
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
    int getTime();
    void setTime(int s);


    bool youWintheLevel();
    int mistakes();
    void showlevel(int level, int rows, int columns);
    void corregirCell();
    void loadLevelText(sf::Vector2u ventanaSize);

};
