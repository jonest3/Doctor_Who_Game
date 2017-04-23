/************************************************
 * *Author:		Taylor Jones (jonest3)	*
 * *Date:		March 15, 2016		*
 * *Description:	VashtaNerada.cpp 	*
 ************************************************/

#include "Creature.hpp"
#include "VashtaNerada.hpp"

#include <iostream>
#include <cstdlib>
#include <string>

// Default Constructor
VashtaNerada::VashtaNerada()
{
   this->creatureType = "Vashta Nerada";
   this->attackDieCount = 2;
   this->attackDieSides = 8;
   this->defenseDieCount = 0;
   this->defenseDieSides = 0;
   this->armor = 0;
   this->strength = 0;
}
