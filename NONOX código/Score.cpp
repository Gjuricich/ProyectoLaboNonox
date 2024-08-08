#include "Score.h"
#include "ArchiveScore.h"


Score::Score(){


}

void Score::setName(const char *name){strcpy(_name,name);}
void Score::setScore(int score){_score=score;}
const char *Score::getName(){return _name;}
int Score::getScore(){return _score;}

int Score::scoreCalculation(int level, int lifes, bool powerUp, int seconds){

          const int multiplier=100;
          int scoreAuxiliar;
          scoreAuxiliar = ((lifes*level*multiplier)+ seconds*multiplier);
          if(powerUp){return scoreAuxiliar/2;}
          else{return scoreAuxiliar;}
}



