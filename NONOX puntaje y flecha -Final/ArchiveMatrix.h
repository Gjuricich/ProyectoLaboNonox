#pragma once
#include "Matrix.h"



class ArchiveMatrix{

private:

    char _name[30];


public:

    ArchiveMatrix();
    ArchiveMatrix(const char *name);
    int getNumberReg();
    Matrix readArchive(int NumberReg, int rows, int columns);
    bool overwriteArchive(int NumberReg, int rows, int columns);
    bool SaveArchive(Matrix aux);

};




