/********************************************************
 * *Author:		Taylor Jones (jonest3)		*
 * *Date:		March 15, 2016			*
 * *Description:	Player.hpp 			*
 ********************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Creature.hpp"
#include "Compartment.hpp"

#include <iostream>
#include <string>
#include <deque>
#include <unistd.h>

class Player:public Creature
{
private:
   std::deque<std::string> TARDIS;
   int lifeCounter;
   Compartment* you_are_here;
   int maxStrength;
   std::string outfit;
   std::string userName;
   int itemCount;
   bool advice;
   bool watch;
   bool screwdriver;
   bool diary;
public:
   Player();
   void setStrength(int);
   void addItem(Compartment*);
   std::string removeItem();
   void setLocation(Compartment*);
   void setOutfit();
   Compartment* getLocation();
   std::string getOutfit();
   void setCreatureType(std::string);
   std::string getType();
   void setAdvice();
   bool getAdvice();
   void setScrewdriver();
   bool getScrewdriver();
   void setWatch();
   bool getWatch();
   void setDiary();
   bool getDiary();
   int getLifeCounter();
   void setItems(std::string, Compartment*);
   int attack();
};
#endif
