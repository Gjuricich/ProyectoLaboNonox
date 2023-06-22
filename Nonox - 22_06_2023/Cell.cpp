#include "Cell.h"


Cell::Cell(){

 _active=false;
 _cross=true;
 _reference=false;

}

void Cell::setCross(bool cross){
      _cross=cross;
}
void Cell::setActive(bool active){

      _active=active;
}

void Cell::setReference(int referenc){

    _reference=referenc;
}

bool Cell::getCross(){
     return _cross;
}

bool Cell::getActive(){

     return _active;

}
int  Cell::getReference(){
    return _reference;
}
