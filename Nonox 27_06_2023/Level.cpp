#include "Level.h"


Level::Level(sf::Vector2u ventanaSize, int level){

    loadDraw(level,ventanaSize);

}

Level::Level(){


}

void Level::loadDrawLifes(int level, sf::Vector2u ventanaSize){
      lifesTexture.loadFromFile("Lifes.png");
      int xPosition=ventanaSize.y/2;
      int yPosition=ventanaSize.y*0.01f;
      for(int j=0;j<_lifes;j++){

      lifesSprite[j].setTexture(lifesTexture);


      lifesSprite[j].setPosition(xPosition, yPosition);
      xPosition+=50;
      }


}

void Level::loadDrawPowerUp(int level,sf::Vector2u ventanaSize){

      setWon(false);
      setLost(false);
      powerUpText.setFont(font);
      powerUpText.setString("50%");
      powerUpText.setCharacterSize(40);
      powerUpText.setFillColor(sf::Color::Cyan);
      loadDrawLifes(level,ventanaSize);
       float x=ventanaSize.x*0.7;
        float y=ventanaSize.y*0.7;
      powerUpText.setPosition(x,y);

}
void Level::loadLevelText(sf::Vector2u ventanaSize){

      LevelText.setFont(font);

      LevelText.setCharacterSize(50);
      powerUpText.setFillColor(sf::Color::Cyan);

       float x=(ventanaSize.x/2)-120;
       float y=ventanaSize.y*0.1;
      LevelText.setPosition(x,y);

}

 void Level::loadDraw(int level, sf::Vector2u ventanaSize){


      font.loadFromFile("fuente.ttf");
      loadParametersLevel(level);

               quitOptionText.setFont(font);
               quitOptionText.setString("Quit");
               quitOptionText.setCharacterSize(40);
               quitOptionText.setFillColor(sf::Color::White);
               quitOptionText.setPosition(550,500);

   //Calculo valores para cargar la configuracion de draw.

      int sizeReference=_columns+_rows-1;
      int anchoTotal = _columns * _sizeCell;
      int altoTotal =_rows * _sizeCell;
      int ventanaAncho = ventanaSize.x;
      int ventanaAlto = ventanaSize.y;
      float posXInicial = (ventanaAncho - anchoTotal) / 2.0f;
      float posYInicial = (ventanaAlto - altoTotal) / 2.0f;
      loadLevelText(ventanaSize);
      loadLevel(level,_rows,_columns);
      lifesSprite=new sf::Sprite [_lifes];
      referenceText=new sf::Text[sizeReference];
      RectangleCell=new sf::RectangleShape *[_rows];
        for (int i = 0; i < _rows; ++i) {
            RectangleCell[i] = new sf::RectangleShape[_columns];
        }
        loadDrawPowerUp(level,ventanaSize);
        loadDrawLifes(level,ventanaSize);




       for (int m = 0; m < _rows; m++) {

             for (int n = 0; n < _columns; n++) {

                RectangleCell[m][n].setSize(sf::Vector2f(_sizeCell,_sizeCell));
                if(!_level.getCell(m,n).getActive()){RectangleCell[m][n].setFillColor(sf::Color::White);}
                RectangleCell[m][n].setOutlineThickness(2.0f);
                RectangleCell[m][n].setOutlineColor(sf::Color::Black);
                RectangleCell[m][n].setPosition(posXInicial + (n * _sizeCell), posYInicial + (m * _sizeCell));

           }
        }
       int i=0;

       for (int w = 0; w < _rows; w++) {

        for (int z = 0; z < _columns; z++) {

             if(!(w==0 && z==0)){
                RectangleCell[w][z].setFillColor(sf::Color::Blue);
                if (w == 0 && z> 0) {


                referenceText[i].setFont(font);
                referenceText[i].setString(std::to_string(_level.getCell(w,z).getReference()));
                referenceText[i].setCharacterSize( _sizeCell/1.5f);
                referenceText[i].setFillColor(sf::Color::Black);
                referenceText[i].setPosition(RectangleCell[w][z].getPosition().x+(_sizeCell*0.2f),RectangleCell[w][z].getPosition().y+(_sizeCell*0.2f));
                i++;


                }


                else if(z == 0 && w > 0) {

                referenceText[i].setFont(font);
                referenceText[i].setString(std::to_string(_level.getCell(w,z).getReference()));
                referenceText[i].setCharacterSize(_sizeCell/1.5f);
                referenceText[i].setFillColor(sf::Color::Black);
                referenceText[i].setPosition(RectangleCell[w][z].getPosition().x+(_sizeCell*0.2f),RectangleCell[w][z].getPosition().y+(_sizeCell*0.2f));
                i++;
                }
        }
    }


}






 }

void Level::loadParametersLevel(int level){


     switch(level){
           case 1:
             _sizeCell=50;
             _rows=6;
             _columns=6;
             _seconds=30;
             _minutes=1;
             _lifes=3;
             LevelText.setString("Level 1");
             break;
           case 2:
             _sizeCell=40.5;
             _rows=11;
             _columns=11;
             _seconds=30;
             _minutes=2;
//             _minutes=((_time / 60) + 2);
//             _seconds=((_time % 60) + 30);
             _lifes++;
             LevelText.setString("Level 2");
                 break;
           case 3:
             _sizeCell=35;
             _rows=16;
             _columns=16;
             _seconds=30;
             _minutes=3;
             _lifes++;
             LevelText.setString("Level 3");
             break;
     }


}
void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const {


       target.draw(quitOptionText);
       target.draw(powerUpText);
       target.draw(LevelText);
       for(int j=0;j<_lifes;j++){

           target.draw(lifesSprite[j]);
       }




        // Dibujar el objeto Nivel en la ventana
        int i=0;
        for (int w = 0; w < _rows; w++) {

        for (int z = 0; z < _columns; z++) {
            target.draw(RectangleCell[w][z]);

            if(!(w==0 && z==0)){
                if (w == 0 && z> 0) {
                   target.draw(referenceText[i]);
                    i++;
                }
                else if(z == 0 && w > 0) {
                   target.draw(referenceText[i]);
                    i++;
                }
            }
        }
       }





}


bool Level::youWintheLevel(){
int cantCells=0;
  for(int j=0;j<_rows;j++){
    for(int k=0;k<_columns;k++){
        if(!_level.getCell(j,k).getCross()==true){
            cantCells++;
        }
    }
  }


int contDescubiertas=0;
  for(int x=0;x<_rows;x++){
    for(int y=0;y<_columns;y++){
       if (RectangleCell[x][y].getFillColor() == sf::Color::Black) {
            contDescubiertas++;
    }
  }

}
if (contDescubiertas==cantCells){
    return true;
}
else{
    return false;
}
}

int  Level::mistakes(){

    int totalRedRects=0;
  for(int x=0;x<_rows;x++){
    for(int y=0;y<_columns;y++){
       if (RectangleCell[x][y].getFillColor() == sf::Color::Red) {
            totalRedRects++;
            }
            }
        }
return totalRedRects;
}


 void Level::powerUp(){

     int cantCells=0;
     for(int i=0;i<_rows;i++){
        for(int j=0;j<_columns;j++){
           if(i != 0 && j != 0 && (RectangleCell[i][j].getFillColor() == sf::Color::Red || RectangleCell[i][j].getFillColor() == sf::Color::Black)){
            cantCells++;

           }
        }
     }
     switch(_rows){
     case 6:
         cantCells=cantCells+13;
        break;
     case 11:
         cantCells=cantCells+50;
        break;
     case 16:
         cantCells=cantCells+120;
        break;
     }



     for(int i=0;i<_rows;i++){
        for(int j=0;j<_columns;j++){
           if(!_level.getCell(i,j).getActive() && cantCells!=0  && i!= 0 && j!= 0 ){
            cantCells--;
            _level.getCell(i,j).setActive(true);
            if(_level.getCell(i,j).getCross()){
                    RectangleCell[i][j].setFillColor(sf::Color::Red);}
            else{
                    RectangleCell[i][j].setFillColor(sf::Color::Black);
            }

            }
           }
        }




 }


void Level::update(sf::RenderWindow& window) {

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        int _option=-1;
        _stateWindow=-1;
          if (quitOptionText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                _option = 0;
               quitOptionText.setFillColor(sf::Color::Red);
            } else {
               quitOptionText.setFillColor(sf::Color::White);
            }


           if (_option == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

           _stateWindow=5;
        }

        if (powerUpText.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
               powerUpText.setFillColor(sf::Color::Red);
               if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && getPowerUpOn()==false) {
                    powerUp();
                    setPowerUpOn(true);

               }

        }

        else {
               powerUpText.setFillColor(sf::Color::Cyan);
        }



        int previousNum=mistakes();

          for (int w = 0; w < _rows; w++) {

             for (int z = 0; z < _columns; z++) {

                if(w != 0 && z != 0){

                   if (RectangleCell[w][z].getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    /*
*/
                      if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !_level.getCell(w,z).getActive()){



                         if(_level.getCell(w,z).getCross()){


                            RectangleCell[w][z].setFillColor(sf::Color::Red);
                             _level.getCell(w,z).setActive(true);

                         }
                         else{

                            RectangleCell[w][z].setFillColor(sf::Color::Black);
                             _level.getCell(w,z).setActive(true);
                         }

                      }
                   }


                }
                //



                if (mistakes()==previousNum+1){
                        setVidas(getLifes()-1);
                        previousNum=mistakes()+1;
                }
                if (youWintheLevel()){
                setWon(true);
                }
                if (getLifes()==0){
                setLost(true);
                }
             }
          }






}

void Level::loadLevel(int level, int rows, int columns){

       ArchiveMatrix archMatrix;
      _level=archMatrix.readArchive(level-1,_rows,_columns);

}



void Level::setVidas(int vidas){

    _lifes=vidas;
}

void Level::setlevelActual(int currentLevel){

    _currentLevel=currentLevel;
}

int Level::getLifes(){

    return _lifes;
}
int Level::getCurrentLevel(){

    return _currentLevel;
}

int Level::getRows(){
 return _rows;
}
int Level::getColumns(){
 return _columns;
}
void Level::setRows(int F){
 _rows=F;
}
void Level::setColumns(int C){
_columns=C;
}
void Level::setWon(bool G){
Won=G;
}
void Level::setLost(bool P){
Lost=P;
}
bool Level::getWon(){
return Won;
}
bool Level::getLost(){
return Lost;
}
int Level::getSeconds(){
return _seconds;
}
void Level::setSeconds(int s){
_seconds=s;}
int Level::getMinutes(){
return _minutes;}
void Level::setMinutes(int m){
_minutes=m;}

int Level::getTime(){
return _time;}
void Level::setTime(int m){
_time=m;}


//Metodo para verificar que levante la Matrix correctamnete
void Level::showlevel(int level, int rows, int columns){

       _level.showMatrix(rows,columns);

}


