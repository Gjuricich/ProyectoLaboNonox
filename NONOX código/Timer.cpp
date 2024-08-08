#include <iostream>
#include "Timer.h"


//el constructor recibe los minutos y segundos iniciales del temporizador y los inicializa.
Timer::Timer(sf::Vector2u ventanaSize,int minutos, int segundos){
    _tiempoTotal = minutos * 60 + segundos;
    _tiempoRestante = _tiempoTotal;
    clock.restart();
    //LoadDraw
    font.loadFromFile("Fuente.ttf");
    timerText.setFont(font);
    timerText.setCharacterSize(25);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(ventanaSize.x/2-(timerText.getCharacterSize()*3),0+timerText.getCharacterSize());
}

void Timer::updateDrawTime(){
    int minutosRestantes = _tiempoRestante / 60;
    int segundosRestantes = _tiempoRestante % 60;
    timerText.setString("Time: " + std::to_string(minutosRestantes) + ":" + std::to_string(segundosRestantes));
}

//Actualiza el tiempo restante cada vez que se llama.

void Timer::update(){
    sf::Time elapsed = clock.getElapsedTime();
    int segundosTranscurridos = elapsed.asSeconds();
    _tiempoRestante = _tiempoTotal - segundosTranscurridos;
    updateDrawTime();
}

void Timer::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(timerText);
}

//Verifica si el tiempo llegó a cero. "<=" Compara el valor de _tiempoRestante con 0.
//Si tiempo Restante es menor o igual a 0, devuelve true. Si es mayor que 0 devuelve false.
bool Timer::tiempoTerminado() {
    return _tiempoRestante <= 0;
}


int Timer::getTiempoTotal(){
    return _tiempoTotal;
}

int Timer::getTiempoRestante(){
    return _tiempoRestante;
}


void Timer::setTiempoRestante(int segundos) {
    segundos = std::max(0, segundos);
    _tiempoRestante = segundos;
    _tiempoTotal = _tiempoRestante;
    clock.restart();
}
