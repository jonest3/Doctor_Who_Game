/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	TheMaster.cpp 		*
 ************************************************/

#include "Creature.hpp"
#include "TheMaster.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
TheMaster::TheMaster()
{
   this->creatureType = "The Master";
   this->attackDieCount = 2;
   this->attackDieSides = 10;
   this->defenseDieCount = 2;
   this->defenseDieSides = 6;
   this->armor = 5;
   this->strength = 20;
}
