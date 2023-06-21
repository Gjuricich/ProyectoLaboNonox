#include "Level.h"
#include <iostream>
#include <string.h>



Level::Level(sf::Vector2u ventanaSize, int level){

    loadDraw(level,ventanaSize);

}

 void Level::loadDraw(int level, sf::Vector2u ventanaSize){

     loadParametersLevel(level);
   //Calculo valores para cargar la configuracion de draw.

      int sizeReference=_columns+_rows-1;
      int anchoTotal = _columns * _sizeCell;
      int altoTotal =_rows * _sizeCell;
      int ventanaAncho = ventanaSize.x;
      int ventanaAlto = ventanaSize.y;
      float posXInicial = (ventanaAncho - anchoTotal) / 2.0f;
      float posYInicial = (ventanaAlto - altoTotal) / 2.0f;

      loadLevel(level,_rows,_columns);

      referenceText=new sf::Text[sizeReference];
      RectangleCell=new sf::RectangleShape *[_rows];
        for (int i = 0; i < _rows; ++i) {
            RectangleCell[i] = new sf::RectangleShape[_columns];
        }

       font.loadFromFile("fuente.ttf");
       for (int m = 0; m < _rows; m++) {

             for (int n = 0; n < _columns; n++) {
                RectangleCell[m][n].setSize(sf::Vector2f(_sizeCell,_sizeCell));
                RectangleCell[m][n].setFillColor(sf::Color::Blue);
                RectangleCell[m][n].setOutlineThickness(2.0f);
                RectangleCell[m][n].setOutlineColor(sf::Color::Black);
                RectangleCell[m][n].setPosition(posXInicial + (n * _sizeCell), posYInicial + (m * _sizeCell));
                _level.activarCell(m,n);

           }
        }
       int contRefs=0;

       for (int w = 0; w < _rows; w++) {

        for (int z = 0; z < _columns; z++) {

             if(!(w==0 && z==0)){
                RectangleCell[w][z].setFillColor(sf::Color::Blue);
                if (w == 0 && z> 0) {


                referenceText[contRefs].setFont(font);
                referenceText[contRefs].setString(std::to_string(_level.getCell(w,z).getReference()));
                referenceText[contRefs].setCharacterSize( _sizeCell/1.5f);
                referenceText[contRefs].setFillColor(sf::Color::Black);
                referenceText[contRefs].setPosition(RectangleCell[w][z].getPosition().x+(_sizeCell*0.2f),RectangleCell[w][z].getPosition().y+(_sizeCell*0.2f));
                contRefs++;


                }


                else if(z == 0 && w > 0) {

                referenceText[contRefs].setFont(font);
                referenceText[contRefs].setString(std::to_string(_level.getCell(w,z).getReference()));
                referenceText[contRefs].setCharacterSize(_sizeCell/1.5f);
                referenceText[contRefs].setFillColor(sf::Color::Black);
                referenceText[contRefs].setPosition(RectangleCell[w][z].getPosition().x+(_sizeCell*0.2f),RectangleCell[w][z].getPosition().y+(_sizeCell*0.2f));
                contRefs++;
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
             _lifes=3;
             break;
           case 2:
             _sizeCell=40.5;
             _rows=11;
             _columns=11;
             _lifes=4;
                 break;
           case 3:
             _sizeCell=35;
             _rows=16;
             _columns=16;
             _lifes=5;
             break;
     }


}

void Level::loadLevel(int level, int rows, int columns){

       ArchiveMatrix archMatrix;
      _level=archMatrix.readArchive(level-1,_rows,_columns);

}

void Level::updatelevel(sf::Vector2u ventanaSize,int level){

     loadDraw(level,ventanaSize);

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
//load level debe pedir el level que desea load, ir al Archive y guardar el level.


//Metodo para verificar que levante la Matrix correctamnete
void Level::showlevel(int level, int rows, int columns){

       _level.showMatrix(rows,columns);

}
bool Level::siCliquea(sf::RenderWindow &Ventana,int sizeCell,sf::Text & Equis){


sf::Color cruz = sf::Color::Red;  // Color para Cells con cruces
sf::Color dibujo = sf::Color::Green; // Color para Cells con parte del dibujo
for (int x=0; x<_rows;x++){
        for (int i=0; i<_columns;i++){

                ///sf::Mouse::getPosition(Ventana).x
                bool colision =(RectangleCell[x][i].getPosition().x <=sf::Mouse::getPosition(Ventana).x
                                && RectangleCell[x][i].getPosition().x >=sf::Mouse::getPosition(Ventana).x -_sizeCell
                                && RectangleCell[x][i].getPosition().y <= sf::Mouse::getPosition(Ventana).y
                                && RectangleCell[x][i].getPosition().y >= sf::Mouse::getPosition(Ventana).y-_sizeCell);
                ///CLICK IZQUIERDO PARA ELEGIR DIBUJO



     if (colision){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
         if(_level.getCell(x,i).getReference()==0){
        _level.activarCell(x,i);


                /// ELEGIR DIBUJO Y ES DIBUJO
                     if (!_level.getCell(x,i).getCross()==true){
                        RectangleCell[x][i].setFillColor(dibujo);


                     }
          /// ELEGIR DIBUJO Y ES CRUZ
                      if (! _level.getCell(x,i).getCross()==false){
                         RectangleCell[x][i].setFillColor(cruz);

                        float X=RectangleCell[x][i].getPosition().x+(_sizeCell/2);
                        float Y=RectangleCell[x][i].getPosition().y;
                         Equis.setPosition(X,Y);




                           return true;
                         }



             }
           }
        }
        ///CLICK DERECHO PARA ELEGIR CRUZ

     }


}
return false;
}
bool Level::yowWintheLevel(){
int cantCells=(_rows*_columns)-1;
int contDescubiertas=0;
  for(int x=0;x<_rows;x++){
    for(int y=0;y<_columns;y++){
       if (RectangleCell[x][y].getFillColor() != sf::Color::Blue) {
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
void Level::updateMatrix(sf::RenderWindow &ventana){



int sizeReference=_columns+_rows-1;
sf::Font font;
font.loadFromFile("fuente.ttf");
sf::Text Equis;
std::string X="X";
 Equis.setFont(font);
                Equis.setString(X);
                Equis.setCharacterSize(_sizeCell);
                Equis.setFillColor(sf::Color::White);
    //Defino las constantes para la posicion en la ventana

    //Creamos objetos de la libreria sfml para la Cell, el color y la fuente de nuestras Cells.
    //No lo agregué como un metodo de Cell porque estaria bueno que lo que esté vinculado a
    //dibujar este acá, cosa que si nos piden un cambio es mas facil a la vista encontrar donde esta



    //Dibujamos las Cells
    for (int i = 0; i < _rows; i++) {

        for (int j = 0; j < _columns; j++) {


           // llamamos al objeto de rectángulo de SFML para assignle la posicion.
           //setiamos el borde el grosor y color del borde.
           //2.0f, se indica que el borde es de 1 píxel de grosor para cada cuadrado.

              ///int quitarVida=0;
             if (_level.getCell(i,j).getReference()==0&&(i!=0&&j!=0)){
             siCliquea( ventana,_sizeCell,Equis);
             ///setVidas(getLifes()-quitarVida);
             ///quitarVida=0;

             }



             if (getLifes()==0){
                setLost(true);

             }
             if (yowWintheLevel()==true){
                setWon(true);
             }


            //Fijamos el color de la Cell segun el estado de activa


            ventana.draw(RectangleCell[i][j]);
            for (int j=0;j<sizeReference;j++){

            ventana.draw(Equis);
            ventana.draw(referenceText[j]);
            }
            }
        }


    }






