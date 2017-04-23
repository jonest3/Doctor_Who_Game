/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	Krafayis.cpp 		*
 ************************************************/
#include "Creature.hpp"
#include "Krafayis.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
Krafayis::Krafayis()
{
   this->creatureType = "Krafayis";
   this->attackDieCount = 1;
   this->attackDieSides = 10;
   this->defenseDieCount = 1;
   this->defenseDieSides = 6;
   this->armor = 3;
   this->strength = 10;
}
