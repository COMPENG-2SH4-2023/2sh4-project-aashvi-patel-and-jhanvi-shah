#include "objPosArrayList.h"


// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
// Paste your CUTE Tested implementation here.
objPosArrayList::objPosArrayList()
{
   aList = new objPos[ARRAY_MAX_CAP];
   sizeList = 0;
   sizeArray = ARRAY_MAX_CAP;
}


objPosArrayList::~objPosArrayList()
{
   delete[] aList;


}


int objPosArrayList::getSize()
{
   return sizeList;
}


void objPosArrayList::insertHead(objPos thisPos)
{
   if(sizeList == sizeArray)
   {
       return;
   }


   for(int i = sizeList; i > 0; i--)  
       aList[i] = aList[i - 1];  // shifting towards the tail


   aList[0] = thisPos;
   sizeList++;
}


void objPosArrayList::insertTail(objPos thisPos)
{
   if(sizeList == sizeArray)
   {
       return;
   }


   aList[sizeList++] = thisPos;
}


void objPosArrayList::removeHead()
{
   if(sizeList == 0)
   {
       return;
   }


   for(int i = 0; i < sizeList - 1; i++)  
       aList[i] = aList[i + 1];  // shifting towards the head


   sizeList--;
}


void objPosArrayList::removeTail()
{
   if(sizeList == 0)
   {
       return;
   }


   sizeList--;  // lazy delete
}


void objPosArrayList::getHeadElement(objPos &returnPos)
{
   if(sizeList == 0)
   {
       return;
   }
  
   returnPos = aList[0];
}


void objPosArrayList::getTailElement(objPos &returnPos)
{
   if(sizeList == 0)
   {
       return;
   }
  
   returnPos = aList[sizeList - 1];
}


void objPosArrayList::getElement(objPos &returnPos, int index)
{
   if(sizeList == 0 || index < 0 || index >= sizeList)
   {
       return;
   }


   returnPos = aList[index];
}