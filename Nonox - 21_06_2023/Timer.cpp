#include <iostream>
#include "Timer.h"


//el constructor recibe los minutos y segundos iniciales del temporizador y los inicializa.
Timer::Timer(sf::Vector2u ventanaSize,int minutos, int segundos){
    _tiempoTotal = minutos * 60 + segundos;
    _tiempoRestante = _tiempoTotal;
    clock.restart();
    font.loadFromFile("Fuente.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setPosition(ventanaSize.x/2-(text.getCharacterSize()*3),0+text.getCharacterSize());
    actualizarTiempo();
}

void Timer::actualizarTiempo() {
    int minutosRestantes = _tiempoRestante / 60;
    int segundosRestantes = _tiempoRestante % 60;
    text.setString("Time: " + std::to_string(minutosRestantes) + ":" + std::to_string(segundosRestantes));
}

//Actualiza el tiempo restante cada vez que se llama.

void Timer::actualizar() {
    sf::Time elapsed = clock.getElapsedTime();
    int segundosTranscurridos = elapsed.asSeconds();
    _tiempoRestante = _tiempoTotal - segundosTranscurridos;
    actualizarTiempo();
}

void Timer::parar() {
    _estaCorriendo = false;
}

//Dibuja el temporizador en una ventana
void Timer::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(text);
}

//Verifica si el tiempo llegó a cero. "<=" Compara el valor de _tiempoRestante con 0.
//Si tiempo Restante es menor o igual a 0, devuelve true. Si es mayor que 0 devuelve false.
bool Timer::tiempoTerminado() {
    return _tiempoRestante <= 0;
}

//Devuelve la cantidad de segundos transcurridos desde el inicio del temporizador.
int Timer::segundosTranscurridos() {
    return _tiempoTotal - _tiempoRestante;
}

void Timer::agregarTiempo(int minutos, int segundos) {
    _tiempoTotal += minutos * 60 + segundos;
}

//Reinicia el temporizador al tiempo inicial.
void Timer::reiniciar() {
    clock.restart();
    _tiempoRestante = _tiempoTotal;
    actualizarTiempo();
}



int Timer::getTiempoTotal(){
    return _tiempoTotal;
}

int Timer::getTiempoRestante(){
    return _tiempoRestante;
}

void Timer::tiempoTotal(int minutos, int segundos) {
    minutos= std::max(0, minutos);
    segundos = std::max(0, segundos);
    _tiempoTotal = minutos * 60 + segundos;
    _tiempoRestante = _tiempoTotal;
}

void Timer::setTiempoRestante(int segundos) {
    segundos = std::max(0, segundos);
    _tiempoRestante = segundos;
    _tiempoTotal = _tiempoRestante;
    clock.restart();
}
