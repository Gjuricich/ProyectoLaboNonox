#include <SFML/Graphics.hpp>
#include "Nonograma.h"
#include "Timer.h"
#include "Matrix.h"
#include "ArchiveMatrix.h"
#include "level.h"



int main()


{
 ArchiveMatrix lol;
/*
 Matrix Matrix1(6,6);
 Matrix1.loadReferencias(6,6);
 Matrix1.loadMatrix(6,6);
 lol.SaveArchive(Matrix1);
 std::cout<<lol.getNumberReg()<<std::endl;
 std::cout<<std::endl;

 Matrix Matrix2(11,11);
 Matrix2.loadReferencias(11,11);
 Matrix2.loadMatrix(11,11);
 lol.SaveArchive(Matrix2);
 std::cout<<lol.getNumberReg()<<std::endl;
 std::cout<<std::endl;

 Matrix Matrix3(16,16);
 Matrix3.loadReferencias(16,16);
 Matrix3.loadMatrix(16,16);
 lol.SaveArchive(Matrix3);*/
 std::cout<<lol.getNumberReg()<<std::endl;
 Matrix Matrix=lol.readArchive(2,11,11);
 Matrix.showMatrix(11,11);
 std::cout<<std::endl;



    sf::RenderWindow ventana(sf::VideoMode(900, 600), "SFML window");
    ventana.setFramerateLimit(90);
    Timer Timer(ventana.getSize(),3, 30);
    Level level(ventana.getSize(),1);
    //Matrix auz=level.get_level();
    //auz.showMatrix(6,6);


    while (level.getLost()==false&&level.getWon()==false) {


        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }

        }


     if (level.getLost()==false&&level.getWon()==false) {
            Timer.actualizar(); // Actualizar el temporizador

            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se acabe el tiempo
                // por ejemplo, terminar el juego o reiniciar el level.
                Timer.reiniciar(); // Reiniciar el temporizador para la próxima partida
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;

                // Aquí puedes realizar las acciones correspondientes cuando se complete el level correctamente
                // y obtener el tiempo transcurrido para usarlo en el puntaje final.

            }
        }


        // Clear screen
        ventana.clear();


        Timer.dibujar(ventana); // Dibujar el temporizador en la ventana
        level.updateMatrix(ventana);



        ventana.display();
        ///std::cout<<level.getVidas();


        if (level.getLost()==true||level.getWon()==true) {
            // El level se ha ganado antes de tiempo, detener el reloj y show el tiempo restante
           Timer.parar(); // Detener el temporizador



            ///std::cout << "¡level ganado antes de tiempo! Tiempo restante: " << (Timer.getTiempoRestante()/ 60)<< " minutos " << (Timer.getTiempoRestante()%60) << " segundos" << std::endl;

            // Aquí puedes realizar las acciones adicionales cuando se gana antes de tiempo
            // por ejemplo, otorgar puntos extra, show una animación, etc.

            sf::sleep(sf::seconds(1)); // Pausa de 1 segundo antes de continuar el bucle
        }
        if (level.getWon()==true){
          std::cout<<"Ganaste!!!!";
        }
        if (level.getLost()==true){
          std::cout<<"Perdiste :( !!!!";
        }

    }

    level.updatelevel(ventana.getSize(),2);
    level.setWon(false);
    level.setLost(false);
    Timer.reiniciar();

while (level.getLost()==false&&level.getWon()==false) {


        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }

        }


     if (level.getLost()==false&&level.getWon()==false) {
            Timer.actualizar(); // Actualizar el temporizador

            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se acabe el tiempo
                // por ejemplo, terminar el juego o reiniciar el level.
                Timer.reiniciar(); // Reiniciar el temporizador para la próxima partida
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;

                // Aquí puedes realizar las acciones correspondientes cuando se complete el level correctamente
                // y obtener el tiempo transcurrido para usarlo en el puntaje final.

            }
        }


        // Clear screen
        ventana.clear();


        Timer.dibujar(ventana); // Dibujar el temporizador en la ventana
        level.updateMatrix(ventana);



        ventana.display();
        ///std::cout<<level.getVidas();


        if (level.getLost()==true||level.getWon()==true) {
            // El level se ha ganado antes de tiempo, detener el reloj y show el tiempo restante
           Timer.parar(); // Detener el temporizador



            ///std::cout << "¡level ganado antes de tiempo! Tiempo restante: " << (Timer.getTiempoRestante()/ 60)<< " minutos " << (Timer.getTiempoRestante()%60) << " segundos" << std::endl;

            // Aquí puedes realizar las acciones adicionales cuando se gana antes de tiempo
            // por ejemplo, otorgar puntos extra, show una animación, etc.

            sf::sleep(sf::seconds(1)); // Pausa de 1 segundo antes de continuar el bucle
        }
        if (level.getWon()==true){
          std::cout<<"Ganaste!!!!";
        }
        if (level.getLost()==true){
          std::cout<<"Perdiste :( !!!!";
        }

    }

level.updatelevel(ventana.getSize(),3);
level.setWon(false);
level.setLost(false);

while (level.getLost()==false&&level.getWon()==false) {


        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }

        }


     if (level.getLost()==false&&level.getWon()==false) {
            Timer.actualizar();
            // Actualizar el temporizador

            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se acabe el tiempo
                // por ejemplo, terminar el juego o reiniciar el level.
                Timer.reiniciar(); // Reiniciar el temporizador para la próxima partida
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;
                // Aquí puedes realizar las acciones correspondientes cuando se complete el level correctamente
                // y obtener el tiempo transcurrido para usarlo en el puntaje final.

            }
        }


        // Clear screen
        ventana.clear();


        Timer.dibujar(ventana); // Dibujar el temporizador en la ventana
        level.updateMatrix(ventana);



        ventana.display();
        ///std::cout<<level.getVidas();


        if (level.getLost()==true||level.getWon()==true) {
            // El level se ha ganado antes de tiempo, detener el reloj y show el tiempo restante
           Timer.parar(); // Detener el temporizador



            ///std::cout << "¡level ganado antes de tiempo! Tiempo restante: " << (Timer.getTiempoRestante()/ 60)<< " minutos " << (Timer.getTiempoRestante()%60) << " segundos" << std::endl;

            // Aquí puedes realizar las acciones adicionales cuando se gana antes de tiempo
            // por ejemplo, otorgar puntos extra, show una animación, etc.

            sf::sleep(sf::seconds(1)); // Pausa de 1 segundo antes de continuar el bucle
        }
        if (level.getWon()==true){
          std::cout<<"Ganaste!!!!";
        }
        if (level.getLost()==true){
          std::cout<<"Perdiste :( !!!!";
        }

    }
    return 0;


}
