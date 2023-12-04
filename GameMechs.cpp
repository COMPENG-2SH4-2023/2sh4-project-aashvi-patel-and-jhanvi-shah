#include "GameMechs.h"
#include "MacUILib.h"
#include "stdlib.h"
#include "time.h"
#include "objPosArrayList.h"




GameMechs::GameMechs()
{
   boardSizeY = 15;
   boardSizeX = 30;
   exitFlag = false;
   loseFlag = false;
   score = 0;
   input = 0;
   //generateFood();
}


GameMechs::GameMechs(int boardX, int boardY)
{
   boardSizeY = boardY;
   boardSizeX = boardX;
   exitFlag = false;
   loseFlag = false;
   score = 0;
   input = 0;
   //generateFood();
}


// do you need a destructor?






bool GameMechs::getExitFlagStatus()
{
   return exitFlag;
}


char GameMechs::getInput()
{
   if(MacUILib_hasChar()){ // accessing the input if input is given
       input = MacUILib_getChar();
   }
   return input;
}


int GameMechs::getBoardSizeX()
{
   return boardSizeX;
}


int GameMechs::getBoardSizeY()
{
   return boardSizeY;
}


void GameMechs::setExitTrue()
{
   exitFlag = true;
}


void GameMechs::setInput(char this_input)
{
   input = this_input;
}


void GameMechs::clearInput()
{
   input = '\0';
}


bool GameMechs::getLoseFlagStatus()
{
   return loseFlag;
}
void GameMechs::setLoseFlag()
{
   loseFlag = true;
}


int GameMechs::getScore(){
   return score-1;
}


void GameMechs::incrementScore(){
   score++;
}


void GameMechs::generateFood(objPos blockOff) {
  // Implement the random food generation algorithm (copy from PPA3)
   // Ensure that the generated food position is not equal to the player's position (blockOff)
  srand(time(NULL));


   int xCand, yCand;
   char potSymbol;
   do {
       xCand = (rand() % (boardSizeX - 2)) + 2;
       yCand = (rand() % (boardSizeY - 2)) + 2;
       potSymbol = '%';  // Assuming 'F' as the symbol for Snake Food
   } while (xCand == playerPos.x && yCand == playerPos.y);


   snakeFood.x = xCand;
   snakeFood.y = yCand;
   snakeFood.symbol = potSymbol;


}
void GameMechs::getFoodPos(objPos &returnPos) {
   returnPos = snakeFood; // Return the food position via pass by reference
}

