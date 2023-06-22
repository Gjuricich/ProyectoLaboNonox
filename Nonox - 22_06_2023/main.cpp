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
// std::cout<<lol.getNumberReg()<<std::endl;
 //Matrix Matrix=lol.readArchive(2,11,11);
// Matrix.showMatrix(11,11);
// std::cout<<std::endl;



    sf::RenderWindow ventana(sf::VideoMode(900, 600), "SFML window");
    ventana.setFramerateLimit(90);
    Timer Timer(ventana.getSize(),3, 30);
    Level level(ventana.getSize(),1);



    while (level.getLost()==false&&level.getWon()==false) {


        sf::Event event;
        while (ventana.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana.close();
            }

        }


     if (level.getLost()==false&&level.getWon()==false) {
            Timer.actualizar();
            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo terminado!" << std::endl;

                Timer.reiniciar();
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "Ganaste Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;



            }
        }


        // Clear screen
        ventana.clear();


        Timer.dibujar(ventana);
        ventana.draw(level);
        level.update(ventana);
        //level.updateMatrix(ventana);



        ventana.display();
        ///std::cout<<level.getVidas();


        if (level.getLost()==true||level.getWon()==true) {

           Timer.parar();






            sf::sleep(sf::seconds(1));
        }
        if (level.getWon()==true){
          std::cout<<"Ganaste!!!!";
        }
        if (level.getLost()==true){
          std::cout<<"Perdiste :( !!!!";
        }

    }

    //level.updatelevel(ventana.getSize(),2);
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
            Timer.actualizar();

            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;

                Timer.reiniciar();
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;


            }
        }



        ventana.clear();


        Timer.dibujar(ventana);
        //level.updateMatrix(ventana);
        ventana.draw(level);
         level.update(ventana);



        ventana.display();
        ///std::cout<<level.getVidas();


        if (level.getLost()==true||level.getWon()==true) {

           Timer.parar();



            ///std::cout << "¡level ganado antes de tiempo! Tiempo restante: " << (Timer.getTiempoRestante()/ 60)<< " minutos " << (Timer.getTiempoRestante()%60) << " segundos" << std::endl;



            sf::sleep(sf::seconds(1));
        }
        if (level.getWon()==true){
          std::cout<<"Ganaste!!!!";
        }
        if (level.getLost()==true){
          std::cout<<"Perdiste :( !!!!";
        }

    }

//level.updatelevel(ventana.getSize(),3);
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

            if (Timer.tiempoTerminado()) {
                std::cout << "¡Tiempo agotado!" << std::endl;

                Timer.reiniciar();
            }

            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "¡Has ganado! Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;


            }
        }


        ventana.clear();


        Timer.dibujar(ventana);
        //level.updateMatrix(ventana);
        ventana.draw(level);
         level.update(ventana);



        ventana.display();



        if (level.getLost()==true||level.getWon()==true) {

           Timer.parar();



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
