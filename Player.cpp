#include "Player.h"
#include "GameMechs.h"
#include "objPos.h"




Player::Player(GameMechs* thisGMRef)
{
   mainGameMechsRef = thisGMRef;
   myFSMMode = STOP;
   // int boardX = GameMechs -> getBoardSizeX();
   // int boardY = GameMechs -> getBoardSizeY();


   playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
   // Add the initial position to the playerPosList
   //playerPosList.insertHead(playerPos);
}




Player::~Player()
{
   // delete any heap members here
}


void Player::getPlayerPos(objPos &returnPos)
{
   // return the reference to the playerPos arrray list
   //returnPos =  playerPos;
   //playerPosList.getHeadElement(returnPos);
   returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
}


void Player::updatePlayerDir()
{
   char input = mainGameMechsRef -> getInput();
   // PPA3 input processing logic  
   if(input != '\0')  // if not null character
   {
       switch(input)
       {  
                             
           case ' ':  // exit
               mainGameMechsRef -> setExitTrue();
               break;
           case 'W':
           case 'w':
               if (myFSMMode != DOWN){
                   myFSMMode = UP;
               }
               break;
           case 'A':
           case 'a':
               if (myFSMMode != RIGHT){
                   myFSMMode = LEFT;
               }
               break;
           case 'S':
           case 's':
               if (myFSMMode != UP){
                   myFSMMode = DOWN;
               }
               break;
           case 'D':
           case 'd':
               if (myFSMMode != LEFT){
                   myFSMMode = RIGHT;
               }
              
               break;
           default:
               break;
       }
       input = '\0';
   } 
}


void Player::movePlayer()
{
   switch(myFSMMode)
   {  
       case UP:
           playerPos.y--;
           break;
       case LEFT:
           playerPos.x--;
           break;
       case DOWN:
           playerPos.y++;
           break;
       case RIGHT:
           playerPos.x++;
           break;
       default:
           break;
   }


   if(playerPos.x == 1){
       playerPos.x = 30-1;
   }
   else if(playerPos.x == 30-1){
       playerPos.x = 2;
   }
   else if(playerPos.y == 1){
       playerPos.y = 15-1;
   }
   else if(playerPos.y == 15){
       playerPos.y = 2;
   }
   
}
