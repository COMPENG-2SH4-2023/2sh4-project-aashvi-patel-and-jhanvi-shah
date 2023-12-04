#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"





using namespace std;


#define DELAY_CONST 100000
int boardSizeX;
int boardSizeY;






void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


GameMechs* gameMechPtr;
objPos playerPos;
//GameMechs game;
Player* player;
int main(void)
{


   Initialize();


   while(!gameMechPtr ->getExitFlagStatus()) 
   {
       GetInput();
       RunLogic();
       DrawScreen();
       LoopDelay();
   }


   CleanUp();


}




void Initialize(void)
{
   MacUILib_init();
   MacUILib_clearScreen();


   boardSizeX = 30;
   boardSizeY = 15;
   gameMechPtr = new GameMechs(30, 15);
   player = new Player(gameMechPtr);
  


}


void GetInput(void)
{
  char input = MacUILib_getChar();
  gameMechPtr -> setInput(input);
}




void RunLogic(void)
{
   player -> updatePlayerDir();
   player -> movePlayer();
   // while(gameMechPtr -> getExitFlagStatus() != true){
   //     gameMechPtr -> generateFood(playerPos);
   // }


   //new start
   objPos foodPos;
   gameMechPtr->getFoodPos(foodPos);
   if (playerPos.x == foodPos.x && playerPos.y == foodPos.y)
   {
       gameMechPtr->generateFood(playerPos);
       MacUILib_printf("%c", foodPos.symbol);
       gameMechPtr->incrementScore();
       MacUILib_clearScreen();


   }//end
}


void DrawScreen(void)
{
   player->getPlayerPos(playerPos);
   objPos foodPos;
   gameMechPtr->getFoodPos(foodPos);
   //player -> getPlayerPos(playerPos);
   int x, y;


   MacUILib_clearScreen();  
   for(y = 1; y <= boardSizeY; y++){
       for(x = 1; x <= boardSizeX; x++){
           if(x == 1 || y == 1 || x == boardSizeX || y == boardSizeY){
               MacUILib_printf("+");
           }
           else{
               MacUILib_printf(" ");
           }
           if (x == playerPos.x && y == playerPos.y){
               MacUILib_printf("%c", playerPos.symbol);
               x+=1;
           }
           if (x == foodPos.x && y == foodPos.y){
               MacUILib_printf("%c", foodPos.symbol);
               x+=1;
           }
       }
       MacUILib_printf("\n");
   }
   MacUILib_printf("Score: %d\n", gameMechPtr->getScore());//new
   MacUILib_printf("Press W to move up, D to move right, S to go down, or A to go left. Press the space bar to shut program down!\n");
    // if (gameMechPtr->getLoseFlagStatus())
    // {
    //     MacUILib_printf("\nGame Over!\n");
    //     MacUILib_Delay(35000000);    //to allow player to see message
    //     gameMechPtr->setExitTrue();
    // }
}


void LoopDelay(void)
{
   MacUILib_Delay(DELAY_CONST); // 0.1s delay
}




void CleanUp(void)
{
   MacUILib_clearScreen();   
    MacUILib_uninit();
   delete gameMechPtr;
   delete player;
}
