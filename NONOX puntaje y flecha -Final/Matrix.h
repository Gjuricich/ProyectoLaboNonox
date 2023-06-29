#pragma once
#include "Cell.h"
#include<iostream>
using namespace std;


class Matrix{

private:

    Cell _m[21][21];

public:

    Matrix();
    Matrix(int rows, int columns);
    Cell getCell(int fila, int columna);
    void assignReferencia(int rows, int columns, int referencia);
    void assignCell(int fila, int columna, bool vacia);
    void loadReferencias(int rows, int columns);
    void loadMatrix(int rows, int columns);
    void showMatrix(int rows, int columns);

};
