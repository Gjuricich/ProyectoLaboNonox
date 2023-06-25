#include "ManagerNonox.h"



ManagerNonox::ManagerNonox() {
       window.create(sf::VideoMode(800, 600), "Nonox");
       window.setFramerateLimit(60);
       _stateWindow = 5;
}


void ManagerNonox::setStateWindow(int s){_stateWindow=s;}
int ManagerNonox::getStateWindow(){return _stateWindow;}

void ManagerNonox::run(sf::RenderWindow &window,Level &level){

    Timer Timer(window.getSize(),3, 30);
//    bool quit=false;
    while (window.isOpen()&& !(level.getWon() && level.getCurrentLevel()==3) && (!level.getWon() && !level.getLost()) && level.getStateWindow()!=5)
    {
        sf::Event evento;
        while (window.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                window.close();
        }
         if (level.getLost()==false&&level.getWon()==false) {
            Timer.actualizar();
            if (Timer.tiempoTerminado()) {
                std::cout << "�Tiempo terminado!" << std::endl;

                Timer.reiniciar();
            }
            if (Timer.segundosTranscurridos() >= 60) {
                int minutos = Timer.segundosTranscurridos() / 60;
                int segundos = Timer.segundosTranscurridos() % 60;
                std::cout << "Ganaste Tiempo: " << minutos << " minutos " << segundos << " segundos" << std::endl;
            }
        }
        window.clear(sf::Color::Black);

        // Dibujar el objeto Nivel en la window
        Timer.dibujar(window);
        window.draw(level);
         sf::sleep(sf::milliseconds(70));
        level.update(window);
//        if(level.getStateWindow()==5){
//         quit=true;
//      }
        window.display();
    }
 sf::sleep(sf::milliseconds(2000));
}

bool ManagerNonox::newGame(sf::RenderWindow &ventana){
        Level level;
        level.setCurrentLevel(1);
        bool inGame=true;

          while(inGame){
switch(level.getCurrentLevel()){
case 1:{

    level.updatelevel(ventana.getSize(),1);
    run(ventana,level);
    if (level.getWon()){
      level.setCurrentLevel(2);

    }else{
       //score
       inGame=false;
    }
    break;
}
case 2:{
    level.updatelevel(ventana.getSize(),2);
    run(ventana,level);
    if (level.getWon()){
      level.setCurrentLevel(3);

    }
    if (level.getLost()){
        //score
       inGame=false;
    }}
    break;
case 3:
    level.updatelevel(ventana.getSize(),3);
    run(ventana,level);
    if (level.getWon()){
            //score
        return true;

    }
    if (level.getLost()){
          //score
       inGame=false;
    }
    break;}

    if(_stateWindow==5){
        inGame=false;
    }


}
return false;
}



 void ManagerNonox::update(sf::RenderWindow& window) {

      switch(_stateWindow){

case 0:

    if(!newGame(window)){
        _stateWindow=5;
    }

     break;

case 1:

       window.draw(_score);
      _score.update(window);
      if(_score.getStateWindow()==5){
         _stateWindow=5;
      }
     break;

case 2:


     break;

case 3:

    break;

case 4:
     window.close();
     break;

case 5:
      window.draw(_menu);
      _menu.update(window);
      if(_menu.getStateWindow()>-1){
         _stateWindow=_menu.getStateWindow();
      }
      break;

    }
  }
