#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class Timer{

private:

    bool _estaCorriendo;
    int  _tiempoTotal;
    int  _tiempoRestante;
    sf::Clock clock;
    sf::Font  font;
    sf::Text  text;


public:

    Timer(sf::Vector2u ventanaSize,int minutos, int segundos);

    void actualizar();
    void actualizarTiempo();
    void dibujar(sf::RenderWindow& window);
    bool tiempoTerminado();
    int  tiempoTranscurrido();
    int  segundosTranscurridos();
    void agregarTiempo(int minutos, int segundos);
    void tiempoTotal(int minutos, int segundos);
    void parar();
    void reiniciar();

    void setTiempoTotal();
    void setTiempoRestante(int segundos);


    int  getTiempoRestante();
    int  getTiempoTotal();





};
