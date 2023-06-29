#pragma once


class Cell{

private:

    bool _cross; //(1 - no contiene pixel pintado, 0 - el pixel esta pintado)
    bool _active; //(1- el usuario interactuó con la Cell, 0 - la Cell no fue cliqueada aun)
    int  _reference; //Valores constantes correspondientes a la primer columna y fila del nomograma
    int  _posicionUtilizada; //indica con un -1 si esa posicion no va a ser utilizada, se inicializa en cero las que si van a usarse

public:

    Cell();
    void setCross(bool cross);
    void setActive(bool active);
    void setReference(int referenc);

    bool getCross();
    bool getActive();
    int  getReference();

};


