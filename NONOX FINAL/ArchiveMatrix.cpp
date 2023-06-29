#include "cstring"
#include <stdio.h>
#include "ArchiveMatrix.h"


ArchiveMatrix::ArchiveMatrix(){

  strcpy(_name,"matrices.dat");

}

ArchiveMatrix::ArchiveMatrix(const char *name){

    strcpy(_name,name);

}

int ArchiveMatrix::getNumberReg(){

    FILE *p;
    p=fopen(_name,"rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Matrix);
}

Matrix ArchiveMatrix::readArchive(int NumberReg, int rows, int columns){

    FILE *p;
    Matrix aux(rows,columns);
    p=fopen(_name,"rb");
    if(p==NULL){return aux;}
    fseek(p, NumberReg * sizeof(Matrix),0);
    fread(&aux,sizeof(Matrix),1,p);
    fclose(p);
    return aux;
}

bool ArchiveMatrix::SaveArchive(Matrix aux){

    FILE *p;
    p=fopen(_name,"ab");
    if(p==NULL){return 0;}
    bool wrote=fwrite(&aux,sizeof(aux),1,p);
    fclose(p);
    return wrote;
}
bool ArchiveMatrix::overwriteArchive(int NumberReg, int rows, int columns){

    FILE *p;
    Matrix aux(rows,columns);
    p=fopen(_name,"rb+");
    if(p==NULL){return false;}
    fseek(p, NumberReg * sizeof(Matrix),NumberReg-1);
    bool wrote=fwrite(&aux,sizeof(aux),1,p);
    fclose(p);
    return wrote;
}




