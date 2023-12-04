#ifndef GAMEMECHS_H
#define GAMEMECHS_H


#include <cstdlib>
#include <time.h>


#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;




class GameMechs
{
   // Construct the remaining declaration from the project manual.


   // Only some sample members are included here


   // You will include more data members and member functions to complete your design.
   /*
   int* ptr;
   gameMechs* gameMechPtr= new gameMechs()
   */




   private:
       char input;
       bool exitFlag;
       int score;
       bool loseFlag;
      
       int boardSizeX;
       int boardSizeY;


       objPos foodPos;


   public:
       GameMechs();
       GameMechs(int boardX, int boardY);
      
       bool getExitFlagStatus();
       void setExitTrue();


       char getInput();
       void setInput(char this_input);
       void clearInput();


       int getBoardSizeX();
       int getBoardSizeY();
       bool getLoseFlagStatus();
       void setLoseFlag();
       int getScore();
       void incrementScore();


       void generateFood(objPos blockOff);
       void getFoodPos(objPos &returnPos);
       objPos playerPos;
       char getRandomFruitSymbol();
       objPos snakeFood;


};


#endif
