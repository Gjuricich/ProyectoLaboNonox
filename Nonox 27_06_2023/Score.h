#pragma once
#include "cstring"




class Score
{
 private:


     char _name[12];
     int  _score;

 public:

      Score();

      void setName(const char *name);
      void setScore(int score);
      const char *getName();
      int getScore();

      int scoreCalculation(int level, int lifes, bool powerUp, int seconds);





};
