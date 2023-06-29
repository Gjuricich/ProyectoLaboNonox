#include "ManagerNonox.h"



ManagerNonox::ManagerNonox(){
       window.create(sf::VideoMode(1370, 770), "Nonox");
       window.setFramerateLimit(60);
       _stateWindow = 5;
       _menu.LoadDraw(window.getSize());
       _ranking.LoadDraw(window.getSize());
       _credits.LoadDraw(window.getSize());
       _rules.LoadDraw(window.getSize());
       _auxScreens.LoadDraw(window.getSize());

}

void ManagerNonox::setStateWindow(int s){_stateWindow=s;}
int ManagerNonox::getStateWindow(){return _stateWindow;}

void ManagerNonox::run(Level &level,int numberLevel){

    Timer Timer(window.getSize(),level.getMinutes(),level.getSeconds());

    while (window.isOpen() && (!level.getWon() && !level.getLost()) && level.getStateWindow()!=5)
    {
        sf::Event evento;
        while (window.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
                window.close();
        }
         if (level.getLost()==false&&level.getWon()==false){
            Timer.actualizar();
            if (Timer.tiempoTerminado()) {
                level.setLost(true);
            }

        }
        window.clear(sf::Color::Black);
        window.draw(level);
        Timer.dibujar(window);
        sf::sleep(sf::milliseconds(70));
        level.update(window);
        if(level.getLost() || level.getWon()){
        _score.setScore(_score.scoreCalculation(numberLevel,level.getLifes(),level.getPowerUpOn(),Timer.getTiempoRestante()));
        }
        window.display();
    }
 sf::sleep(sf::milliseconds(1500));
}

int ManagerNonox::isGreater(int s){

       Score auxScore;
       for(int i=0;i<_archivoScore.getCantRegistros();i++){

        auxScore=_archivoScore.leerArchivo(i);
        if(s>auxScore.getScore()){
            return i;
        }
       }

     return -1;

}

void ManagerNonox::saveScoreArchive(){

     if(_score.getScore()>0){
        int pos=isGreater(_score.getScore());
        Score vec[10];
        for(int i=0;i<10;i++){
            vec[i]=_archivoScore.leerArchivo(i);
        }
        Score obj;
        obj.setName(_score.getName());
        obj.setScore(_score.getScore());
        if(pos>=0 && pos<=9){
           _archivoScore.sobreEscribirScore(obj,pos);
          for(int i=pos;i<9;i++){
              _archivoScore.sobreEscribirScore(vec[i],i+1);
          }
        }
     }
}


bool ManagerNonox::newGame(){

       bool inGame=true;
       char nombre[12];
       cout<<"Ingrese nombre de jugador: "<<endl;
       cin>>nombre;
       _score.setName(nombre);
       int currentLevel=1;
       sf::sleep(sf::milliseconds(100));


          while(inGame){

switch(currentLevel){

case 1:{
    Level level1;
    level1.loadDraw(1,window.getSize());
    run(level1,1);
    if (level1.getWon()){
      currentLevel++;

    }else{
       if(level1.getLost()){
       saveScoreArchive();}
       inGame=false;
    }
}
    break;

case 2:{
    Level level2;
    level2.loadDraw(2,window.getSize());
    run(level2,2);
    if (level2.getWon()){
      currentLevel++;

    }else{
       if(level2.getLost()){
       saveScoreArchive();}
       inGame=false;
    }
}
    break;
case 3:{
    Level level3;
    level3.loadDraw(3,window.getSize());
    run(level3,3);
    if (level3.getWon()){
            saveScoreArchive();
            _stateWindow=5;
    }else{
        if(level3.getLost()){
       saveScoreArchive();}
       inGame=false;
    }
}
    break;}

    if(_stateWindow==5){
        inGame=false;
    }


}
return false;
}


 void ManagerNonox::update(){

      switch(_stateWindow){

case 6:

    if(!newGame()){
        _stateWindow=5;
    }
    break;

case 1:
       _ranking.LoadDrawUpdate(window.getSize());
       window.draw(_ranking);
      _ranking.update(window);
      if(_ranking.getStateWindow()==5){
         _stateWindow=5;
      }
     break;


case 2:

      window.draw(_credits);
      _credits.update(window);
      if(_credits.getStateWindow()==5){
         _stateWindow=5;
      }


     break;

case 3:

     window.draw(_rules);
      _rules.update(window);
      if(_rules.getStateWindow()==5){
         _stateWindow=5;
      }

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

case 0:

       window.draw(_auxScreens);
       sf::sleep(sf::milliseconds(150));
       _stateWindow=6;
       break;
      }

  }


  void ManagerNonox::cleanScore(){

    ArchiveScore _archivoScore;
    Score score;

    ///LIMPIO SCORE
    score.setName("None");
    score.setScore(0);

  for(int i=0;i<10;i++){

    _archivoScore.sobreEscribirScore(score,i);
  }

}
