#pragma once
#include "Nonograma.h"
#include "GameManager.h"

class GameLoop {
private:
///GameLoop gameLoop;
     Level level1;
     Level level2;
     Level level3;
     bool TheEnd=false;

public:

 GameManager(){
    level1(ventana,3,6,6,60,60);
    level2(ventana,3,9,9,40,40);
    level3(ventana,3,12,12,20,20);
    }
    void ()



};
