#include <iostream>
using namespace std;
#include "cstring"
#include "ArchiveScore.h"





ArchiveScore::ArchiveScore(){

  strcpy(_name,"Score.dat");

}

ArchiveScore::ArchiveScore(const char *name){

    strcpy(_name,name);

}

int ArchiveScore::getCantRegistros(){

    FILE *p;
    p=fopen(_name,"rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Score);
}

Score ArchiveScore::leerArchivo(int cantRegistros){

    FILE *p;
    Score aux;
    p=fopen(_name,"rb");
    if(p==NULL){return aux;}
    fseek(p, cantRegistros * sizeof(Score),0);
    fread(&aux,sizeof(Score),1,p);
    fclose(p);
    return aux;
}

bool ArchiveScore::guardarArchivo(Score aux){

    FILE *p;
    p=fopen(_name,"ab");
    if(p==NULL){return 0;}
    bool escribio=fwrite(&aux,sizeof(aux),1,p);
    fclose(p);
    return escribio;
}

bool ArchiveScore::sobreEscribirScore(Score aux, int pos){

    FILE *p;
    p=fopen(_name,"rb+");
    if(p==NULL){return 0;}
    fseek(p, pos * sizeof(Score),0);
    bool escribio=fwrite(&aux,sizeof(aux),1,p);
    fclose(p);
    return escribio;
}

void ArchiveScore::cleanArchive(){


        ArchiveScore _archivoScore;
        Score score;
        score.setName("None");
        score.setScore(0);
        for(int i=0;i<10;i++){
         _archivoScore.sobreEscribirScore(score,i);
        }

}


