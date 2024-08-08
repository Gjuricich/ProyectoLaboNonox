#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Timer{

private:

    int  _tiempoTotal;
    int  _tiempoRestante;
    sf::Clock clock;
    sf::Font  font;
    sf::Text  timerText;


public:

    Timer(sf::Vector2u ventanaSize,int minutos, int segundos);

    void update();
    void updateDrawTime();
    void dibujar(sf::RenderWindow& window);
    bool tiempoTerminado();

    void setTiempoTotal();
    void setTiempoRestante(int segundos);
    int  getTiempoRestante();
    int  getTiempoTotal();


};
