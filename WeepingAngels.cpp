/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	WeepingAngels.cpp 	*
 ************************************************/

#include "Creature.hpp"
#include "WeepingAngels.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
WeepingAngels::WeepingAngels()
{
   this->creatureType = "Weeping Angels";
   this->attackDieCount = 2;
   this->attackDieSides = 6;
   this->defenseDieCount = 1;
   this->defenseDieSides = 6;
   this->armor = 6;
   this->strength = 3;
}
