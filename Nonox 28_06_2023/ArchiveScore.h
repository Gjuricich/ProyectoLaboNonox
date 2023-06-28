#pragma once
#include "Score.h"


class ArchiveScore{

private:

    char _name[30];


public:

    ArchiveScore();
    ArchiveScore(const char *name);
    int getCantRegistros();
    Score leerArchivo(int cantRegistros);
    bool guardarArchivo(Score aux);
    bool sobreEscribirScore(Score aux, int pos);
    void cleanArchive();

};
