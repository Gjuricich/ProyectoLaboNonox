using namespace std;
#include "Matrix.h"


Matrix::Matrix(){

}
//Constructor de Matrix, crea una Matrix de las rows y columns que se le pasa.
//Luego setea en inactivas todas las Cells, ademas de las referencias en cero, y "vacia"=vacia

    Matrix::Matrix(int rows, int columns){

     for(int i=0;i<rows;i++){

        for(int j=0;j<columns;j++){

        _m[i][j].setActive(0);
        _m[i][j].setReference(0);
        _m[i][j].setCross(0);

        }
    }


    }


// ----------------------------- Funciones para acceder a Cell desde level ----------------------------------

Cell Matrix::getCell(int fila, int columna){

      return _m[fila][columna];

}
//Asigna solamente los valores de las referencias por Cell.

void Matrix::assignReferencia(int fila, int columna, int referencia){

    _m[fila][columna].setReference(referencia);

}

//carga solamente los valores de las referencias de la Matrix.

void  Matrix::loadReferencias(int rows, int columns){
    int referencia;
    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < columns; j++) {

          if(!(i==0 && j==0)){

            if (i == 0 || j == 0) {

                cout<<"assign referencia: "<<endl;
                cin>>referencia;
                assignReferencia(i,j,referencia);
            }
        }
    }


}
}

//Asigna los estados de "vacia", 1-vacia, 0-llena por Cell

void Matrix::assignCell(int fila, int columna, bool vacia){

    _m[fila][columna].setCross(vacia);


}

//carga los estados de "vacia" a la Matrix.

void Matrix::loadMatrix(int rows, int columns){

    bool vacia;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

               if (i != 0 && j != 0){

             cout<<"assign condicion de pintada o no a la Cell, 0-pintada, 1-vacia)"<<endl;
             cin>>vacia;
             assignCell(i,j,vacia);
             }
           }

    }
}

//Muestra la Matrix cargada con las referencias y los estados de vacia

void Matrix::showMatrix(int rows, int columns) {
    int cont=0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
cout<<"Cell : "<<cont<<endl;
cont++;
cout<<"Esta Vacia? : "<<_m[i][j].getCross()<<endl;
cout<<"Es referencia? : "<<_m[i][j].getReference()<<endl;

    }

}
}


